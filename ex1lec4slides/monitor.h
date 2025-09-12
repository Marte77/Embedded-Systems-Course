//
// Created by Martinho Tavares Malhão on 03/09/2025.
//

#ifndef A1_MONITOR_H
#define A1_MONITOR_H
#include "systemc.h"

SC_MODULE(Monitor) {
    sc_in<int> macOut;
    sc_in<bool> clk;
    void print() {
        for (int i = 0; i < 3; i++) {
            wait(); // waits until mac out signal is written to
            std::cout << name() << " result: " << macOut << " " << sc_time_stamp() << std::endl;
        }
    }
    SC_CTOR(Monitor) {
        SC_THREAD(print);
        sensitive << clk.neg();
    }
};


#endif //A1_MONITOR_H
