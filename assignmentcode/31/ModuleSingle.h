//
// Created by Martinho Tavares Malhão on 04/09/2025.
//

#ifndef A1_MODULESINGLE_H
#define A1_MODULESINGLE_H
#include "systemc.h"

SC_MODULE(ModuleSingle) {
    sc_uint<4> counter;
    sc_event event;
    SC_CTOR(ModuleSingle) {
        SC_THREAD(thread_function);
        SC_METHOD(method_function);
        sensitive << event;
    }
    void method_function() {
        std::cout << "Counter: " << counter << " Timestamp:" << sc_time_stamp() << std::endl;
        counter++;
    }
    void thread_function() {
        while (true) {
            wait(2, SC_MS);
            event.notify();
        }
    }
};


#endif //A1_MODULESINGLE_H
