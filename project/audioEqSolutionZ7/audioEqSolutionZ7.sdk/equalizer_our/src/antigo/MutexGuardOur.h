/*
 * Mutex.h
 *
 *  Created on: 15 Dec 2025
 *      Author: marti
 */

#ifndef SRC_MUTEXGUARDOUR_H_
#define SRC_MUTEXGUARDOUR_H_
#include "FreeRTOS.h"
#include "semphr.h"
#include <string>

#include "MutexOur.h"
class MutexGuardOur { // TAKEN FROM THE AUDIOEQSOLUTIONZ7 MutexGuard.h
public:
	MutexGuardOur(MutexOur *mutex) {
		mMutex = mutex;
		mMutex->Acquire();
		mOwner = true;
	}
	~MutexGuardOur() {
		if (mOwner)
			mMutex->Release();
	}
private:
	MutexOur *mMutex; // Mutex wrapper facade
	bool mOwner;
	// disallow copying and assignment
	MutexGuardOur(const MutexGuardOur &);
	void operator= (const MutexGuardOur &);
};



#endif /* SRC_MUTEXGUARDOUR_H_ */
