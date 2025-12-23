/*
 * Equalizer.cpp
 *
 *  Created on: 5. dec. 2017
 *      Author: au288681
 */

#include "Equalizer.h"

#include <math.h>
#define PI 3.141592
void calculateCoefficientForNewGain(int freq, int gain, float coeffs[6]) {
        // Formulas from the Audio EQ Cookbook https://webaudio.github.io/Audio-EQ-Cookbook/Audio-EQ-Cookbook.txt
    	//MutexGuard guard(&mMutex); // using this mutex guard, we dont have to release the semaphore when the function ends, since its called in the MutexGuard deconstructor
		int Fs = 44100;
	    float Q= 10;
		float w0,alpha,a0,a1,a2,b1,b0,b2,A ;
        A  = sqrt( 10^(gain/20) );
        w0 = 2*PI*freq/Fs;
        alpha = sin(w0)/(2*Q);

        b0 =   1 + alpha*A;
        b1 =  -2*cos(w0);
        b2 =   1 - alpha*A;
        a0 =   1 + alpha/A;
        a1 =  -2*cos(w0);
        a2 =   1 - alpha/A;
        int pos = 0;
        switch (freq) {
            case 60:
                pos = 0;
                break;
            case 230:
                pos = 1;
                break;
            case 910:
                pos = 2;
                break;
            case 4000:
                pos = 3;
                break;
            case 14000:
                pos = 4;
                break;
        };
        // this doesnt print the floats, but if you debug it, everything is fine
        xil_printf("%d Hz coeffs (b0,b1,b2,a0,a1,a2):[%f %f %f %f %f %f]\r\n",b0,b1,b2,a0,a1,a2);
        coeffs[0] = b0;
        coeffs[1] = b1;
        coeffs[2] = b2;
        coeffs[3] = a0;
        coeffs[4] = a1;
        coeffs[5] = a2;
    }

// Initialization of left or right channels
void Equalizer::initEq(IIR *pIIR, EqHLS *pEqHLS)
{
	int band = 0;
	float coeffs[5][6];
	pIIR[band].makePeakEQ(SAMPLE_FS, 60, 10, 1.8); // Cut frequency 0.2 kHz
    pEqHLS->setCoeff(pIIR[band].getCoeffPtr(), band);
    calculateCoefficientForNewGain(60, 0,coeffs[band]);

    band++;
    pIIR[band].makePeakEQ(SAMPLE_FS, 230, 10, 0.1); // Cut frequency 0.5 kHz
    pEqHLS->setCoeff(pIIR[band].getCoeffPtr(), band);
    calculateCoefficientForNewGain(230, 0,coeffs[band]);

    band++;
    pIIR[band].makePeakEQ(SAMPLE_FS, 910, 10, 0.1); // Cut frequency 1 kHz
    pEqHLS->setCoeff(pIIR[band].getCoeffPtr(), band);
    calculateCoefficientForNewGain(910, 0,coeffs[band]);

    band++;
    pIIR[band].makePeakEQ(SAMPLE_FS, 4000, 10, 1.8); // Cut frequency 2 kHz
    pEqHLS->setCoeff(pIIR[band].getCoeffPtr(), band);
    calculateCoefficientForNewGain(4000, 0,coeffs[band]);

    band++;
    pIIR[band].makePeakEQ(SAMPLE_FS, 14000, 10, 0.1); // Cut frequency 4 kHz
    pEqHLS->setCoeff(pIIR[band].getCoeffPtr(), band);
    calculateCoefficientForNewGain(14000, 0,coeffs[band]);

    //pEqHLS->setCoeffsMarte(coeffs);
    while (XEqualizer_IsReady(&(pEqHLS->mHlsEq)) == 0); // Polling ready register

    XEqualizer_Set_mode(&(pEqHLS->mHlsEq), 2);
    XEqualizer_Write_coeffs_Words(&(pEqHLS->mHlsEq), 0, (int*)coeffs, sizeof(float)*5*6);
    XEqualizer_Start(&(pEqHLS->mHlsEq));;

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
