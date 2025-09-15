//
// Created by Martinho Tavares Malhão on 08/09/2025.
//

#ifndef A1_35_CONF_H
#define A1_35_CONF_H
#define CHANNEL_BITS 4 // Number of channel wires
#define ERROR_BITS 2 // Number of error wires
#define DATA_BITS 16 // Number of data wires
#define MAX_CHANNEL 2 // Maximum number of channels actual used
#define CLK_PERIODE 20 // ns

#define DATA_SIG_TYPE_35 sc_int<DATA_BITS>
//#define DATA_SIG_TYPE int

#define ERROR_SIG_TYPE_35 sc_int<ERROR_BITS>
//#define ERROR_SIG_TYPE int

//#define READY_VAL_SIG_TYPE
//#define READY_VAL_SIG_TYPE_35 sc_logic
#define READY_VAL_SIG_TYPE_35 bool

#define CHANNEL_SIG_TYPE_35 sc_int<CHANNEL_BITS>

#endif //A1_35_CONF_H
