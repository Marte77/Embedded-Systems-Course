#include "ParametricEqualizer.h"
void equalizer(double sample[SAMPLE_SIZE], double GB[NUM_SECTIONS], double G0[NUM_SECTIONS], double G[NUM_SECTIONS], double bandwith[NUM_SECTIONS], double frequencies[NUM_SECTIONS], double* outresult) {
	// Convert to integer arrays (using scaling where needed)

	double y[SAMPLE_SIZE]; // output signal
	
	// Parameter arrays (scaled appropriately)
	
	// Create parametric equalizer with integer parameters
	ParametricEqualizer peq(1000, frequencies, bandwith, GB, G0, G);
	
	// Run the equalizer
	peq.run(sample, y);
	outresult = y;
}

