#include "Section.h"
#define NUM_SECTIONS 4
class ParametricEqualizer {
public:
    Section sections[NUM_SECTIONS]; 
    double G0[NUM_SECTIONS]; 
    double G[NUM_SECTIONS]; 
    double GB[NUM_SECTIONS]; 
    double f0[NUM_SECTIONS]; 
    double Bf[NUM_SECTIONS]; 

    ParametricEqualizer(double fs, double f0_arr[NUM_SECTIONS], double Bf_arr[NUM_SECTIONS],
                        double GB_arr[NUM_SECTIONS], double G0_arr[NUM_SECTIONS], double G_arr[NUM_SECTIONS]) {
        for (int i = 0; i < NUM_SECTIONS; i++) {
            G0[i] = G0_arr[i];
            G[i] = G_arr[i];
            GB[i] = GB_arr[i];
            f0[i] = f0_arr[i];
            Bf[i] = Bf_arr[i];
        }
        
        for (int sectionNumber = 0; sectionNumber < NUM_SECTIONS; sectionNumber++) {
            sections[sectionNumber] = Section(f0[sectionNumber], Bf[sectionNumber], GB[sectionNumber], G0[sectionNumber], G[sectionNumber], fs);
        }
    }

    void run(double x[SAMPLE_SIZE], double y[SAMPLE_SIZE]) {
        for (int i = 0; i < SAMPLE_SIZE; i++) {
            y[i] = x[i];
        }
        for (int i = 0; i < NUM_SECTIONS; i++) {
            sections[i].process(y, y);
        }
    }
};
