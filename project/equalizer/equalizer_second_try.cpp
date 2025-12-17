#include "equalizer_second_try.h"

float computeK(int n) {
	float k = 1.0;
	for (int i = 0; i<n; i++) {
		k *= 1 / sqrt(1 + pow(2, (-2*i)));
	}
	return k;
}

float cordic(float alpha, int n, float* res, bool cos) {

}


/* f0 sets the cutt off frequency
* prev_sample contains the last 3 values of the previous sample
**/
void equalizer(data_t sample[SAMPLE_SIZE+3], data_t f0, data_t sample_out[SAMPLE_SIZE]/*, data_t alpha, data_t a0, data_t a1, data_t a2, data_t b1, data_t w0, data_t b0*/
																		  ) {
	// with a sample rate of 44.1khz, the sample corresponds to 23 milliseconds of audio
	data_t w0 = 2 * PI * f0 /SAMPLE_RATE;
	data_t alpha = sin(w0) / (2*Q);
	data_t a0 = 1+alpha;
	data_t a1 = -2 * cos(w0);
	data_t a2 = 1 - alpha;
	data_t b1 = -(1+cos(w0));
	data_t b0 = (-b1) / 2;
	data_t b0_over_a0 = b0 / a0;
	data_t b1_over_a0 = b1 / a0;
	data_t a1_over_a0 = a1 / a0;
	data_t a2_over_a0 = a2 / a0;
	data_t prev_sample[3] = {
			sample[0], sample[1], sample[2]
	};
	// values for f0 = 100
	/*data_t w0         = 0.0142476  ;//2 * PI * f0 /SAMPLE_RATE;
	data_t alpha      = 0.00474903 ;//sin(w0) / (2*Q);
	data_t a0         = 1.00475    ;//1+alpha;
	data_t a1 	      = -1.9998    ;//-2 * cos(w0);
	data_t a2 	      = 0.995251   ;//1 - alpha;
	data_t b1 	      = -1.9999    ;//-(1+cos(w0));
	data_t b0 	      = 0.999949   ;//(-b1) / 2;
	data_t b0_over_a0 = 0.995223  ;//b0 / a0;

	//data_t b0_over_a0 = b0 / a0;
	data_t b1_over_a0 = b1 / a0;
	data_t a1_over_a0 = a1 / a0;
	data_t a2_over_a0 = a2 / a0;*/
equalizer_label7:	for (int i = 3; i < SAMPLE_SIZE+3; i++) {
		prev_sample[2] = prev_sample[1];
		prev_sample[1] = prev_sample[0];
		prev_sample[0] = sample[i];
		sample_out[i] = (b0_over_a0 * prev_sample[0])
				+ (b1_over_a0 * prev_sample[1])
				+ (b0_over_a0 * prev_sample[2]) // since b2 is equal to b0 in this formula
				- (a1_over_a0 * sample[i-1])
				- (a2_over_a0 * sample[i-2]);
	}
}
