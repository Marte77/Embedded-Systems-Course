/*
 * EQSettings.h
 *
 *  Created on: 15 Dec 2025
 *      Author: marti
 */

#ifndef SRC_EQSETTINGS_H_
#define SRC_EQSETTINGS_H_

#include <map>
#include <cmath>
#include <string>
#include <array>
#include "xequalizer.h"

#include "MutexGuardOur.h"
#define PI 3.141592
class EQSettings {
    std::map<int, int> freqMapToGain{{60,0},{230,0},{910,0},{4000,0},{14000,0}}; // values that are on the equalizer in the youtube music app on my phone
    std::map<int, int> freqMapToGainUserSetting{{60,0},{230,0},{910,0},{4000,0},{14000,0}}; // values that are on the equalizer in the youtube music app on my phone
    std::string frequenciesToString;
    /*float coeffs[5][6] = {
        {0,0,0,0,0,0}, // one for each freq   
        {0,0,0,0,0,0}, // one for each freq   
        {0,0,0,0,0,0}, // one for each freq   
        {0,0,0,0,0,0}, // one for each freq   
        {0,0,0,0,0,0}  // one for each freq  
    };*/
    std::array<std::array<float,6>,5> coeffs;
	MutexOur mMutex;
    bool wasGainUpdatedV = true;
    bool eqEnabled = true;
    const int Fs = 44100;
    const float Q= 1.5;
    void calculateCoefficientForNewGain(int freq, int gain) {
        // Formulas from the Audio EQ Cookbook https://webaudio.github.io/Audio-EQ-Cookbook/Audio-EQ-Cookbook.txt
    	//MutexGuard guard(&mMutex); // using this mutex guard, we dont have to release the semaphore when the function ends, since its called in the MutexGuard deconstructor
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
        coeffs[pos][0] = b0;
        coeffs[pos][1] = b1;
        coeffs[pos][2] = b2;
        coeffs[pos][3] = a0;
        coeffs[pos][4] = a1;
        coeffs[pos][5] = a2;
    }

public:
    void frequenciesAsString() {
        int i = 1;
        for (std::map<int,int>::const_iterator it = freqMapToGainUserSetting.begin(); it != freqMapToGainUserSetting.end(); ++it)
        {
            int freq = it->first, gain = it->second;
            xil_printf("\t%d - %d Hz\r\n", freq, gain);
            i++;
        }
    }
    EQSettings() {
        frequenciesToString=""; 
        mMutex = MutexOur("MutexEQSettings");
        for (std::map<int,int>::const_iterator it = freqMapToGainUserSetting.begin(); it != freqMapToGainUserSetting.end(); ++it)
        {
            int freq = it->first, gain = it->second;
            calculateCoefficientForNewGain(freq, gain);
        }
        setGainUpdated(true);
    }
    void setGain(int gain, int freq) {
        //MutexGuard guard(&mMutex);
        if (gain > 6) gain = 6;
        if (gain < -6) gain = -6;
        freqMapToGainUserSetting[freq] = gain;
        calculateCoefficientForNewGain(freq, gain);
        setGainUpdated(true);
        if (eqEnabled) {
            freqMapToGain[freq] = gain;
        }
    }
    void enableEQ() {
        //MutexGuard guard(&mMutex);
        eqEnabled = true;
        for (std::map<int,int>::const_iterator it = freqMapToGainUserSetting.begin(); it != freqMapToGainUserSetting.end(); ++it)
        {
        	int freq = it->first, gain = it->second;
        	freqMapToGain[freq] = gain;
        	calculateCoefficientForNewGain(freq, gain);
        }
    }

    void disableEQ() {
        //MutexGuard guard(&mMutex);
        eqEnabled = false;
    }

    bool eqState() {
        //MutexGuard guard(&mMutex);
        return eqEnabled;
    }
    
    int getGain(int freq) {
        //MutexGuard guard(&mMutex);
        return freqMapToGain[freq];
    }
    bool wasGainUpdated() {
        //MutexGuard guard(&mMutex);
        return wasGainUpdatedV;
    }
    void setGainUpdated(bool val) {
        //MutexGuard guard(&mMutex);
        wasGainUpdatedV = val;
    }

    std::array<std::array<float,6>,5>* getCoeffs() {
        //MutexGuard guard(&mMutex);
        return &coeffs;
    }
};

#endif 
