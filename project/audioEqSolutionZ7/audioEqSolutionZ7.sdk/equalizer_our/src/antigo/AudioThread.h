/*
 * AudioThread.h
 *
 *  Created on: 15 Dec 2025
 *      Author: marti
 */

#ifndef SRC_AUDIOTHREADOURS_H_
#define SRC_AUDIOTHREADOURS_H_
#include "EQSettings.h"
#include "AbstractThread.h"
#include "EqualizerOur.h"


#define AUDIO_BASE				XPAR_ZYBO_AUDIO_CTRL_0_BASEADDR
enum i2s_regs { // from profs code
	I2S_DATA_RX_L_REG				= 0x00 + AUDIO_BASE,
	I2S_DATA_RX_R_REG				= 0x04 + AUDIO_BASE,
	I2S_DATA_TX_L_REG      			= 0x08 + AUDIO_BASE,
	I2S_DATA_TX_R_REG         		= 0x0c + AUDIO_BASE,
	I2S_STATUS_REG          		= 0x10 + AUDIO_BASE,
};
class AudioThreadOurs;
class AudioThreadState {
protected:
	AudioThreadOurs* audio;
public:
	virtual ~AudioThreadState(){}
	void setContext(AudioThreadOurs *t) {
		this->audio = t;
	}
	virtual void updateGain(){}
	virtual void sendAudio(){}
};

class AudioThreadOurs : public AbstractThread {
	EQSettings *eqSettings;
	EqualizerOur *eqLeft, *eqRight;
	AudioThreadState *state;
public:
	EQSettings* getEqSettings();
	EqualizerOur* getLeft();
	EqualizerOur* getRight();
	AudioThreadOurs(EQSettings *eqSettings,EqualizerOur* eqLeft, EqualizerOur* eqRight);
	void transitionState(AudioThreadState *s);
	void updateGain();
	void readLeftAndReadAudio(unsigned long &sLeft, unsigned long &sRight); // taken from the profs code
	void run() override;
};



class SendAudioState : public AudioThreadState {
private:
	static SendAudioState* instance;
	SendAudioState(AudioThreadOurs *t) {
		this->audio = t;
	}
public:
	static SendAudioState* getInstance(AudioThreadOurs *ctx);
	void updateGain();
	void sendAudio();
};
class UpdateGainState : public AudioThreadState {
private:
	static UpdateGainState* instance;
	UpdateGainState(AudioThreadOurs *t) {
		this->audio = t;
	}
public:
	static UpdateGainState* getInstance(AudioThreadOurs *ctx);
	void sendAudio();
	void updateGain();
};


#endif /* SRC_AUDIOTHREADOURS_H_ */
