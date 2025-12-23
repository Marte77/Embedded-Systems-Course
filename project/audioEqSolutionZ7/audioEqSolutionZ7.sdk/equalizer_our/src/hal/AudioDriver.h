/*
 * AudioDriver.h
 *
 *  Created on: 16. aug. 2017
 *      Author: Kim Bjerge
 */

#ifndef SRC_HAL_AUDIODRIVER_H_
#define SRC_HAL_AUDIODRIVER_H_

#include "Timer.h"
#include "xiicps.h"

class AudioDriver
{
public:
	AudioDriver() : timer(XPAR_PS7_SCUTIMER_0_DEVICE_ID) {};

	int Init(void);

	bool isNewSampleReady(void);
	void busyWaitForSamples(void);
	void inSamples(unsigned long &sLeft, unsigned long &sRight);
	void outSamples(unsigned long sLeft, unsigned long sRight);

private:
	int IicConfig(int DeviceIdPS);
	void AudioWriteToReg(unsigned char u8RegAddr, short u16Data);
	void LineinLineoutConfig();
	XIicPs mIic;
	Timer timer;
};



#endif /* SRC_HAL_AUDIODRIVER_H_ */
