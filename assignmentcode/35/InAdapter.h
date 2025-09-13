//
// Created by Martinho Tavares Malhão on 12/09/2025.
//

#ifndef A1_INADAPTER_H
#define A1_INADAPTER_H

#include "systemc.h"
#include "conf_35.h"
template<class T>
class InAdapter : public sc_fifo_out_if<T>, public sc_module {
public:
    // Clock and reset
    sc_in_clk clock;
    sc_in<READY_VAL_SIG_TYPE_35> reset;
    // Handshake ports for ST bus
    sc_in<READY_VAL_SIG_TYPE_35> ready;
    sc_out<READY_VAL_SIG_TYPE_35> valid;
    // Channel, error and data ports ST bus
    sc_out<sc_int<CHANNEL_BITS>> channel;
    sc_out<sc_int<ERROR_BITS>> error;
    sc_out<sc_int<DATA_BITS>> data;

    void write(const T &value) {
        //if (reset == SC_LOGIC_0) {
        if (!reset) {
            // Output sample data on negative edge of clock
            //while (ready == SC_LOGIC_0)
            while (!ready)
                wait(clock.posedge_event());
            wait(clock.posedge_event());
            data.write(value);
            channel.write(0); // Channel number
            error.write(0); // Error
            //valid.write(SC_LOGIC_1); // Signal valid new data
            valid.write(true); // Signal valid new data
            wait(clock.posedge_event());
            //valid.write(SC_LOGIC_0);
            valid.write(false);
        } else wait(clock.posedge_event());
    }

    InAdapter(sc_module_name name_)
            : sc_module(name_) {}

private:
    bool nb_write(const T &data) {
        SC_REPORT_FATAL("/InAdapter", "Called nb_write()");
        return false;
    }

    virtual int num_free() const {
        SC_REPORT_FATAL("/InAdapter", "Called num_free()");
        return 0;
    }

    virtual const sc_event &data_read_event() const {
        SC_REPORT_FATAL("/InAdapter", "Called data_read_event()");
        return *new sc_event;
    }
};

#endif //A1_INADAPTER_H
