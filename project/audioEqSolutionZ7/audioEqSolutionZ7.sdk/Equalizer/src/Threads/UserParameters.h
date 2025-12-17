/*
 * UserParameters.h
 *
 *  Created on: 18. aug. 2017
 *      Author: Kim Bjerge
 */

#ifndef SRC_USERPARAMETERS_H_
#define SRC_USERPARAMETERS_H_

#include "Mutex.h"
#include "MutexGuard.h"
using namespace AbstractOS;

class UserParameters
{
public:
	UserParameters() : mMutex("MutexUserParam") {
		mBypass = true;
		mMute = false;
		mEqOn = false;
	}

	bool isBypass() {
		MutexGuard guard(&mMutex);
		return mBypass;
	}
	void setBypass(bool on) {
		MutexGuard guard(&mMutex);
		mBypass = on;
	}
	bool isMuted() {
		MutexGuard guard(&mMutex);
		return mMute;
	}
	void setMute(bool on) {
		MutexGuard guard(&mMutex);
		mMute = on;
	}
	bool isEqOn() {
		MutexGuard guard(&mMutex);
		return mEqOn;
	}
	void setEqOn(bool on) {
		MutexGuard guard(&mMutex);
		mEqOn = on;
	}

private:
	Mutex mMutex;
	bool mBypass;
	bool mMute;
	bool mEqOn;
};



#endif /* SRC_USERPARAMETERS_H_ */
