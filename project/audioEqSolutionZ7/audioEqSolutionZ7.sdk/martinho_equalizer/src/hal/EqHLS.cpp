/*
 * EqHLS.cpp
 *
 *  Created on: 5. dec. 2017
 *      Author: au288681
 */


#include "EqHLS.h"

int EqHLS::Init(void)
{
	/*XEq_Config *cfgPtr;
	int status;

	cfgPtr = XEq_LookupConfig(mDeviceId);
	if (!cfgPtr) {
	  print("ERROR: Lookup of EQ configuration failed.\n\r");
	  status = XST_FAILURE;
   	  return status;
	}

	status = XEq_CfgInitialize(&mHlsEq, cfgPtr);
	if (status != XST_SUCCESS) {
	  print("ERROR: Could not initialize EQ.\n\r");
	}
	return status;*/
	XEqualizer_Config *config;
	config = XEqualizer_LookupConfig(mDeviceId);
	int status = XEqualizer_CfgInitialize(&mHlsEq, config);
	if (status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	XEqualizer_Initialize(&mHlsEq, mDeviceId);
	return status;
}

void EqHLS::filterSample(unsigned long sample)
{
	// send samples after shifting least significant 8 bits as the filter
	// requires 16 bit input sample
	/*while (XEq_IsReady(&mHlsEq) == 0); // Polling ready register
	XEq_Set_band(&mHlsEq, 0xff); // Ensure EQ filtering samples
	XEq_Set_sampleIn(&mHlsEq, sample >> 8);
	XEq_Start(&mHlsEq);*/
	XEqualizer_Set_mode(&mHlsEq, 1);
	XEqualizer_Set_x(&mHlsEq, sample >> 8);
	XEqualizer_Start(&mHlsEq);;
}

unsigned long EqHLS::getFiltered(void)
{
	unsigned long u32Data;

	while (XEqualizer_IsDone(&mHlsEq) == 0); // Polling done register
	u32Data = XEqualizer_Get_y(&mHlsEq);
	// shift left by 8 bits as output sample is 16 bit whereas CODEC requires 24 bits
    return u32Data << 8;
}

// Writting coefficients to equalizer band
void EqHLS::setCoeff(int *coeff, int band)
{
	/*while (XEq_IsReady(&mHlsEq) == 0); // Polling ready register
	XEq_Set_b0(&mHlsEq, coeff[0]);
	XEq_Set_b1(&mHlsEq, coeff[1]);
	XEq_Set_b2(&mHlsEq, coeff[2]);
	XEq_Set_a1(&mHlsEq, coeff[4]);
	XEq_Set_a2(&mHlsEq, coeff[5]);
	XEq_Set_band(&mHlsEq, band);
	XEq_Start(&mHlsEq);
	while (XEq_IsDone(&mHlsEq) == 0); // Polling done register
	*/
}

void EqHLS::setCoeffsMarte(float** coeffs) {
	while (XEqualizer_IsReady(&mHlsEq) == 0); // Polling ready register

	XEqualizer_Set_mode(&mHlsEq, 2);
	XEqualizer_Write_coeffs_Words(&mHlsEq, 0, (int*)coeffs, sizeof(float)*5*6);
	XEqualizer_Start(&mHlsEq);;
}
