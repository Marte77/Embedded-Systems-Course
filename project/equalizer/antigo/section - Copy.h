#include <vector>
#include <cmath>
#include <algorithm>
#include "filter.h"
#define M_PI       3.14159265358979323846   // pi
/* @author Geir K. Nilsen (geir.kjetil.nilsen@gmail.com) 2017
 *https://octovoid.com/2017/11/04/coding-a-parametric-equalizer-for-audio-applications/
 * translated from C# to C++ by martinho
 * */
namespace pe {
    class Section {
        
    private:
        double G0;
        double G;
        double GB;
        double f0;
        double Bf;
        double fs;
        double fs;

        std::vector<std::vector<double>> coeffs;
        Filter filter = Filter(std::vector<double>{1.0}, std::vector<double>{1.0});
    public:
        Section(double f0, double Bf, double GB, double G0, double G, double fs)
            : f0(f0), Bf(Bf), GB(GB), G0(G0), G(G), fs(fs){

            coeffs.resize(2);
            coeffs[0].resize(3);
            coeffs[1].resize(3);
            

            double beta = std::tan(Bf / 2.0 * M_PI / (fs / 2.0)) *
                std::sqrt(std::abs(std::pow(std::pow(10, GB / 20.0), 2.0) - std::pow(std::pow(10.0, G0 / 20.0), 2.0))) /
                std::sqrt(std::abs(std::pow(std::pow(10.0, G / 20.0), 2.0) - std::pow(std::pow(10.0, GB / 20.0), 2.0)));

            coeffs[0][0] = (std::pow(10.0, G0 / 20.0) + std::pow(10.0, G / 20.0) * beta) / (1 + beta);
            coeffs[0][1] = (-2 * std::pow(10.0, G0 / 20.0) * std::cos(f0 * M_PI / (fs / 2.0))) / (1 + beta);
            coeffs[0][2] = (std::pow(10.0, G0 / 20.0) - std::pow(10.0, G / 20.0) * beta) / (1 + beta);

            coeffs[1][0] = 1.0;
            coeffs[1][1] = -2 * std::cos(f0 * M_PI / (fs / 2.0)) / (1 + beta);
            coeffs[1][2] = (1 - beta) / (1 + beta);

            filter = Filter(coeffs[1], coeffs[0]);
        }

        std::vector<double> run(std::vector<double>& x, std::vector<double>& y) {
            filter.apply(x, y);
            return y;
        }

    };
}
