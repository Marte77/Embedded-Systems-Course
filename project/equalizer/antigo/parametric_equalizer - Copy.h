#include "section.h"
/* @author Geir K. Nilsen (geir.kjetil.nilsen@gmail.com) 2017
 *https://octovoid.com/2017/11/04/coding-a-parametric-equalizer-for-audio-applications/
 * translated from C# to C++ by martinho
 * */

namespace pe {

class ParametricEqualizer {
private:
    int numberOfSections;
    std::vector<Section> section;
    std::vector<double> G0;
    std::vector<double> G;
    std::vector<double> GB;
    std::vector<double> f0;
    std::vector<double> Bf;

public:
    ParametricEqualizer(int numberOfSections, int fs, std::vector<double>& f0, std::vector<double>& Bf,
                        std::vector<double>& GB, std::vector<double>& G0, std::vector<double>& G)
        : numberOfSections(numberOfSections), G0(G0), G(G), GB(GB), f0(f0), Bf(Bf) {
        section.reserve(numberOfSections);
        for (int sectionNumber = 0; sectionNumber < numberOfSections; sectionNumber++) {
            section.emplace_back(f0[sectionNumber], Bf[sectionNumber], GB[sectionNumber], G0[sectionNumber], G[sectionNumber], fs);
        }
    }

    void run(std::vector<double>& x, std::vector<double>& y) {
        std::vector<double> input = x;
        for (int sectionNumber = 0; sectionNumber < numberOfSections; sectionNumber++) {
            section[sectionNumber].run(input, y);
            input = y; // next section
        }
    }
};

} // namespace ParametricEqualizer
