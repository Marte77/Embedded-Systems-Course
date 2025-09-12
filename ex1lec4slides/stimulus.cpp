//
// Created by Martinho Tavares Malhão on 03/09/2025.
//

#include "stimulus.h"

void Stimmer::generate_values() {
    std::cout << name() << " called generate" << std::endl;
    wait(); // only because its a thread
    a1 = a2 = 100;
    b = 2;
    wait(); // only because its a thread
    a1 = a2 = 200;
    b = 23;
    wait(); // only because its a thread
    a1 = a2 = 14;
    b = 3;
    sc_stop();
}