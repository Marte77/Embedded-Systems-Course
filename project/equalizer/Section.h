#include "Filter.h"
#include <hls_math.h>

const double  PI  = 3.1415926535897932384626433832795;
class Section {
public:
    double G0;
    double G;
    double GB;
    double f0;
    double Bf;
    double fs;
    double coeffs[2][3];
    Filter filter;
    Section() {}
    Section(
    double G0,
    double G,
    double GB,
    double f0,
    double Bf,
    double fs) : G0(G0), G(G), GB(GB), f0(f0), Bf(Bf), fs(fs) {
        double beta = tan(Bf / 2.0 * PI / (fs / 2.0)) * sqrt(abs(pow(pow(10, GB / 20.0), 2.0) - pow(pow(10.0, G0 / 20.0), 2.0))) / sqrt(abs(pow(pow(10.0, G / 20.0), 2.0) - pow(pow(10.0, GB/20.0), 2.0)));

        coeffs[0][0] = (pow(10.0, G0 / 20.0) + pow(10.0, G/20.0) * beta) / (1 + beta);
        coeffs[0][1] = (-2 * pow(10.0, G0/20.0) * cos(f0 * PI / (fs / 2.0))) / (1 + beta);
        coeffs[0][2] = (pow(10.0, G0/20) - pow(10.0, G/20.0) * beta) / (1 + beta);

        coeffs[1][0] = 1.0;
        coeffs[1][1] = -2 * cos(f0 * PI / (fs / 2.0)) / (1 + beta);
        coeffs[1][2] = (1 - beta) / (1 + beta);

        filter = Filter(coeffs[1], coeffs[0]);
    }

    void process(double x[SAMPLE_SIZE], double y[SAMPLE_SIZE])
    {
        filter.apply(x, y);
    }
};
