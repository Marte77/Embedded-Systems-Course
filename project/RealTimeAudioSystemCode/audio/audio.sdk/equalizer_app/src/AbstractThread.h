/*
 * AbstractThread.h
 *
 *  Created on: 15 Dec 2025
 *      Author: marti
 */

#ifndef SRC_ABSTRACTTHREAD_H_
#define SRC_ABSTRACTTHREAD_H_

#include "FreeRTOS.h"
#include "task.h"
#include "EQSettings.h"

class AbstractThread {
	EQSettings *eqSettings;
	TaskHandle_t handle; // taken from the AudioSolution i think
    static void threadMapper(void* p)
	{
        ((AbstractThread*)p)->run();
        return;
	}
public:
	AbstractThread(EQSettings *eqSettings, const char* name, int priority) : eqSettings(eqSettings) {
        xTaskCreate(threadMapper, 				/* The function that implements the task. */
				name, 	                        /* Text name for the task, provided to assist debugging only. */
				350,//configMINIMAL_STACK_SIZE  /*x3 because the EQSettings class uses 236 bytes*/ , 	    /* The stack allocated to the task. */
				this, 						    /* The task parameter is pointer to the thread class. */
				tskIDLE_PRIORITY + priority,	/* The task runs at the idle priority. */
				&handle );
	}
	virtual ~AbstractThread(){}
    virtual void run() {}
    void yield() { // taken from profs code
		taskYIELD();
	}
};

#endif /* SRC_ABSTRACTTHREAD_H_ */
