//
// Created by Martinho Tavares Malhão on 08/09/2025.
//

#ifndef A1_35_MODULESLAVE_H
#define A1_35_MODULESLAVE_H
#include "systemc.h"
#include "conf_35.h"
#include "InAdapter.h"
#include <random>


SC_MODULE(ModuleSlave_35) { // data sink
    sc_in_clk clock;
    sc_out<READY_VAL_SIG_TYPE_35> ready;
    sc_in<READY_VAL_SIG_TYPE_35> valid, reset;
    sc_in<DATA_SIG_TYPE_35> data;
    sc_in<ERROR_SIG_TYPE_35> error;
    sc_in<CHANNEL_SIG_TYPE_35> channel;
    FILE* data_file;

    SC_CTOR(ModuleSlave_35) {
        data_file = fopen("35_slave_received_data.slv","w");
        SC_THREAD(work_a_serio);
        sensitive << clock << valid << data << error;
        dont_initialize();
    }
    ~ModuleSlave_35() {
        fclose(data_file);
    }

    void work_a_serio() {
        while (true) {
            //ready.write(SC_LOGIC_1);
            ready.write(true);
            //do { wait(); /* waits until the next clock or valid or data change */ } while(valid != SC_LOGIC_0); // wait until valid is sent by master
            do { wait(); /* waits until the next clock or valid or data change */ } while(valid); // wait until valid is sent by master
            auto number = data.read(); // read and save
            fprintf(data_file, "%d\n", number.to_int());
            wait();
            //ready.write(SC_LOGIC_0); // send false to master so it can set valid to false
            ready.write(false); // send false to master so it can set valid to false
            wait();
        }
    }

};


#endif //A1_35_MODULESLAVE_H
