//
// Created by Martinho Tavares Malhão on 03/09/2025.
//

#ifndef A1_MAC_H
#define A1_MAC_H
#include "systemc.h"

SC_MODULE(MAC) {
    sc_in<int> a1, a2, b;
    sc_out<int> res;
    sc_signal<int> signal1;
    void add();
    void multiply();
    SC_CTOR(MAC) {
        SC_METHOD(add);
        sensitive << a1 << a2;
        SC_METHOD(multiply);
        sensitive << signal1 << b;

    }
};


#endif //A1_MAC_H
