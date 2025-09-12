#ifndef SIMPLE_PROCESS_EX_H
#define SIMPLE_PROCESS_EX_H
#include <systemc.h>

SC_MODULE(simple_process_ex) { // same as `struct simple_proccess_ex : sc_module` or `class simple_proccess_ex : sc_module`
    // keep in mind that if the module is defined as a class, the constructor (SC_CTOR) must be set as public
  sc_fifo<int> fifo1;

  SC_CTOR(simple_process_ex) {
    SC_THREAD(meu_processo_threaded);
    SC_THREAD(meu_processo_threaded_recetor);
    SC_METHOD(meu_method_novo);
    //dont_initialize();
  }
  void meu_processo_threaded(void);
  void meu_processo_threaded_recetor(void);
  void meu_method_novo(void);
};

#endif
