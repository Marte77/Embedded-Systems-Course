//
// Created by Martinho Tavares Malhão on 08/09/2025.
//

#ifndef A1_AVALONSTTOP_H
#define A1_AVALONSTTOP_H
#include "systemc.h"
#include "conf.h"
#include "ModuleSlave.h"
#include "ModuleMaster.h"

SC_MODULE(AvalonSTTop) {
    ModuleSlave *slave;//= ModuleSlave("Slave");
    ModuleMaster *master;// = ModuleMaster("Master");
    sc_clock clock = sc_clock("clock", sc_time(CLK_PERIODE, SC_NS));

    sc_trace_file *tf;
    sc_signal<READY_VAL_SIG_TYPE> ready, valid;
    sc_signal<DATA_SIG_TYPE> data;
    sc_signal<ERROR_SIG_TYPE> error;
    SC_CTOR(AvalonSTTop) : ready("ready_sig"),valid("valid_sig"),data("data_sig"),error("error_sig") {
        master = new ModuleMaster("Master");
        slave = new ModuleSlave("Slave");

        master->clock(clock);
        slave->clock(clock);
        master->valid(valid);
        master->ready(ready);
        master->data(data);
        master->error(error);
        slave->valid(valid);
        slave->ready(ready);
        slave->data(data);
        slave->error(error);



        // Create VCD wave form file used for signal timing analysis
        tf = sc_create_vcd_trace_file("WaveForm");
        tf->set_time_unit(1, SC_NS);
        sc_trace(tf, data, "data");
        sc_trace(tf, ready, "ready");
        sc_trace(tf, valid, "valid");
        sc_trace(tf, error, "error");
        sc_trace(tf, clock, "clock");
    }
    ~AvalonSTTop() {
        sc_close_vcd_trace_file(tf);
        delete master;
        delete slave;
    }
};


#endif //A1_AVALONSTTOP_H
