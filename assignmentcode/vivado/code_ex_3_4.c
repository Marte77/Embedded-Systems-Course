#include "xparameters.h"
#include "xgpio.h"
#include <inttypes.h>
#include "led_ip.h"
#include "XScuTimer.h"
#define ONE_SECOND 325000000
//====================================================

int mainFromLab4Original (void)
{

   XGpio dip, push;
   int i, psb_check, dip_check;
	
   xil_printf("-- Start of the Program --\r\n");
 
   XGpio_Initialize(&dip, XPAR_SWITCHES_SWAG_DEVICE_ID); // Modify this
   XGpio_SetDataDirection(&dip, 1, XPAR_SWITCHES_SWAG_BASEADDR);

   XGpio_Initialize(&push, XPAR_BUTTONS_DEVICE_ID); // Modify this
   XGpio_SetDataDirection(&push, 1, XPAR_BUTTONS_BASEADDR);
	

   while (1)
   {
	  psb_check = XGpio_DiscreteRead(&push, 1);
	  xil_printf("Push Buttons Status %x\r\n", psb_check);
	  dip_check = XGpio_DiscreteRead(&dip, 1); // all of the switches' values are "added", and so since they are 4, they output a value between 0 and 2^4-1 (F in HEX)
	  xil_printf("DIP Switch Status %x\r\n", dip_check);
	  
	  // output dip switches value on LED_ip device
	  LED_IP_mWriteReg(XPAR_LED_IP_S_AXI_BASEADDR, 0, dip_check);

	  
	  for (i=0; i<9999999; i++); // delay
   }
}

#define MATRIX_SIZE 4

typedef union {
	unsigned char comp[MATRIX_SIZE];
	unsigned int vect;
} vectorType;
typedef vectorType VectorArray[MATRIX_SIZE];

void setInputMatrices(VectorArray A, VectorArray B);
void displayMatrix(VectorArray m);
void multiMatrixSoft(VectorArray A, VectorArray B, VectorArray P);
void multiMatrixHard(VectorArray A, VectorArray B, VectorArray P);

VectorArray pInst, aInst, bTInst;

