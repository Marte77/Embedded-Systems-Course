/*#include "equalizer.h"
#include <string.h>

// Default FIR coefficients for each band (low-pass characteristics)
// These are example coefficients - in practice, you would design specific
// coefficients for each frequency band using filter design tools
static const int16_t default_coeffs[NUM_BANDS][FIR_TAPS] = {
    // Band 0: Low frequencies (60-170 Hz)
    {0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x1800, 0x1C00, 0x1E00,
     0x1E00, 0x1C00, 0x1800, 0x1000, 0x0800, 0x0400, 0x0200, 0x0100},
    
    // Band 1: Low-mid frequencies (170-310 Hz)
    {0x0080, 0x0180, 0x0300, 0x0600, 0x0C00, 0x1400, 0x1A00, 0x1D00,
     0x1D00, 0x1A00, 0x1400, 0x0C00, 0x0600, 0x0300, 0x0180, 0x0080},
    
    // Band 2: Mid frequencies (310-600 Hz)
    {0x0060, 0x0140, 0x0280, 0x0500, 0x0A00, 0x1200, 0x1800, 0x1C00,
     0x1C00, 0x1800, 0x1200, 0x0A00, 0x0500, 0x0280, 0x0140, 0x0060},
    
    // Band 3: Upper-mid frequencies (600-1.2 kHz)
    {0x0040, 0x0120, 0x0240, 0x0480, 0x0900, 0x1100, 0x1600, 0x1A00,
     0x1A00, 0x1600, 0x1100, 0x0900, 0x0480, 0x0240, 0x0120, 0x0040},
    
    // Band 4: High-mid frequencies (1.2-2.5 kHz)
    {0x0030, 0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x1400, 0x1800,
     0x1800, 0x1400, 0x1000, 0x0800, 0x0400, 0x0200, 0x0100, 0x0030},
    
    // Band 5: High frequencies (2.5-5 kHz)
    {0x0020, 0x00E0, 0x01C0, 0x0380, 0x0700, 0x0E00, 0x1200, 0x1600,
     0x1600, 0x1200, 0x0E00, 0x0700, 0x0380, 0x01C0, 0x00E0, 0x0020},
    
    // Band 6: Very high frequencies (5-10 kHz)
    {0x0010, 0x00C0, 0x0180, 0x0300, 0x0600, 0x0C00, 0x1000, 0x1400,
     0x1400, 0x1000, 0x0C00, 0x0600, 0x0300, 0x0180, 0x00C0, 0x0010}
};

Equalizer::Equalizer() {
    // Initialize all arrays to zero
    memset(delay_line, 0, sizeof(delay_line));
    memset(delay_index, 0, sizeof(delay_index));
    
    // Set default gains to unity (1.0 in Q15 format)
    for (int i = 0; i < NUM_BANDS; i++) {
        band_gains[i] = 0x4000;  // 0.5 in Q15 format as default
    }
    
    // Initialize default coefficients
    init_default_coefficients();
}

void Equalizer::init_default_coefficients() {
    for (int band = 0; band < NUM_BANDS; band++) {
        for (int tap = 0; tap < FIR_TAPS; tap++) {
            coefficients[band][tap] = default_coeffs[band][tap];
        }
    }
}

void Equalizer::set_band_gain(int band, int16_t gain) {
    if (band >= 0 && band < NUM_BANDS) {
        band_gains[band] = gain;
    }
}

void Equalizer::set_band_coefficients(int band, const int16_t* coeffs) {
    if (band >= 0 && band < NUM_BANDS && coeffs != nullptr) {
        for (int i = 0; i < FIR_TAPS; i++) {
            coefficients[band][i] = coeffs[i];
        }
    }
}

int16_t Equalizer::apply_fir_filter(int band, int16_t sample) {
    // Add new sample to delay line
    delay_line[band][delay_index[band]] = sample;
    
    // Compute FIR filter output
    int32_t output = 0;
    int idx = delay_index[band];
    
    for (int i = 0; i < FIR_TAPS; i++) {
        // Multiply coefficient with delayed sample
        output += (int32_t)coefficients[band][i] * delay_line[band][idx];
        
        // Move to previous sample (circular buffer)
        idx = (idx - 1 + FIR_TAPS) % FIR_TAPS;
    }
    
    // Update delay index for next sample
    delay_index[band] = (delay_index[band] + 1) % FIR_TAPS;
    
    // Scale down and apply band gain
    output >>= (ALGO_BITS - 1);  // Scale FIR output
    output = (output * band_gains[band]) >> 14;  // Apply gain (Q15 * Q15 = Q30, shift by 14 for Q16)
    
    // Clamp to 16-bit range
    if (output > 32767) output = 32767;
    if (output < -32768) output = -32768;
    
    return (int16_t)output;
}

void Equalizer::equalize(int16_t sample, const int16_t* band_settings, int16_t* result) {
    // Update band gains if provided
    if (band_settings != nullptr) {
        for (int i = 0; i < NUM_BANDS; i++) {
            band_gains[i] = band_settings[i];
        }
    }
    
    // Process sample through all bands
    int32_t output = 0;
    
    for (int band = 0; band < NUM_BANDS; band++) {
        int16_t band_output = apply_fir_filter(band, sample);
        output += band_output;
    }
    
    // Scale and clamp final output
    output >>= 3;  // Divide by 8 to prevent overflow with 7 bands
    
    if (output > 32767) output = 32767;
    if (output < -32768) output = -32768;
    
    *result = (int16_t)output;
}

void Equalizer::reset() {
    // Clear all delay lines
    memset(delay_line, 0, sizeof(delay_line));
    memset(delay_index, 0, sizeof(delay_index));
}

int16_t Equalizer::get_band_gain(int band) const {
    if (band >= 0 && band < NUM_BANDS) {
        return band_gains[band];
    }
    return 0;
}*/
#include "equalizer.h"
#include <iostream>
#include <vector>

