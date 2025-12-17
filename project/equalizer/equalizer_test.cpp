#include <stdio.h>
#include <fstream>
#include <iostream>
/*#define SAMPLES   48000
#define SAMPLE_FS 48000
#define NUM_BANDS     7
void equalizer(int b0, int b1, int b2, int a1, int a2, // b0, b1, b2, a1, a2
		 short band,
		 short sampleIn,
         short* sampleOut);
int main() {

	//FILE   *rawfile=fopen("cut.raw","w");
	FILE   *fp=fopen("cut.raw.out","w");
	short signal, output;
	printf("OLAAAAAAAAAAA");
	int i;
	for (i=0;i<SAMPLES;i++) {
	  if(i==0)
		  signal = 0x4000;
	  else
		  signal = 0;

	  equalizer(0, 0, 0, 0, 0, NUM_BANDS, signal, &output);

	  printf("%i %d %d\n",i,(int)signal,(int)output);
	  fprintf(fp,"%03i %05d %05d\r\n",i,signal,output);
	}
	fclose(fp);
	return 0;
}
*/
#include "equalizer_second_try.h"
//#define SAMPLE_SIZE 10
//#define NUM_SECTIONS 4
//void equalizer(double* sample, double GB[NUM_SECTIONS], double G0[NUM_SECTIONS], double G[NUM_SECTIONS], double bandwith[NUM_SECTIONS], double frequencies[NUM_SECTIONS], double* outresult);
//void equalizer(float sample[SAMPLE_SIZE], float f0, float prev_sample[3]);
int main() {
	/*double x[SAMPLE_SIZE] = { 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // input signal (delta function example, scaled by 1000)
	double y[SAMPLE_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0,0};
	double frequencies[4] = { 200, 250, 300, 350 };     // frequencies in Hz
	double bandwith[4] = { 5, 5, 5, 5 };             // bandwidth
	double GB_arr[4] = { 900, 900, 900, 900 };     // GB values (9.0 * 100 for scaling)
	double G0_arr[4] = { 0, 0, 0, 0 };             // G0 values
	double G_arr[4] = { 800, 1000, 1200, 1400 };   // G values (8.0, 10.0, 12.0, 14.0 * 100 for scaling)

	equalizer(x,GB_arr, G0_arr, G_arr, bandwith, frequencies, y);*/
	std::ifstream c("netsky_lost_in_this_world.raw", std::ios_base::binary);
	std::cout << "OLA SIZE: " << SAMPLE_SIZE << std::endl;
	data_t sample[SAMPLE_SIZE+3], out[SAMPLE_SIZE];
	for (int i = 0; i < SAMPLE_SIZE + 3; i++) {
		sample[i] = 0;
	}
	equalizer(sample, 100, out);
	/*FILE * out = fopen("netsky_ya.raw", "wb");
	if (c) {
		data_t prev[3];
		data_t val;
		data_t sample[SAMPLE_SIZE], sample_orig[SAMPLE_SIZE];
		for (int i = 0; i < 1; i ++) {
			for (int i = 0; i < 3; i++) {
				c.read((char*)&val, sizeof(val));
				prev[i] = val;
			}
			for (int i = 0; i < SAMPLE_SIZE; i++){
				c.read((char*)&val, sizeof(val));
				sample[i] = val;
				sample_orig[i] = val;
			}
			equalizer(sample, 100, prev);
			for (int i = 0; i < SAMPLE_SIZE; i++){
				val = sample[i];
				//std::cout << sample[i] << " " << sample_orig[i] << std::endl;
				//fwrite(&val, sizeof(data_t), 1, out);
			}
		}
	}
	fclose(out);*/
	/*data_t w0 = 2 * PI * 100 /SAMPLE_RATE;
	data_t alpha = sin(w0) / (2*Q);
	data_t a0 = 1+alpha;
	data_t a1 = -2 * cos(w0);
	data_t a2 = 1 - alpha;
	data_t b1 = -(1+cos(w0));
	data_t b0 = (-b1) / 2;
	data_t b0_over_a0 = b0 / a0;
	std::cout << w0 << std::endl << alpha << std::endl << a0 << std::endl << a1 << std::endl << a2 << std::endl << b1 << std::endl << b0 << std::endl << b0_over_a0 << std::endl;
*/
	return 0;
}
