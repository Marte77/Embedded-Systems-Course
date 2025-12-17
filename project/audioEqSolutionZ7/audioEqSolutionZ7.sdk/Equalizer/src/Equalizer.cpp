/*
 * Equalizer.cpp
 *
 *  Created on: 5. dec. 2017
 *      Author: au288681
 */

#include "Equalizer.h"


// Initialization of left or right channels
void Equalizer::initEq(IIR *pIIR, EqHLS *pEqHLS)
{
	int band = 0;

	pIIR[band].makePeakEQ(SAMPLE_FS, 200, 10, 1.8); // Cut frequency 0.2 kHz
    pEqHLS->setCoeff(pIIR[band].getCoeffPtr(), band);

    band++;
    pIIR[band].makePeakEQ(SAMPLE_FS, 500, 10, 0.1); // Cut frequency 0.5 kHz
    pEqHLS->setCoeff(pIIR[band].getCoeffPtr(), band);

    band++;
    pIIR[band].makePeakEQ(SAMPLE_FS, 1000, 10, 0.1); // Cut frequency 1 kHz
    pEqHLS->setCoeff(pIIR[band].getCoeffPtr(), band);

    band++;
    pIIR[band].makePeakEQ(SAMPLE_FS, 2000, 10, 1.8); // Cut frequency 2 kHz
    pEqHLS->setCoeff(pIIR[band].getCoeffPtr(), band);

    band++;
    pIIR[band].makePeakEQ(SAMPLE_FS, 4000, 10, 0.1); // Cut frequency 4 kHz
    pEqHLS->setCoeff(pIIR[band].getCoeffPtr(), band);

    band++;
    pIIR[band].makePeakEQ(SAMPLE_FS, 8000, 10, 0.1); // Cut frequency 8 kHz
    pEqHLS->setCoeff(pIIR[band].getCoeffPtr(), band);

    band++;
    pIIR[band].makePeakEQ(SAMPLE_FS, 16000, 10, 1.8); // Cut frequency 16 kHz
    pEqHLS->setCoeff(pIIR[band].getCoeffPtr(), band);

}

int Equalizer::Init()
{
	int status = leftEqHLS.Init();
	if (status == XST_SUCCESS) {
		initEq(leftIIR, &leftEqHLS);
	}
	status = rightEqHLS.Init();
	if (status == XST_SUCCESS) {
		initEq(rightIIR, &rightEqHLS);
	}
	return status;
}

void Equalizer::filterSamples(unsigned long sLeft, unsigned long sRight)
{
	leftEqHLS.filterSample(sLeft);
	rightEqHLS.filterSample(sRight);
}

void Equalizer::getFiltered(unsigned long &sLeft, unsigned long &sRight)
{
	sLeft = leftEqHLS.getFiltered();
	sRight = rightEqHLS.getFiltered();
}