int main() {
    // Create an instance of the equalizer
    Equalizer eq;
    
    // Example: Set some band gains
    // Band gains in Q15 format: 0x7FFF = 1.0, 0x4000 = 0.5, 0x0000 = 0.0
    int16_t band_settings[NUM_BANDS] = {
        0x6000,  // Band 0: 75% gain
        0x4000,  // Band 1: 50% gain  
        0x7FFF,  // Band 2: 100% gain
        0x2000,  // Band 3: 25% gain
        0x5000,  // Band 4: 62.5% gain
        0x3000,  // Band 5: 37.5% gain
        0x1000   // Band 6: 12.5% gain
    };
    
    // Test with some sample data
    std::vector<int16_t> test_samples = {
        1000, 2000, -1500, 3000, -2500, 1200, -800, 2200, -1800, 900
    };
    
    std::cout << "Equalizer Test Results:" << std::endl;
    std::cout << "Input Sample\t-> Output Sample" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    
    for (size_t i = 0; i < test_samples.size(); i++) {
        int16_t input = test_samples[i];
        int16_t output;
        
        // Process the sample through the equalizer
        eq.equalize(input, band_settings, &output);
        
        std::cout << input << "\t\t-> " << output << std::endl;
    }
    
    // Example: Change individual band gains
    std::cout << "\nChanging band 2 gain to maximum (1.0)..." << std::endl;
    eq.set_band_gain(2, 0x7FFF);
    
    // Process another sample
    int16_t test_sample = 1500;
    int16_t result;
    eq.equalize(test_sample, nullptr, &result);  // Use existing band settings
    
    std::cout << "Sample " << test_sample << " -> " << result << std::endl;
    
    // Display current band gains
    std::cout << "\nCurrent Band Gains:" << std::endl;
    for (int i = 0; i < NUM_BANDS; i++) {
        int16_t gain = eq.get_band_gain(i);
        float gain_percent = (float)gain / 0x7FFF * 100.0f;
        std::cout << "Band " << i << ": 0x" << std::hex << gain 
                  << " (" << std::dec << gain_percent << "%)" << std::endl;
    }
    
    return 0;
}