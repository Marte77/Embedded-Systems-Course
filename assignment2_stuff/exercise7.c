/*
 * main.c
 *
 *  Created on: 8 Oct 2025
 *      Author: marti
 */


/*
 * main.c
 *
 *  Created on: 8 Oct 2025
 *      Author: marti
 */

#include <stdio.h>
#include <xil_printf.h>
#include <inttypes.h>
#include "xscutimer.h"
#include "xneuralnet.h"

#define ONE_SECOND 333000000 // half of the CPU clock speed
#define SL_LEN 4								// Length of switches and leds
#define BITS 15							        // Weights shifted number of bits (*2^BIT_SHIFT)
#define INPUT_LEN 196               			// Number of inputs 28/2*28/2 MINST pixels (49)
#define NEURONS_LEN  32               			// Number of neurons (16)
#define WEIGHTS_I_LEN (INPUT_LEN*NEURONS_LEN)  	// Number of weights in input layer
#define OUTPUT_LEN 10			        		// Number of outputs 10 digits
#define WEIGHTS_O_LEN (NEURONS_LEN*OUTPUT_LEN)  // Number of weights in output layer
#define multfix(a,b) ((int)((((signed long long) a)*((signed long long) b)) >> BITS))

XNeuralnet neuralNet;
XScuTimer timer;
const int scale = (1<<BITS);
volatile u32 timeSpent = 0;
void print_time(char *text) {
	print(text);
	xil_printf("%"PRIu32" (%d ms, %d us)\r\n", timeSpent, (timeSpent*100 / ONE_SECOND), (timeSpent*1000000 / ONE_SECOND));
}
int timer_initialize(void)
{
	int Status;
	XScuTimer *TimerInstancePtr = &timer;
	XScuTimer_Config *ConfigTmrPtr;

	/* Initialize the Scu Private Timer driver. */
	ConfigTmrPtr = XScuTimer_LookupConfig(XPAR_PS7_SCUTIMER_0_DEVICE_ID);

	/* This is where the virtual address would be used, this uses physical address. */
	Status = XScuTimer_CfgInitialize(TimerInstancePtr, ConfigTmrPtr, ConfigTmrPtr->BaseAddr);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	/* Disable Auto reload mode and set prescaler to 1 */
	XScuTimer_SetPrescaler(TimerInstancePtr, 0);

	return Status;
}

int net_initialize(void) {
	/*XNeuralnet_Config *config;
	config = XNeuralnet_LookupConfig(XPAR_NEURALNET_0_DEVICE_ID);
	int status = XNeuralnet_CfgInitialize(&neuralNet, config, config->Bus_BaseAddress);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	XNeu
	return status;*/
	return XNeuralnet_Initialize(&neuralNet, XPAR_NEURALNET_0_DEVICE_ID);
}
void set_time_spent(u32 start, u32 end) {
	timeSpent = start - end;
}

void neuralNetworkSoftware(char input[INPUT_LEN], int output[OUTPUT_LEN]) {
	short weightsI[WEIGHTS_I_LEN], weightsO[WEIGHTS_O_LEN];
	int i, j;
	for (i=0; i<WEIGHTS_I_LEN; i++) {
		weightsI[i] = 0.0001*i*scale + 0.5;
	}
	for (i=0; i<WEIGHTS_O_LEN; i++) {
		weightsO[i] = 0.001*i*scale + 0.5;
	}
	int neurons[NEURONS_LEN];
	int neuron, result;
	int offsetI, offsetO;

	volatile u32 start = XScuTimer_GetCounterValue(&timer);
	// Compute input layer (hidden layer)
	for (i = 0; i < NEURONS_LEN; i++) {
		neuron = 0;
		offsetI = NEURONS_LEN * i;

		// Compute neurons using fixed-point arithmetic
		for (j = 0; j < INPUT_LEN; j++) {
			neuron += multfix((input[j]<<BITS), (weightsI[j + offsetI]));
		}

			// Store neuron value and apply ReLU activation
		neurons[i] = neuron>> BITS;
		if (neuron < 0) // ReLU activation
			neurons[i] = 0;
	}

	// Compute output layer
	for (i = 0; i < OUTPUT_LEN; i++) {
		result = 0;
		offsetO = OUTPUT_LEN * i;
		for (j = 0; j < NEURONS_LEN; j++) {
			// Fixed-point multiplication: divide by scale to maintain Q16.15 format
			result += multfix((neurons[j] << BITS), (weightsO[j + offsetO]));
		}
		output[i] = result >> BITS;
	}
	volatile u32 end = XScuTimer_GetCounterValue(&timer);
	xil_printf("SHORT start %"PRIu32" end %"PRIu32" \r\n", start, end);
	set_time_spent(start, end);
}
void neuralNetFloat(char input[INPUT_LEN], float output[OUTPUT_LEN])
{
	float weightsI[WEIGHTS_I_LEN], weightsO[WEIGHTS_O_LEN];

	int i, j;
	for (i=0; i<WEIGHTS_I_LEN; i++) {
		weightsI[i] = 0.0001*i;
	}
	for (i=0; i<WEIGHTS_O_LEN; i++) {
		weightsO[i] = 0.001*i;
	}
	float neurons[NEURONS_LEN];
	float neuron, result;
	int offsetI, offsetO;

	volatile u32 end = 0, start = XScuTimer_GetCounterValue(&timer);
	// Compute input layer
	for (i=0; i<NEURONS_LEN; i++) {
		neuron = 0;
		offsetI = NEURONS_LEN * i;
		// Compute neurons
		for (j=0; j<INPUT_LEN; j++) {
			neuron += input[j] * weightsI[j+offsetI];
		}
		//printf("%0.2f,", neuron);
		neurons[i] = neuron;
		if (neuron < 0) // ReLU
			neurons[i] = 0;
	}

	// Compute output layer
	for (i=0; i<OUTPUT_LEN; i++) {
		result = 0;
		offsetO = OUTPUT_LEN * i;
		for (j=0;  j<NEURONS_LEN; j++) {
			result += neurons[j] * weightsO[j+offsetO];
		}
		output[i] = result;
	}
	end = XScuTimer_GetCounterValue(&timer);
	xil_printf("FLOAT start %"PRIu32" end %"PRIu32"\r\n", start, end);
	set_time_spent(start, end);
}

