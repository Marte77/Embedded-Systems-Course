//
// Created by Martinho Tavares Malhão on 03/09/2025.
//

#ifndef A1_STIMULUS_H
#define A1_STIMULUS_H
#include "systemc.h"

SC_MODULE(Stimmer) {
    sc_in<bool> clock;
    sc_out<int> a1,a2, b;
    void generate_values();
    SC_CTOR(Stimmer) {
        SC_THREAD(generate_values);
        sensitive << clock.pos();
    }
};


#endif //A1_STIMULUS_H
