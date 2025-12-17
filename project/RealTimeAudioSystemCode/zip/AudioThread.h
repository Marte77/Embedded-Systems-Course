/*
 * ConsumerThread.h
 *
 *  Created on: 8. aug. 2017
 *      Author: Kim Bjerge
 */

#pragma once

#include "Thread.h"
#include "AudioDriver.h"
#include "FirHLS.h"
#include "UserParameters.h"

using namespace AbstractOS;

class AudioThread : public Thread
{
public:

	AudioThread(ThreadPriority pri, string name, UserParameters *pUP,
			    AudioDriver *pA, FirHLS *pL, FirHLS *pR) :
		 Thread(pri, name)
	 {
		 pParameters = pUP;
		 pAudio = pA;
		 pFirLeft = pL;
		 pFirRight = pR;
	 }

	void bypassAudio(void)
	{
		unsigned long sampleLeft, sampleRight;

		while (!pAudio->isNewSampleReady()) yield();
		pAudio->inSamples(sampleLeft, sampleRight);
		pAudio->outSamples(sampleLeft, sampleRight);
	}

	void filterAudio(void)
	{
		unsigned long sampleLeft, sampleRight;

		while (!pAudio->isNewSampleReady()) yield();
		pAudio->inSamples(sampleLeft, sampleRight);

		// Sending audio samples to HLS Fir IP Core
		pFirLeft->filterSample(sampleLeft);
		pFirRight->filterSample(sampleRight);
		sampleLeft = pFirLeft->getFiltered();
		sampleRight = pFirRight->getFiltered();

		pAudio->outSamples(sampleLeft, sampleRight);
	}

	virtual void run()
	{

		while (1) {
			// Process stereo samples forever
			if (!pParameters->isMuted()) {
				if (pParameters->isBypass())
					bypassAudio();
				else
					filterAudio();
			}
			yield();
		}
	}

private:
	UserParameters *pParameters;
	AudioDriver *pAudio;
	FirHLS *pFirLeft;
	FirHLS *pFirRight;
};


