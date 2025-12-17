/*
 * Equalizer.h
 *
 *  Created on: 15 Dec 2025
 *      Author: marti
 */

#ifndef SRC_EQUALIZER_H_
#define SRC_EQUALIZER_H_

#include "EQSettings.h"

class Equalizer {
	XEqualizer *eq;
public:
	Equalizer(XEqualizer *eq) : eq(eq) {
       
	}

    void updateGain(std::array<std::array<float,6>,5>* coeffs) {
        XEqualizer_Set_mode(eq, 2); // anything other than 1 will cause the core to check the coeffs
        float c[5][6];
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 6; j++)
                c[i][j] = (*coeffs)[i][j];
        
        XEqualizer_Write_coeffs_Words(eq, 0, (int*)c, sizeof(float)*5*6); // is this correct? the int* c cast is kinda weird
        XEqualizer_Start(eq);
        while(XEqualizer_IsDone(eq) == 0); // wait for set
    }
    float getAudioAltered(float sample) {
        XEqualizer_Set_mode(eq, 1);
        XEqualizer_Set_x(eq, sample);
        XEqualizer_Start(eq);
        while(XEqualizer_IsDone(eq) == 0); // wait for set
        return (float)XEqualizer_Get_y(eq);
    }
    
};

#endif /* SRC_EQUALIZER_H_ */
