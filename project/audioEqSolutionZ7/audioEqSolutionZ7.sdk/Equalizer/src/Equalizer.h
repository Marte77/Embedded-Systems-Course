/*
 * Equalizer.h
 *
 *  Created on: 5. dec. 2017
 *      Author: au288681
 */

#ifndef SRC_EQUALIZER_H_
#define SRC_EQUALIZER_H_

#include "IIR.h"
#include "EqHLS.h"

#define NUM_BANDS 	7
#define SAMPLE_FS	48000

class Equalizer {

public:
	Equalizer(int LeftDevId, int RightDevId) : leftEqHLS(LeftDevId), rightEqHLS(RightDevId) {};

	int Init();

	void filterSamples(unsigned long sLeft, unsigned long sRight);
	void getFiltered(unsigned long &sLeft, unsigned long &sRight);

private:
	void initEq(IIR *pIIR, EqHLS *pEqHLS); // Initialize left/right channel

	IIR leftIIR[NUM_BANDS];
	IIR rightIIR[NUM_BANDS];
	EqHLS leftEqHLS; // Left HLS IP Core 7 bands EQ
	EqHLS rightEqHLS;// Right HLS IP Core 7 bands EQ
};

#endif /* SRC_EQUALIZER_H_ */
