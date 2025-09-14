//
// Created by Martinho Tavares Malhão on 07/09/2025.
//

#ifndef A1_MODULETCP_H
#define A1_MODULETCP_H
#include "systemc.h"
#include <random>
#include <ostream>

#define PACKET_SIZE 512
#define DATA_SIZE (PACKET_SIZE-20)
struct TCPHeader
{
    sc_uint<16> SourcePort;
    sc_uint<16> DestinationPort;
    sc_uint<32> SequenceNumber;
    sc_uint<32> Acknowledge;
    sc_uint<16> StatusBits;
    sc_uint<16> WindowSize;
    sc_uint<16> Checksum;
    sc_uint<16> UrgentPointer;
    char Data[DATA_SIZE];

    friend ostream &operator<<(ostream &os, const TCPHeader &header) {
        os << "SourcePort: " << header.SourcePort << " DestinationPort: " << header.DestinationPort
           << " SequenceNumber: " << header.SequenceNumber << " Acknowledge: " << header.Acknowledge << " StatusBits: "
           << header.StatusBits << " WindowSize: " << header.WindowSize << " Checksum: " << header.Checksum
           << " UrgentPointer: " << header.UrgentPointer << " Data: " << header.Data;
        return os;
    }

    bool operator==(const TCPHeader &rhs) const {
        return SourcePort == rhs.SourcePort &&
               DestinationPort == rhs.DestinationPort &&
               SequenceNumber == rhs.SequenceNumber &&
               Acknowledge == rhs.Acknowledge &&
               StatusBits == rhs.StatusBits &&
               WindowSize == rhs.WindowSize &&
               Checksum == rhs.Checksum &&
               UrgentPointer == rhs.UrgentPointer &&
               Data == rhs.Data;
    }

    bool operator!=(const TCPHeader &rhs) const {
        return !(rhs == *this);
    }
};

SC_MODULE(TCPProducer) {

    sc_port<sc_fifo_out_if<TCPHeader>,0> fifo; // 0 is what allows us to have an arbitrary amount of ports, otherwise we'd be limited by the number specified

    SC_CTOR(TCPProducer) {
        SC_THREAD(tcp_send);
    }
    TCPHeader generate_tcp(int seq_num) {
        return {
            .SourcePort = 9876,
            .DestinationPort = 1234,
            .SequenceNumber = seq_num,
            .Acknowledge = 0,
            .StatusBits = 0,
            .WindowSize = 0,
            .Checksum = 0,
            .UrgentPointer = 0,
            .Data = "OLA TUDO BEM\0"
        };
    }
    void tcp_send() {
        // rand gen from https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution.html
        std::random_device rd;  // a seed source for the random number engine
        std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> distrib(2, 10);

        int counter = 0;
        while (true) {
            auto waittime = distrib(gen); // 2-10
            counter++;
            auto tcp = generate_tcp(counter);
            for (int i = 0; i < fifo.size(); i++) {
                // if we invert the for to for(int i = fifo.size(); i > 0; i--)
                // we will see that the last consumer in the original code will turn into the first consumer
                fifo[i]->write(tcp);
                //std::cout << name() << "::Wrote to fifo " << i << std::endl;
            }
            //fifo.write(counter);
            wait(waittime, SC_MS);
        }
    }
};


SC_MODULE(TCPConsumer) {
    sc_port<sc_fifo_in_if<TCPHeader>> fifo;
    SC_CTOR(TCPConsumer) {
        SC_THREAD(tcp_recv);
    }

    void tcp_recv() {
        while (true) {
            auto tcpHeader = fifo->read();
            std::cout << name() <<"::Sequence number received: " << tcpHeader.SequenceNumber << ". Simulation time: " << sc_time_stamp() << std::endl;
        }
    }
};

#endif //A1_MODULETCP_H
