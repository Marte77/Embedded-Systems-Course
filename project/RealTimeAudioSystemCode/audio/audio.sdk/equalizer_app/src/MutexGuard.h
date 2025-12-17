/*
 * Mutex.h
 *
 *  Created on: 15 Dec 2025
 *      Author: marti
 */

#ifndef SRC_MUTEXGUARD_H_
#define SRC_MUTEXGUARD_H_
#include "FreeRTOS.h"
#include "semphr.h"
#include <string>
#include "Mutex.h"
class MutexGuard { // TAKEN FROM THE AUDIOEQSOLUTIONZ7 MutexGuard.h
public:
	MutexGuard(Mutex *mutex) {
		mMutex = mutex;
		mMutex->Acquire();
		mOwner = true;
	}
	~MutexGuard() {
		if (mOwner)
			mMutex->Release();
	}
private:
	Mutex *mMutex; // Mutex wrapper facade
	bool mOwner;
	// disallow copying and assignment
	MutexGuard(const MutexGuard &);
	void operator= (const MutexGuard &);
};



#endif /* SRC_MUTEXGUARD_H_ */