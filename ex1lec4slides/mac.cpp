//
// Created by Martinho Tavares Malhão on 03/09/2025.
//

#include "mac.h"

void MAC::add() {
    std::cout << name() << " called add " << a1 << " + " << a2 << std::endl;

    signal1 = a1 + a2;
}

void MAC::multiply() {
    std::cout << name() << " called multiply " << signal1 << " * " << b << std::endl;

    res = signal1 * b;
}