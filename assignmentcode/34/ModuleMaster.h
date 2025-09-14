//
// Created by Martinho Tavares Malhão on 08/09/2025.
//

#ifndef A1_MODULEMASTER_H
#define A1_MODULEMASTER_H
#include "systemc.h"
#include "conf.h"
#include <random>


SC_MODULE(ModuleMaster) { // data source
    sc_in_clk clock;
    sc_in<READY_VAL_SIG_TYPE> ready;
    sc_out<READY_VAL_SIG_TYPE> valid;
    sc_out<DATA_SIG_TYPE> data;
    sc_out<ERROR_SIG_TYPE> error;
    sc_out<CHANNEL_SIG_TYPE> channel;
    SC_CTOR(ModuleMaster) {
        SC_THREAD(work_a_serio);
        sensitive << clock << ready;
        dont_initialize();
    }
    ~ModuleMaster() { }

    void work_a_serio() {
        std::random_device rd;  // a seed source for the random number engine
        std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> value_rng(1, 320);
        while (true) {
            do { wait(); } while(!ready); // wait() works until the next clock - waiting until ready is sent by slave
            wait();
            data.write(value_rng(gen)); // write value so slave can read it
            valid.write(true); // write valid so slave knows he can read it
            do { wait(); } while(ready); // wait until slave sends false to end the request
            valid.write(false); // set valid to false and wait again for ready == true
            wait();
        }
    }

};


#endif //A1_MODULEMASTER_H
