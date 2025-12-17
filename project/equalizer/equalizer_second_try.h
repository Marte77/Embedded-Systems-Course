#include <math.h>
#define SAMPLE_RATE 44100
#define SAMPLE_SIZE 1024
#define PI 3.141592
#define Q 1.5
typedef float data_t;
//void equalizer(data_t sample[SAMPLE_SIZE+3], data_t f0, data_t sample_out[SAMPLE_SIZE]);
void equalizer(data_t sample[SAMPLE_SIZE+3], data_t f0, data_t sample_out[SAMPLE_SIZE]);
