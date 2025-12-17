#include "section.h"
/* @author Geir K. Nilsen (geir.kjetil.nilsen@gmail.com) 2017
 *https://octovoid.com/2017/11/04/coding-a-parametric-equalizer-for-audio-applications/
 * translated from C# to C++ by martinho
 * */
namespace pe {

class ParametricEqualizer {
private:
    int numberOfSections;
    Section section[NUM_BANDS];
    int G0[NUM_BANDS];
    int G[NUM_BANDS];
    int GB[NUM_BANDS];
    int f0[NUM_BANDS];
    int Bf[NUM_BANDS];

public:
    ParametricEqualizer(int numberOfSections, int fs, int* f0_arr, int* Bf_arr,
                        int* GB_arr, int* G0_arr, int* G_arr)
        : numberOfSections(numberOfSections) {
        // Copy arrays to member variables
        for (int i = 0; i < numberOfSections && i < NUM_BANDS; i++) {
            G0[i] = G0_arr[i];
            G[i] = G_arr[i];
            GB[i] = GB_arr[i];
            f0[i] = f0_arr[i];
            Bf[i] = Bf_arr[i];
        }
        
        // Initialize sections
        for (int sectionNumber = 0; sectionNumber < numberOfSections && sectionNumber < NUM_BANDS; sectionNumber++) {
            section[sectionNumber] = Section(f0[sectionNumber], Bf[sectionNumber], GB[sectionNumber], G0[sectionNumber], G[sectionNumber], fs);
        }
    }

    void run(int* x, int* y, int x_size, int& y_size) {
        int input[NUM_BANDS];
        int temp_output[NUM_BANDS];
        
        // Copy input to working array
        for (int i = 0; i < x_size && i < NUM_BANDS; i++) {
            input[i] = x[i];
        }
        
        int current_size = x_size;
        for (int sectionNumber = 0; sectionNumber < numberOfSections && sectionNumber < NUM_BANDS; sectionNumber++) {
            section[sectionNumber].run(input, temp_output, current_size, y_size);
            // Copy output to input for next section
            for (int i = 0; i < y_size && i < NUM_BANDS; i++) {
                input[i] = temp_output[i];
            }
            current_size = y_size;
        }
        
        // Copy final result to output array
        for (int i = 0; i < y_size && i < NUM_BANDS; i++) {
            y[i] = temp_output[i];
        }
    }
};

} // namespace ParametricEqualizer
