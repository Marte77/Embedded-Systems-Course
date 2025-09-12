/*
 * mac.cpp
 *
 *  Created on: Apr 30, 2013
 *      Author: kbe
 */

#include "mac.h"

void Mac::multiply(){
    std::cout << name() << " called multiply" << std::endl;
	p = a * b;
}

void Mac::addition(){
    std::cout << name() << " called addition" << std::endl;
	f = c + p;
}
