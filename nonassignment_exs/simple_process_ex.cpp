#include "simple_process_ex.h"

void simple_process_ex::meu_processo_threaded(void) {
    std::cout << "criei o thread e chamo me " << name() << std::endl;
    std::cout << "criei o thread e chamo me " << name() << std::endl;
    for (int i = 0; i < 10; ++i) {
        fifo1.write(i);
        std::cout << "Thread1: sent the int value: " << i << std::endl;
        wait(10, SC_MS);
    }

}

void simple_process_ex::meu_processo_threaded_recetor(void) {
    int i = -1;
    while (i < 10) {
        i = fifo1.read();
        std::cout << "Thread2: received the int value: " << i << std::endl;
    }
}
void simple_process_ex::meu_method_novo(void) {
    std::cout << "criei o meu metodo novo" << std::endl;
    return;
}