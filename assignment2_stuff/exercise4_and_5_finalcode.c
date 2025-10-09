#include "xparameters.h"
#include "xgpio.h"
#include <inttypes.h>
#include "led_ip.h"
#include "matrix_ip.h"
#include "XScuTimer.h"
#define ONE_SECOND 325000000
//====================================================
#define MATRIX_SIZE 4

typedef union {
	unsigned char comp[MATRIX_SIZE];
	unsigned int vect;
} vectorType;
typedef vectorType VectorArray[MATRIX_SIZE];

void setInputMatrices(VectorArray A, VectorArray B, VectorArray P);
void displayMatrix(VectorArray m);
void multiMatrixSoft(VectorArray A, VectorArray B, VectorArray P);
void multiMatrixHard(VectorArray A, VectorArray B, VectorArray P);

VectorArray pInst, aInst, bTInst;

void runMatrixMultComparisons(int useSoft,VectorArray aInst, VectorArray bTInst, VectorArray pInst, XScuTimer* TimerInstancePtr) {
	setInputMatrices(aInst, bTInst, pInst);
	u32 counter = 0, start;
	if (useSoft == 0) {
		XScuTimer_Start(TimerInstancePtr);
		start = XScuTimer_GetCounterValue(TimerInstancePtr);
		multiMatrixHard(aInst, bTInst, pInst);
	}
	else {
		XScuTimer_Start(TimerInstancePtr);
		start = XScuTimer_GetCounterValue(TimerInstancePtr);
		multiMatrixSoft(aInst, bTInst, pInst);
	}
	counter = XScuTimer_GetCounterValue(TimerInstancePtr);
	xil_printf("\r\nTicks spent: %lu (%d ms, %d us)", (start - counter),
			((start - counter) * 100 / ONE_SECOND), ((start - counter) * 1000000 / ONE_SECOND));
	xil_printf("\r\nMatrix P (A * B result):");
	displayMatrix(pInst);
	// Stop the timer
	XScuTimer_Stop(TimerInstancePtr);
	// Set AutoLoad mode
	XScuTimer_DisableAutoReload(TimerInstancePtr);
	XScuTimer_RestartTimer(TimerInstancePtr);
}

int main(void) {
	setInputMatrices(aInst, bTInst, pInst);
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
	// Load timer with delay in multiple of ONE_SECOND
	XScuTimer_LoadTimer(TimerInstancePtr, ONE_SECOND);

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
			// Set AutoLoad mode
			XScuTimer_EnableAutoReload(TimerInstancePtr);
			int counter = 0, i = 0;
			XScuTimer_Start(TimerInstancePtr);
			while (i != 3) {
				// Check timer expired
				if(XScuTimer_IsExpired(TimerInstancePtr)) {
					// clear status bit
					XScuTimer_ClearInterruptStatus(TimerInstancePtr);
					counter++;
					if (counter == 16) {
						counter = 0;
						i++;
					}
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
			xil_printf("\r\nMatrix P:");
			displayMatrix(pInst);
			xil_printf("\r\nSoftware Matrix Mult:");
			runMatrixMultComparisons(1, aInst, bTInst, pInst, TimerInstancePtr);
			xil_printf("\r\nHardware Matrix Mult:");
			runMatrixMultComparisons(0, aInst, bTInst, pInst, TimerInstancePtr);
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


void multiMatrixHard(VectorArray A, VectorArray B, VectorArray P) {
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			Xil_Out32(XPAR_MATRIX_IP_0_S00_AXI_BASEADDR + MATRIX_IP_S00_AXI_SLV_REG0_OFFSET, A[i].vect);
			Xil_Out32(XPAR_MATRIX_IP_0_S00_AXI_BASEADDR + MATRIX_IP_S00_AXI_SLV_REG1_OFFSET, B[j].vect);
			P[i].comp[j] = Xil_In32(XPAR_MATRIX_IP_0_S00_AXI_BASEADDR + MATRIX_IP_S00_AXI_SLV_REG2_OFFSET);
		}
	}
}

void multiMatrixSoft(VectorArray A, VectorArray B, VectorArray P) {
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			P[i].comp[j] = 0;
			for (int k = 0; k < MATRIX_SIZE; k++)
				P[i].comp[j] += A[i].comp[k] * B[j].comp[k];
		}
	}
}

void setInputMatrices(VectorArray A, VectorArray B, VectorArray P) {
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
	P[0].comp[0] = 0;
	P[0].comp[1] = 0;
	P[0].comp[2] = 0;
	P[0].comp[3] = 0;
	P[1].comp[0] = 0;
	P[1].comp[1] = 0;
	P[1].comp[2] = 0;
	P[1].comp[3] = 0;
	P[2].comp[0] = 0;
	P[2].comp[1] = 0;
	P[2].comp[2] = 0;
	P[2].comp[3] = 0;
	P[3].comp[0] = 0;
	P[3].comp[1] = 0;
	P[3].comp[2] = 0;
	P[3].comp[3] = 0;
}
