//
// Created by Martinho Tavares Malhão on 03/09/2025.
//

#ifndef A1_TOP_H
#define A1_TOP_H
#include "systemc.h"
#include "monitor.h"
#include "stimulus.h"
#include "mac.h"
#include "visualize.h"

SC_MODULE(Top) {
    sc_signal<int> siga, sigb, sigc, sigres;
    sc_clock clocker;
    Monitor *monitor;
    Stimmer *stimmer;
    MAC *mac;
    sc_trace_file *tf;
    SC_CTOR(Top):clocker("clocker"){
        monitor = new Monitor("Monitor");
        stimmer = new Stimmer("Stimmer");
        mac = new MAC("mac");
        stimmer->a1(siga);
        stimmer->a2(sigb);
        stimmer->b(sigc);
        stimmer->clock(clocker);

        mac->a1(siga);
        mac->a2(sigb);
        mac->b(sigc);
        mac->res(sigres);

        monitor->macOut(mac->res);
        monitor->clk(stimmer->clock);


        // Create VCD wave form file used for signal timing analysis
        tf = sc_create_vcd_trace_file("WaveForm");
        tf->set_time_unit(1, SC_NS);
        sc_trace(tf, siga, "a");
        sc_trace(tf, sigb, "b");
        sc_trace(tf, sigc, "c");
        sc_trace(tf, sigres, "res");
        sc_trace(tf, clocker, "clock");

    }
};


#endif //A1_TOP_H
