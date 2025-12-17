/*
 * Mutex.h
 *
 *  Created on: 15 Dec 2025
 *      Author: marti
 */

#ifndef SRC_MUTEX_H_
#define SRC_MUTEX_H_
#include "FreeRTOS.h"
#include "semphr.h"
#include <string>
class Mutex {// TAKEN FROM THE AUDIOEQSOLUTIONZ7 Mutex.h and Mutex.cpp
public:
    Mutex() {
		Mutex("Mutex");
	}
	Mutex(std::string name) {
		mutexName = name;
		mutexHandle = xSemaphoreCreateMutex();
		//mutexHandle = xSemaphoreCreateCounting(1, 1);
	}
	virtual ~Mutex() {}
	virtual void Acquire(void) {
		xSemaphoreTake(mutexHandle, portMAX_DELAY);
	}
	virtual void Release(void) {
		xSemaphoreGive(mutexHandle);
	}
protected:
	std::string mutexName;
	SemaphoreHandle_t mutexHandle;
};


#endif /* SRC_MUTEX_H_ */
