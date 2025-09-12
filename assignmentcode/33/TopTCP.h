//
// Created by Martinho Tavares Malhão on 07/09/2025.
//

#ifndef A1_TOPTCP_H
#define A1_TOPTCP_H
#include "systemc.h"
#include "ModuleTCP.h"
SC_MODULE(TopTCP) {
    sc_fifo<TCPHeader> fifo1, fifo2;
    TCPProducer *tcpProducer = new TCPProducer("TCP_Producer");
    TCPConsumer *tcpConsumer1 = new TCPConsumer("TCP_Consumer1");
    TCPConsumer *tcpConsumer2 = new TCPConsumer("TCP_Consumer2");

    SC_CTOR(TopTCP) {
        tcpProducer->fifo(fifo1);
        tcpProducer->fifo(fifo2);
        tcpConsumer1->fifo(fifo1);
        tcpConsumer2->fifo(fifo2);
    }
};


#endif //A1_TOPTCP_H
