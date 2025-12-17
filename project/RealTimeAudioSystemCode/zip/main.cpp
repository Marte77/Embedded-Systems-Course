/*
 * Empty C++ Application
 */

#include "IRQ.h"
/*
 * main.cpp
 *
 *  Created on: 18. aug. 2017
 *      Author: Kim Bjerge
 */
#include "AudioThread.h"
#include "UserControlThread.h"

// Allocation of objects in DDR memory
AudioDriver audioDriver;
IRQ irq(XPAR_SCUGIC_0_DEVICE_ID);
FirHLS leftFir(XPAR_FIR_LEFT_DEVICE_ID);
FirHLS rightFir(XPAR_FIR_RIGHT_DEVICE_ID);

int main()
{
	// Initialization of hardware abstraction layer
	if (audioDriver.Init() != XST_SUCCESS) return -1;
	if (leftFir.Init() != XST_SUCCESS) return -1;
	if (rightFir.Init()!= XST_SUCCESS) return -1;

	UserParameters userParameters;

	AudioThread mAudioThread(Thread::PRIORITY_LOW,
							"AudioThread",
							&userParameters,
							&audioDriver,
							&leftFir,
							&rightFir);

	UserControlThread mUserControlThread(Thread::PRIORITY_NORMAL,
										"UserControlThread",
										&userParameters);

	/* Start FreeRTOS, the tasks running. */
	vTaskStartScheduler();

	/* If all is well, the scheduler will now be running, and the following line
	will never be reached.  If the following line does execute, then there was
	insufficient FreeRTOS heap memory available for the idle and/or timer tasks
	to be created.  See the memory management section on the FreeRTOS web site
	for more details. */
	for( ;; );
}

//-------------------------------------------------------------------------------------------------------
// For testing, without freertos, with and without IRQ
//-------------------------------------------------------------------------------------------------------
/*
void testFilterAudio(void)
{
	unsigned long sampleLeft, sampleRight;

	while (1) {
		audioDriver.busyWaitForSamples();
		audioDriver.inSamples(sampleLeft, sampleRight);

		leftFir.filterSample(sampleLeft);
		rightFir.filterSample(sampleRight);
		sampleLeft = leftFir.getFiltered();
		sampleRight = rightFir.getFiltered();

		audioDriver.outSamples(sampleLeft, sampleRight);
	}
}

int main()
{
	if (audioDriver.Init() != XST_SUCCESS) return -1;

#if 1
    // HLS Fir Without interrupt
	if (leftFir.Init() != XST_SUCCESS) return -1;
	if (rightFir.Init()!= XST_SUCCESS) return -1;
#else
	// HLS Fir Using interrupts
	if (irq.Init() != XST_SUCCESS) return -1;

	if (leftFir.Init(&irq, XPAR_FABRIC_FIR_LEFT_INTERRUPT_INTR) != XST_SUCCESS) return -1;
	if (rightFir.Init(&irq, XPAR_FABRIC_FIR_RIGHT_INTERRUPT_INTR)!= XST_SUCCESS) return -1;

	leftFir.Enable();
	rightFir.Enable();
#endif

	unsigned long sample = 2341;
	leftFir.filterSample(sample);
	rightFir.filterSample(sample);
	testFilterAudio();
}
*/
