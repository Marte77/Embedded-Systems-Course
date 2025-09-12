//
// Created by Martinho Tavares Malhão on 08/09/2025.
//

#ifndef A1_MODULESLAVE_H
#define A1_MODULESLAVE_H
#include "systemc.h"
#include "conf.h"
#include <random>


SC_MODULE(ModuleSlave) { // data sink
    sc_in_clk clock;
    sc_out<READY_VAL_SIG_TYPE> ready;
    sc_in<READY_VAL_SIG_TYPE> valid;
    sc_in<DATA_SIG_TYPE> data;
    sc_in<ERROR_SIG_TYPE> error;
    sc_out<CHANNEL_SIG_TYPE> channel;
    FILE* data_file;

    SC_CTOR(ModuleSlave) {
        data_file = fopen("34_slave_received_data.slv","w");
        SC_THREAD(work_a_serio);
        sensitive << clock << valid << data << error;
        dont_initialize();
    }
    ~ModuleSlave() {
        fclose(data_file);
    }

    void work_a_serio() {
        wait(5, SC_NS);
        while (true) {
            wait();
            ready.write(true);
            do { wait(); /* waits until the next clock or valid or data change */ } while(!valid); // wait until valid is sent by master
            int number = data; // read and save
            fprintf(data_file, "%d\n", number);
            wait();
            ready.write(false); // send false to master so it can set valid to false
            wait();
        }
    }

};


#endif //A1_MODULESLAVE_H
