/*
 * FirHLS.cpp
 *
 *  Created on: 16. aug. 2017
 *      Author: Kim Bjerge
 */

#include "FirHLS.h"


void FirHLS::filterSample(unsigned long sample)
{
	// Clear done flags
	mResultAvailHlsFir = 0;
	// send samples after shifting least significant 8 bits as the filter
	// requires 16 bit input sample
	while (XFir_IsReady(&mHlsFir) == 0); // Polling ready register
	XFir_Set_x(&mHlsFir, sample >> 8);
	XFir_Start(&mHlsFir);
}

unsigned long FirHLS::getFiltered(void)
{
	unsigned long u32Data;

	if (mpIrq != 0)	// Busy wait for fir irq
		while(!mResultAvailHlsFir);
	else
		while (XFir_IsDone(&mHlsFir) == 0); // Polling done register

	u32Data = XFir_Get_y(&mHlsFir);
	// shift left by 8 bits as output sample is 16 bit whereas CODEC requires 24 bits
    return u32Data << 8;
}

void FirHLS::Disable(void)
{
	// Disable Global and instance interrupts
    XFir_InterruptDisable(&mHlsFir, 1);
    XFir_InterruptGlobalDisable(&mHlsFir);
	// clear the local interrupt
	XFir_InterruptClear(&mHlsFir, 1);
}

void FirHLS::Enable(void)
{
	// Enable Global and instance interrupts
	mResultAvailHlsFir = 0;
    XFir_InterruptEnable(&mHlsFir,1);
    XFir_InterruptGlobalEnable(&mHlsFir);
}

void FirHLS::hls_fir_isr(void *InstancePtr)
{
	FirHLS *pHlsFir = (FirHLS *)InstancePtr;
	XFir *pAccelerator = &(pHlsFir->mHlsFir);

	// clear the local interrupt
	XFir_InterruptClear(pAccelerator, 1);

	pHlsFir->mResultAvailHlsFir = 1;
}

int FirHLS::Init(IRQ* pIrq, int mIrqDeviceId)
{
	XFir_Config *cfgPtr;
	int status;

	// Set IRQ pointer
	mpIrq = pIrq;

	cfgPtr = XFir_LookupConfig(mDeviceId);
	if (!cfgPtr) {
	  print("ERROR: Lookup of FIR configuration failed.\n\r");
	  return XST_FAILURE;
	}

	status = XFir_CfgInitialize(&mHlsFir, cfgPtr);
	if (status != XST_SUCCESS) {
	  print("ERROR: Could not initialize FIR.\n\r");
	  return XST_FAILURE;
	}

	// Disable and clear interrupts from FIR
	Disable();

	if (mpIrq != 0) { // Enable interrupt if interrupt controller specified
		// Connect the Left FIR ISR to the exception table
		status = XScuGic_Connect(mpIrq->getScuGic(), mIrqDeviceId,
								 (Xil_InterruptHandler)hls_fir_isr, this);
		if(status != XST_SUCCESS){
		   return status;
		}

		// Enable the FIR ISR
		XScuGic_Enable(mpIrq->getScuGic(), mIrqDeviceId);
	}

	return status;
}
