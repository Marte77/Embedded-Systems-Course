//
// Created by Martinho Tavares Malhão on 08/09/2025.
//

#ifndef A1_35_MODULEMASTER_H
#define A1_35_MODULEMASTER_H
#include "systemc.h"
#include "conf_35.h"
#include "InAdapter.h"
#include <random>


SC_MODULE(ModuleMaster_35) { // data source
    InAdapter<int> *fifo;
    SC_CTOR(ModuleMaster_35, InAdapter<int>*fifo) {
        this->fifo = fifo;
        SC_THREAD(work_a_serio);
    }
    ~ModuleMaster_35() { }

    void work_a_serio() {
        std::random_device rd;  // a seed source for the random number engine
        std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> value_rng(1, 320);
        std::cout << name() << "::Printing the values: [";
        for(int i = 0; i < 15; i++) {
            wait(5, SC_NS);
            auto v = value_rng(gen);
            std::cout << v << ", ";
            fifo->write(v);
        }
        std::cout << "]" << std::endl;
    }

};


#endif //A1_35_MODULEMASTER_H
