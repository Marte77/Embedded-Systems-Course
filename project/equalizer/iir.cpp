#include "iir.h"

void equalizer(data_t *y, data_t x, int mode, data_t coeffs[NUM_SECTIONS][6]) {
	 static IIRFilter iir;
	 if (mode == 1)
		 *y = iir.filter(x);
	 else {
		 iir.setCoeffs(coeffs);
	 }
}
