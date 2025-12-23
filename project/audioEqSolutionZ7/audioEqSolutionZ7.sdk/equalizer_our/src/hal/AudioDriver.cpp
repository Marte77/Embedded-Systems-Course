/*
 * AudioDriver.cpp
 *
 *  Created on: 16. aug. 2017
 *      Author: Kim Bjerge
 */
#include <xparameters.h>
#include "AudioDriver.h"

//Base addresses
#define AUDIO_BASE				XPAR_ZYBO_AUDIO_CTRL_0_BASEADDR

//Slave address for the ADAU audio controller
#define IIC_SLAVE_ADDR			0x1A

//I2C Serial Clock frequency in Hertz
#define IIC_SCLK_RATE			100000

//ADAU internal registers
enum audio_regs {
	R0_LEFT_ADC_INPUT								= 0x00,
	R1_RIGHT_ADC_INPUT								= 0x01,
	R2_LEFT_DAC_VOLUME					 			= 0x02,
	R3_RIGHT_DAC_VOLUME								= 0x03,
	R4_ANALOG_AUDIO_PATH							= 0x04,
	R5_DIGITAL_AUDIO_PATH							= 0x05,
	R6_POWER_MANAGEMENT								= 0x06,
	R7_DIGITAL_AUDIO_INTERFACE						= 0x07,
	R8_SAMPLING_RATE								= 0x08,
	R9_ACTIVE										= 0x09,
	R15_SOFTWARE_RESET								= 0x0F,
	R16_ALC_CONTROL_1								= 0x10,
	R17_ALC_CONTROL_2								= 0x11,
	R18_NOISE_GATE									= 0x12
};

//Audio controller registers
enum i2s_regs {
	I2S_DATA_RX_L_REG				= 0x00 + AUDIO_BASE,
	I2S_DATA_RX_R_REG				= 0x04 + AUDIO_BASE,
	I2S_DATA_TX_L_REG      			= 0x08 + AUDIO_BASE,
	I2S_DATA_TX_R_REG         		= 0x0c + AUDIO_BASE,
	I2S_STATUS_REG          		= 0x10 + AUDIO_BASE,
};

bool AudioDriver::isNewSampleReady(void)
{
	if (Xil_In32(I2S_STATUS_REG) == 0)
		return false;
	else {
		Xil_Out32(I2S_STATUS_REG, 0x00000001); //Clear data rdy bit
		return true;
	}
}

void AudioDriver::busyWaitForSamples(void)
{
	unsigned long u32Temp;

	do //busy wait for RX data to become available
	{
		u32Temp = Xil_In32(I2S_STATUS_REG);
	} while ( u32Temp == 0);

	Xil_Out32(I2S_STATUS_REG, 0x00000001); //Clear data rdy bit
}

void AudioDriver::inSamples(unsigned long &sLeft, unsigned long &sRight)
{
	sLeft = Xil_In32(I2S_DATA_RX_L_REG);
	sRight = Xil_In32(I2S_DATA_RX_R_REG);
}

void AudioDriver::outSamples(unsigned long sLeft, unsigned long sRight)
{
	Xil_Out32(I2S_DATA_TX_L_REG, sLeft);
	Xil_Out32(I2S_DATA_TX_R_REG, sRight);
}

int AudioDriver::Init(void)
{
	int Status;

	//Configure the IIC data structure
	Status = IicConfig(XPAR_XIICPS_0_DEVICE_ID);
	if(Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	// Initialize PS7 timer
	Status = timer.Init();
	if(Status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	//Configure the Line in and Line out ports.
	LineinLineoutConfig();

	//xil_printf("ADAU1761 configured\n\r");
	Xil_Out32(XPAR_AXI_GPIO_0_BASEADDR, 0b1);
	Xil_Out32(XPAR_AXI_GPIO_0_BASEADDR + 0x4, 0b0);

	return Status;
}

int AudioDriver::IicConfig(int DeviceIdPS)
{

	XIicPs_Config *Config;
	int Status;

	//Initialize the IIC driver so that it's ready to use
	//Look up the configuration in the config table, then initialize it.
	Config = XIicPs_LookupConfig(DeviceIdPS);
	if(NULL == Config) {
		return XST_FAILURE;
	}

	Status = XIicPs_CfgInitialize(&mIic, Config, Config->BaseAddress);
	if(Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	//Set the IIC serial clock rate.
	XIicPs_SetSClk(&mIic, IIC_SCLK_RATE);

	return XST_SUCCESS;
}

/******************************************************************************
 * Function to write 9-bits to one of the registers from the audio
 * controller.
 * @param	u8RegAddr is the register address.
 * @param	u16Data is the data word to write ( only least significant 9 bits).
  * @return	none.
 *****************************************************************************/
void AudioDriver::AudioWriteToReg(unsigned char u8RegAddr, short u16Data) {

	unsigned char u8TxData[2];

	u8TxData[0] = (u8RegAddr << 1 ) | ((u16Data >> 8) & 0x01); // append msb of 9-bit data to the reg addr after shifting left
	u8TxData[1] = u16Data & 0xFF;

	XIicPs_MasterSendPolled(&mIic, u8TxData, 2, IIC_SLAVE_ADDR);
	while(XIicPs_BusIsBusy(&mIic));
}

/******************************************************************************
 * Configures Line-In input, ADC's, DAC's, Line-Out and HP-Out.
 * @param   none.
 * @return	none.
 *****************************************************************************/
void AudioDriver::LineinLineoutConfig()
{
	// software reset
	AudioWriteToReg(R15_SOFTWARE_RESET, 0x000);
	timer.Delay(75000);
	// power mgmt: 0_00110010=>0,Power up, power up, OSC dn, out off, DAC up, ADC up, MIC off, LineIn up
	AudioWriteToReg(R6_POWER_MANAGEMENT, 0x030);
	// left ADC Input: 0_01010111=>0,mute disable, Line volume 0 dB
	AudioWriteToReg(R0_LEFT_ADC_INPUT,0x017);
	// right ADC Input: 0_00010111=>0,mute disable, Line volume 0 dB
	AudioWriteToReg(R1_RIGHT_ADC_INPUT,0x017);
	AudioWriteToReg(R2_LEFT_DAC_VOLUME,0x079);
	AudioWriteToReg(R3_RIGHT_DAC_VOLUME,0x079);
	// analog audio path: 0_00010010=>0,-6 dB side attenuation, sidetone off, DAC selected, bypass disabled, line input, mic mute disabled, 0 dB mic
	AudioWriteToReg(R4_ANALOG_AUDIO_PATH, 0x012);
	// digital audio path: 0_00000000=>0_000, clear offset, no mute, no de-emphasize, adc high-pass filter enabled
	AudioWriteToReg(R5_DIGITAL_AUDIO_PATH, 0x000);
	// digital audio interface: 0_00001110=>0, BCLK not inverted, slave mode, no l-r swap, normal LRC and PBRC, 24-bit, I2S mode
	AudioWriteToReg(R7_DIGITAL_AUDIO_INTERFACE, 0x00A);
	timer.Delay(75000);
	// Digital core:0_00000001=>0_0000000, activate core
	AudioWriteToReg(R9_ACTIVE, 0x001);
	// power mgmt: 0_00100010 0_Power up, power up, OSC dn, out ON, DAC up, ADC up, MIC off, LineIn up
	AudioWriteToReg(R6_POWER_MANAGEMENT, 0x022); // power mgmt: 001100010 turn on OUT
}
