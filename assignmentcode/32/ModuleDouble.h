//
// Created by Martinho Tavares Malhão on 04/09/2025.
//

#ifndef A1_MODULEDOUBLE_H
#define A1_MODULEDOUBLE_H

#include "systemc.h"

SC_MODULE(ModuleDouble) {
    sc_event eventA, eventB, eventAack, eventBack;
    SC_CTOR(ModuleDouble) {
        SC_THREAD(threadA);
        sensitive << eventAack;
        SC_THREAD(threadB);
        sensitive << eventBack;
        SC_METHOD(methodA);
        sensitive << eventA << eventB; // probably can only specify sensitivity for eventB since it fires first but shouldn't matter much
    }
    void threadA() {
        while (true) {
            wait(3, SC_MS);
            eventA.notify();
            wait(3,SC_MS, eventAack);//wait on event A ACK or timeout after 3 ms
        }
    }
    void threadB() {
        while (true) {
            wait(2, SC_MS);
            eventB.notify();
            wait(2, SC_MS, eventBack); //wait on event B ACK or timeout after 2 ms
        }
    }
    void methodA() {
        if (eventA.triggered()) {
            std::cout << "Event A triggered, sending a Aack. Simulation time: " << sc_time_stamp() << std::endl;
            eventAack.notify();
            // if we don't specify this next_trigger, there's a chance we could respond to 2 consecutive A events
            // which we don't want, per the exercise
            next_trigger(eventB);
        } else if (eventB.triggered()) {
            std::cout << "Event B triggered, sending a Back. Simulation time: " << sc_time_stamp() << std::endl;
            eventBack.notify();
            next_trigger(eventA);
        }
    }
};


#endif //A1_MODULEDOUBLE_H
