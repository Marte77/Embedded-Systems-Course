/*
 * FirHLS.h
 *
 *  Created on: 16. aug. 2017
 *      Author: Kim Bjerge
 */

#ifndef SRC_HAL_FIRHLS_H_
#define SRC_HAL_FIRHLS_H_

//#include "xfir.h"
#include "IRQ.h"

class FirHLS
{
public:
	FirHLS(int deviceId) : mDeviceId(deviceId), mResultAvailHlsFir(0) {}

	int Init(IRQ* pIrq = 0, int mIrqDeviceId = 0);

	void Disable(void);
	void Enable(void);

	void filterSample(unsigned long sample);
	unsigned long getFiltered(void);

private:
	static void hls_fir_isr(void *InstancePtr);

	int mDeviceId;
	volatile int mResultAvailHlsFir;

	// HLS FIR HW instance
	//XFir mHlsFir;
	IRQ  *mpIrq;
};



#endif /* SRC_HAL_FIRHLS_H_ */
