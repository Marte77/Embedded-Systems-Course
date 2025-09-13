//
// Created by Martinho Tavares Malhão on 12/09/2025.
//

#ifndef A1_TOP35_H
#define A1_TOP35_H
#include "systemc.h"
#include "ModuleMaster_35.h"
#include "ModuleSlave_35.h"
#include "conf_35.h"
#include "InAdapter.h"

SC_MODULE(Top35) {
    ModuleMaster_35 *master;
    ModuleSlave_35 *slave;

    sc_clock clock = sc_clock("clock", sc_time(CLK_PERIODE, SC_NS));
    sc_trace_file *tf;
    sc_signal<READY_VAL_SIG_TYPE_35> ready, valid, reset;
    sc_signal<DATA_SIG_TYPE_35> data;
    sc_signal<ERROR_SIG_TYPE_35> error;
    sc_signal<CHANNEL_SIG_TYPE_35> channel;
    sc_fifo<int> fifo;
    InAdapter<int> *inAdapter;

    SC_CTOR(Top35) : reset("reset_sig"),fifo("fifo_sig"),channel("channel_sig"),ready("ready_sig"),valid("valid_sig"),data("data_sig"),error("error_sig") {
        inAdapter = new InAdapter<int>("InAdapter");
        master = new ModuleMaster_35("Master_35", inAdapter);
        slave = new ModuleSlave_35("Slave_35");
        slave->clock(clock);
        inAdapter->clock(clock);
        inAdapter->ready(ready);
        slave->ready(ready);
        inAdapter->valid(valid);
        slave->valid(valid);
        inAdapter->error(error);
        slave->error(error);
        inAdapter->channel(channel);
        slave->channel(channel);
        inAdapter->data(data);
        slave->data(data);
        inAdapter->reset(reset);
        slave->reset(reset);


        // Create VCD wave form file used for signal timing analysis
        tf = sc_create_vcd_trace_file("35_WaveForm");
        tf->set_time_unit(1, SC_NS);
        sc_trace(tf, data, "data");
        sc_trace(tf, ready, "ready");
        sc_trace(tf, valid, "valid");
        sc_trace(tf, error, "error");
        sc_trace(tf, clock, "clock");
        sc_trace(tf, channel, "channel");
        sc_trace(tf, reset, "reset");
        // sc_trace of fifo gives error TODO see why
        // sc_trace(tf, fifo, "fifo");



    }
    ~Top35() {
        sc_close_vcd_trace_file(tf);
        delete master;
        delete slave;
    }
};


#endif //A1_TOP35_H
