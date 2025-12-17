#include <cmath>
#include <algorithm>
#include "filter.h"
#define M_PI       3.14159265358979323846   // pi
/* @author Geir K. Nilsen (geir.kjetil.nilsen@gmail.com) 2017
 *https://octovoid.com/2017/11/04/coding-a-parametric-equalizer-for-audio-applications/
 * translated from C# to C++ by martinho
 * */
namespace pe {
    
    const int SCALE = 10000;
    const int PI_SCALED = 31416; // PI * 10000
    class Section {
    private:
        int G0;
        int G;
        int GB;
        int f0;
        int Bf;
        int fs;

        int coeffs[2][3];
        Filter filter;
    public:
        Section() {
            // Default constructor
        }
        int int_pow10_20(int x) {
            // Approximation of 10^(x/20) scaled by 1000
            // For x in range -60 to +20 (typical dB range)
            if (x >= 20) return 10000;
            if (x <= -60) return 1;
            // Linear approximation: 10^(x/20) ≈ 1000 + x*46 for small x
            return 1000 + (x * 46);
        }
        
        int int_sqrt(int x) {
        // Integer square root using binary search
        if (x <= 1) return x;
        int start = 1, end = x, result = 0;
            while (start <= end) {
                int mid = (start + end) / 2;
                if (mid <= x / mid) {
                    start = mid + 1;
                    result = mid;
                } else {
                    end = mid - 1;
                }
            }
            return result;
        }

        int int_tan(int x_scaled) {
            // Simple approximation: tan(x) ≈ x for small x
            // x is already scaled, so return x directly for small angles
            return x_scaled;
        }

        int int_cos(int x_scaled) {
            // Approximation: cos(x) ≈ 1 - x²/2 (scaled)
            // x_scaled is angle * SCALE
            int x_sq = (x_scaled * x_scaled) / SCALE;
            return SCALE - (x_sq / 2);
        }
        
        Section(int f0, int Bf, int GB, int G0, int G, int fs)
            : f0(f0), Bf(Bf), GB(GB), G0(G0), G(G), fs(fs) {

            // All calculations using integer arithmetic with scaling
            // Scale factor: 10000 for higher precision
           
            
            // Integer approximation functions
            

            // Calculate beta using integer arithmetic
            int Bf_half_pi_fs_half = (Bf * PI_SCALED) / (fs * 2);  // (Bf/2) * PI / (fs/2)
            int tan_val = int_tan(Bf_half_pi_fs_half);
            
            // Calculate gain terms (scaled)
            int pow10_GB_20 = int_pow10_20(GB);
            int pow10_G0_20 = int_pow10_20(G0);
            int pow10_G_20 = int_pow10_20(G);
            
            // Calculate beta numerator and denominator
            int pow10_GB_20_sq = (pow10_GB_20 * pow10_GB_20) / 1000;
            int pow10_G0_20_sq = (pow10_G0_20 * pow10_G0_20) / 1000;
            int pow10_G_20_sq = (pow10_G_20 * pow10_G_20) / 1000;
            
            int num_sqrt_arg = (pow10_GB_20_sq > pow10_G0_20_sq) ? 
                              (pow10_GB_20_sq - pow10_G0_20_sq) : (pow10_G0_20_sq - pow10_GB_20_sq);
            int den_sqrt_arg = (pow10_G_20_sq > pow10_GB_20_sq) ? 
                              (pow10_G_20_sq - pow10_GB_20_sq) : (pow10_GB_20_sq - pow10_G_20_sq);
            
            int beta_num = (tan_val * int_sqrt(num_sqrt_arg)) / 1000;
            int beta_den = int_sqrt(den_sqrt_arg);
            int beta = (beta_den > 0) ? (beta_num * SCALE) / beta_den : SCALE;
            
            // Calculate cos term for coefficients
            int f0_pi_fs_half = (f0 * PI_SCALED) / (fs);  // f0 * PI / (fs/2)
            int cos_val = int_cos(f0_pi_fs_half);
            
            // Calculate coefficients (all scaled by SCALE)
            int one_plus_beta = SCALE + beta;
            
            // b coefficients
            int b0_num = (pow10_G0_20 * SCALE) + (pow10_G_20 * beta) / 1000;
            int b0 = (b0_num * 1000) / one_plus_beta;
            
            int b1_num = (-2 * pow10_G0_20 * cos_val) / SCALE;
            int b1 = (b1_num * 1000) / one_plus_beta;
            
            int b2_num = (pow10_G0_20 * SCALE) - (pow10_G_20 * beta) / 1000;
            int b2 = (b2_num * 1000) / one_plus_beta;
            
            // a coefficients
            int a0 = 1000;  // Always 1.0 scaled by 1000
            
            int a1_num = (-2 * cos_val);
            int a1 = (a1_num * 1000) / one_plus_beta;
            
            int a2_num = SCALE - beta;
            int a2 = (a2_num * 1000) / one_plus_beta;

            coeffs[0][0] = b0;
            coeffs[0][1] = b1;
            coeffs[0][2] = b2;

            coeffs[1][0] = a0;
            coeffs[1][1] = a1;
            coeffs[1][2] = a2;

            int a_coeffs[3] = {coeffs[1][0], coeffs[1][1], coeffs[1][2]};
            int b_coeffs[3] = {coeffs[0][0], coeffs[0][1], coeffs[0][2]};
            filter = Filter(a_coeffs, b_coeffs, 3, 3);
        }

        void run(int* x, int* y, int x_size, int& y_size) {
            filter.apply(x, y, x_size, y_size);
        }

    };
}
