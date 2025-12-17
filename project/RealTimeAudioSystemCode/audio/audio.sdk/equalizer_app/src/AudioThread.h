/*
 * AudioThread.h
 *
 *  Created on: 15 Dec 2025
 *      Author: marti
 */

#ifndef SRC_AUDIOTHREAD_H_
#define SRC_AUDIOTHREAD_H_
#include "EQSettings.h"
#include "AbstractThread.h"
#include "Equalizer.h"


#define AUDIO_BASE				XPAR_ZYBO_AUDIO_CTRL_0_BASEADDR
enum i2s_regs { // from profs code
	I2S_DATA_RX_L_REG				= 0x00 + AUDIO_BASE,
	I2S_DATA_RX_R_REG				= 0x04 + AUDIO_BASE,
	I2S_DATA_TX_L_REG      			= 0x08 + AUDIO_BASE,
	I2S_DATA_TX_R_REG         		= 0x0c + AUDIO_BASE,
	I2S_STATUS_REG          		= 0x10 + AUDIO_BASE,
};
class AudioThread;
class AudioThreadState {
protected:
	AudioThread* audio;
public:
	virtual ~AudioThreadState(){}
	void setContext(AudioThread *t) {
		this->audio = t;
	}
	virtual void updateGain(){}
	virtual void sendAudio(){}
};

class AudioThread : public AbstractThread {
	EQSettings *eqSettings;
	Equalizer *eqLeft, *eqRight;
	AudioThreadState *state;
public:
	EQSettings* getEqSettings();
	Equalizer* getLeft();
	Equalizer* getRight();
	AudioThread(EQSettings *eqSettings,Equalizer* eqLeft, Equalizer* eqRight);
	void transitionState(AudioThreadState *s);
	void updateGain();
	void readLeftAndReadAudio(unsigned long &sLeft, unsigned long &sRight); // taken from the profs code
	void run() override;
};



class SendAudioState : public AudioThreadState {
private:
	static SendAudioState* instance;
	SendAudioState(AudioThread *t) {
		this->audio = t;
	}
public:
	static SendAudioState* getInstance(AudioThread *ctx);
	void updateGain();
	void sendAudio();
};
class UpdateGainState : public AudioThreadState {
private:
	static UpdateGainState* instance;
	UpdateGainState(AudioThread *t) {
		this->audio = t;
	}
public:
	static UpdateGainState* getInstance(AudioThread *ctx);
	void sendAudio();
	void updateGain();
};


#endif /* SRC_AUDIOTHREAD_H_ */
