#include "neuralNet.h"

#define multfix(a,b) ((int)((((signed long long) a)*((signed long long) b)) >> BITS))

void neuralNet(char input[INPUT_LEN], short weightsI[WEIGHTS_I_LEN],
               short weightsO[WEIGHTS_O_LEN], int output[OUTPUT_LEN],
               ap_int<SL_LEN> inSwitch, ap_int<SL_LEN> *outLeds) {
	int neurons[NEURONS_LEN];
	int neuron, result;
	int i, j, offsetI, offsetO;
    for (i = 0; i < NEURONS_LEN; i++) {
    	neuron = 0;
    	offsetI = NEURONS_LEN * i;
    	neuralNet_label0:for (j = 0; j < INPUT_LEN; j++)
    		neuron += multfix((input[j]<<BITS), (weightsI[j + offsetI])) ;
    	neurons[i] = neuron>> BITS;
    	if (neuron < 0) // ReLU activation
    		neurons[i] = 0;
    }
    // Compute output layer
    for (i = 0; i < OUTPUT_LEN; i++) {
    	result = 0;
    	offsetO = OUTPUT_LEN * i;
    	neuralNet_label1:for (j = 0; j < NEURONS_LEN; j++)
    		result += multfix((neurons[j] << BITS), (weightsO[j + offsetO]));
    	output[i] = result >> BITS;
    }
    *outLeds = inSwitch;
}