int main(void) {
	setInputMatrices(aInst, bTInst);
	XGpio switches, push;
	XGpio_Initialize(&switches, XPAR_SWITCHES_SWAG_DEVICE_ID); // Modify this
	XGpio_SetDataDirection(&switches, 1, XPAR_SWITCHES_SWAG_BASEADDR);

	XGpio_Initialize(&push, XPAR_BUTTONS_DEVICE_ID); // Modify this
	XGpio_SetDataDirection(&push, 1, XPAR_BUTTONS_BASEADDR);
	char value_read = -1;
	XScuTimer timer;

	// PS Timer related definitions and initalize timer
	XScuTimer_Config *ConfigPtr;
	XScuTimer *TimerInstancePtr = &timer;
	ConfigPtr = XScuTimer_LookupConfig (XPAR_PS7_SCUTIMER_0_DEVICE_ID);
	int Status_timer = XScuTimer_CfgInitialize (TimerInstancePtr, ConfigPtr, ConfigPtr->BaseAddr);
	if (Status_timer != XST_SUCCESS) {
		xil_printf("Timer init() failed\r\n");
		return XST_FAILURE;
	}
	int switches_input;
	while (1) {
		xil_printf("\r\n1 - SWLeds 2 - Timer Leds 3 - Matrix\r\nInsert command (press C to go back when inside command):");
		value_read = inbyte();
		xil_printf("%c\r\n", value_read);
		switch (value_read) {
		case '1':
			xil_printf("\r\nPress any key other than C to update the values and print to console (press C to go back when inside command):");
			while (value_read != 'c' && value_read != 'C') {
				switches_input = XGpio_DiscreteRead(&switches, 1);
				xil_printf("\r\nSwitches input: %d", switches_input);
				// output dip switches value on LED_ip device
				LED_IP_mWriteReg(XPAR_LED_IP_S_AXI_BASEADDR, 0, switches_input);
				value_read = inbyte();
			}
			break;
		case '2': {

			// Load timer with delay in multiple of ONE_SECOND
			XScuTimer_LoadTimer(TimerInstancePtr, ONE_SECOND);
			// Set AutoLoad mode
			XScuTimer_EnableAutoReload(TimerInstancePtr);
			int counter = 0;
			XScuTimer_Start(TimerInstancePtr);
			while (value_read != 'c' && value_read != 'C') {
				// Check timer expired
				if(XScuTimer_IsExpired(TimerInstancePtr)) {
					// clear status bit
					XScuTimer_ClearInterruptStatus(TimerInstancePtr);
					counter++;
					if (counter == 16) counter = 0;
					LED_IP_mWriteReg(XPAR_LED_IP_S_AXI_BASEADDR, 0, counter);
					xil_printf("\r\nCounter increased to: %d", counter);
				}
			}
			// Stop the timer
			XScuTimer_Stop(TimerInstancePtr);
			// Set AutoLoad mode
			XScuTimer_DisableAutoReload(TimerInstancePtr);
			XScuTimer_RestartTimer(TimerInstancePtr);
			break;
		}
		case '3':
			xil_printf("\r\nMatrix A:");
			displayMatrix(aInst);
			xil_printf("\r\nMatrix B:");
			displayMatrix(bTInst);
      //start timer to count time of execution
			XScuTimer_Start(TimerInstancePtr);
			multiMatrixSoft(aInst, bTInst, pInst);
			u32 counter = XScuTimer_GetCounterValue(TimerInstancePtr);
			xil_printf("\r\nTicks spent: %"PRIu32" (in milliseconds: %d)", counter, (counter*100 / ONE_SECOND));
			xil_printf("\r\nMatrix P (A * B result):");
			displayMatrix(pInst);
			// Stop the timer
			XScuTimer_Stop(TimerInstancePtr);
			// Set AutoLoad mode
			XScuTimer_DisableAutoReload(TimerInstancePtr);
			XScuTimer_RestartTimer(TimerInstancePtr);
			break;
		default:
			xil_printf("\r\nOption not available");
		}
		LED_IP_mWriteReg(XPAR_LED_IP_S_AXI_BASEADDR, 0, 0);
	}

}


void displayMatrix(VectorArray m) {
	xil_printf("\r\n");
	for (int i = 0; i < MATRIX_SIZE; i++) {
		xil_printf("\r\n|");
		for (int j = 0; j < MATRIX_SIZE; j++) {
			xil_printf("%d ", m[i].comp[j]);
		}
		xil_printf("|");
	}
	xil_printf("\r\n");
}


void multiMatrixSoft(VectorArray A, VectorArray B, VectorArray P) {
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			for (int k = 0; k < MATRIX_SIZE; k++)
				P[i].comp[j] += A[i].comp[k] * B[k].comp[j];

		}
	}
}

void setInputMatrices(VectorArray A, VectorArray B) {
	A[0].comp[0] = 1;
	A[0].comp[1] = 2;
	A[0].comp[2] = 3;
	A[0].comp[3] = 4;
	A[1].comp[0] = 5;
	A[1].comp[1] = 6;
	A[1].comp[2] = 7;
	A[1].comp[3] = 8;
	A[2].comp[0] = 9;
	A[2].comp[1] = 10;
	A[2].comp[2] = 11;
	A[2].comp[3] = 12;
	A[3].comp[0] = 13;
	A[3].comp[1] = 14;
	A[3].comp[2] = 15;
	A[3].comp[3] = 16;
	B[0].comp[0] = 1;
	B[0].comp[1] = 1;
	B[0].comp[2] = 1;
	B[0].comp[3] = 1;
	B[1].comp[0] = 2;
	B[1].comp[1] = 2;
	B[1].comp[2] = 2;
	B[1].comp[3] = 2;
	B[2].comp[0] = 3;
	B[2].comp[1] = 3;
	B[2].comp[2] = 3;
	B[2].comp[3] = 3;
	B[3].comp[0] = 4;
	B[3].comp[1] = 4;
	B[3].comp[2] = 4;
	B[3].comp[3] = 4;
}
