/*#ifndef EQUALIZER_H
#define EQUALIZER_H

#include <stdint.h>

#define NUM_BANDS       7      // Number of frequency bands
#define FIR_TAPS        16     // Number of FIR filter taps per band
#define ALGO_BITS       16     // 16 bits resolution of samples

class Equalizer {
private:
    // FIR filter coefficients for each band (16-bit signed)
    int16_t coefficients[NUM_BANDS][FIR_TAPS];
    
    // Delay line (history buffer) for each band
    int16_t delay_line[NUM_BANDS][FIR_TAPS];
    
    // Current position in circular delay buffer for each band
    int delay_index[NUM_BANDS];
    
    // Band gains (16-bit signed, in Q15 format: 0x7FFF = 1.0)
    int16_t band_gains[NUM_BANDS];
    
    // Initialize default FIR coefficients for each band
    void init_default_coefficients();
    
    // Apply FIR filter for a specific band
    int16_t apply_fir_filter(int band, int16_t sample);

public:
    // Constructor
    Equalizer();
    
    // Set gain for a specific band
    // band: 0 to NUM_BANDS-1
    // gain: 16-bit signed gain value (0x7FFF = 1.0, 0x4000 = 0.5, 0x0000 = 0.0)
    void set_band_gain(int band, int16_t gain);
    
    // Set FIR coefficients for a specific band
    void set_band_coefficients(int band, const int16_t* coeffs);
    
    // Main equalizer processing function
    // sample: input sample (16-bit signed)
    // band_settings: array of band gains to apply (can be NULL to use existing settings)
    // result: pointer to store the output sample
    void equalize(int16_t sample, const int16_t* band_settings, int16_t* result);
    
    // Reset all delay lines
    void reset();
    
    // Get current gain for a specific band
    int16_t get_band_gain(int band) const;
};

#endif // EQUALIZER_H*/