int neuralNetworkHardware(char input[INPUT_LEN], int output[OUTPUT_LEN]) {
	short weightsI[WEIGHTS_I_LEN], weightsO[WEIGHTS_O_LEN];
	int i;
	for (i=0; i<WEIGHTS_I_LEN; i++) {
		weightsI[i] = 0.0001*i*scale + 0.5;
	}
	for (i=0; i<WEIGHTS_O_LEN; i++) {
		weightsO[i] = 0.001*i*scale + 0.5;
	}
	xil_printf("Waiting for IP Core to be ready\r\n");
	while (XNeuralnet_IsReady(&neuralNet) == 0); // Check IP core ready
	xil_printf("IP Core ready, writing to IP Core\r\n");

	// load values into the IP core
	volatile u32 end = 0;
	volatile u32 start = XScuTimer_GetCounterValue(&timer);
	XNeuralnet_Start(&neuralNet);
	XNeuralnet_Write_input_r_Words(&neuralNet, 0, (int*)input, INPUT_LEN/4);
	XNeuralnet_Write_weightsI_Words(&neuralNet, 0, (int*)weightsI, WEIGHTS_I_LEN/2);
	XNeuralnet_Write_weightsO_Words(&neuralNet, 0, (int*)weightsO, WEIGHTS_O_LEN/2);
	end = XScuTimer_GetCounterValue(&timer);
	set_time_spent(start, XScuTimer_GetCounterValue(&timer));
	print_time("Time Spent loading data into the hardware: ");
	xil_printf("Waiting for IP Core to calculate\r\n");
	start = XScuTimer_GetCounterValue(&timer);
	// wait for calculation
	while (XNeuralnet_IsDone(&neuralNet) == 0);
	end = XScuTimer_GetCounterValue(&timer);
	set_time_spent(start, end);
	print_time("Time spent calculating data: ");
	xil_printf("IP Core Done\r\n");
	//read output to the output parameter
	start = XScuTimer_GetCounterValue(&timer);
	XNeuralnet_Read_output_r_Words(&neuralNet, 0, (int *)output, OUTPUT_LEN);
	end = XScuTimer_GetCounterValue(&timer);
	set_time_spent(start,end);
	print_time("Time spent reading back data: ");
	return timeSpent;
}
enum mode {
	floating,
	shorting,
	hardware
};
int main() {
	int mode = floating;
	print("Starting program\r\nInitializing timer\r\n");
	int timerStatus = timer_initialize();
	if (timerStatus == XST_FAILURE)
		print("Failed to initialize timer!!!!!!!!!\r\n");
	switch (mode) {
		case floating:
			print("TESTING NEURAL NET WITH FLOATING POINT TYPE");
			break;
		case shorting:
			print("TESTING NEURAL NET WITH SHORT TYPE");
			break;
		case hardware:
			print("TESTING NEURAL NET WITH HARDWARE");
			break;
		}
	print("\r\n");
	print("Initializing neural net\r\n");
	int netStatus = net_initialize();
	if (netStatus == XST_FAILURE)
		print("Failed to initialize neural net!!!!!!!!!\r\n");
	int i;
	char inputs[INPUT_LEN];
	for (i=0; i<INPUT_LEN; i++) {
		inputs[i] = i%255;
	}
	print("First input successfully initialized\r\n");

	int output_Short[OUTPUT_LEN];
	float output_Float[OUTPUT_LEN];

	XScuTimer_LoadTimer(&timer, 0xFFFFFF);
	XScuTimer_Start(&timer);
	switch (mode) {
	case floating:
		neuralNetFloat(inputs, output_Float);
		print_time("Neural network with FLOAT data type done. Time for calculation ");
		break;
	case shorting:
		neuralNetworkSoftware(inputs, output_Short);
		print_time("Neural network with SHORT data type done. Time for calculation ");
		break;
	case hardware:
		neuralNetworkHardware(inputs, output_Short);
		print("Neural network with HARDWARE done.");
		break;
	}
	XScuTimer_Stop(&timer);
	print("Done.\r\n");
	return 0;
}

