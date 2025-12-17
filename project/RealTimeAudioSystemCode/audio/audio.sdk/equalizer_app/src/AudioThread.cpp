#include "AudioThread.h"
// AudioThread
#pragma region AudioThread
EQSettings* AudioThread::getEqSettings() {
	return eqSettings;
}
Equalizer* AudioThread::getLeft() {
	return eqLeft;
}
Equalizer* AudioThread::getRight() {
	return eqRight;
}
AudioThread::AudioThread(EQSettings *eqSettings,Equalizer* eqLeft, Equalizer* eqRight) :
	AbstractThread(eqSettings, "Audio",0/*less priority than UserThread*/, 28+252), eqLeft(eqLeft), eqRight(eqRight) {}
void AudioThread::transitionState(AudioThreadState *s) {
	this->state = s;
}
void AudioThread::updateGain() {
	eqLeft->updateGain(eqSettings->getCoeffs());
	eqRight->updateGain(eqSettings->getCoeffs());
	eqSettings->setGainUpdated(false);
}
void AudioThread::readLeftAndReadAudio(unsigned long &sLeft, unsigned long &sRight) { // taken from the profs code
	sLeft = Xil_In32(I2S_DATA_RX_L_REG);
	sRight = Xil_In32(I2S_DATA_RX_R_REG);
}
void AudioThread::run() {
	//xil_printf("AudioThread::run()\r\n");
	while (1) {
		if (eqSettings->wasGainUpdated()) {
			transitionState(UpdateGainState::getInstance(this));
			state->updateGain();
			transitionState(SendAudioState::getInstance(this));
		}
		state->sendAudio();
		yield();
	}
}
#pragma endregion
SendAudioState* SendAudioState::instance = nullptr;
UpdateGainState* UpdateGainState::instance = nullptr;
#pragma region SendAudioState
// SendAudioState
SendAudioState* SendAudioState::getInstance(AudioThread *ctx) {
	if (!instance)
		instance = new SendAudioState(ctx);
	return instance;
}
void SendAudioState::updateGain() {
	xil_printf("ILLEGAL STATE CALL. IM SENDAUDIOSTATE AND UPDATEGAIN() WAS CALLED");
}
void SendAudioState::sendAudio() {
	unsigned long audioLeft, audioRight;
	Equalizer *left = audio->getLeft(), *right = audio->getRight();
	bool isSampleReady = false;
	while (isSampleReady == false) {
		if (Xil_In32(I2S_STATUS_REG) != 0) {
			isSampleReady = true;
			Xil_Out32(I2S_STATUS_REG, 0x00000001); //Clear data rdy bit
		}
		audio->yield();
	}
	audio->readLeftAndReadAudio(audioLeft, audioRight);
	if (audio->getEqSettings()->eqState()) {
		audioLeft = left->getAudioAltered(audioLeft);
		audioRight = right->getAudioAltered(audioRight);
	}
	Xil_Out32(I2S_DATA_TX_L_REG, audioLeft);
	Xil_Out32(I2S_DATA_TX_R_REG, audioRight);
}
#pragma endregion

#pragma region UpdateGainState
UpdateGainState* UpdateGainState::getInstance(AudioThread *ctx) {
	if (!instance)
		instance = new UpdateGainState(ctx);
	return instance;
}
void UpdateGainState::sendAudio() {
	xil_printf("ILLEGAL STATE CALL. IM UPDATEGAINSTATE AND SENDAUDIO() WAS CALLED");
}
void UpdateGainState::updateGain() {
	audio->updateGain();
	audio->transitionState(SendAudioState::getInstance(audio));
}
#pragma endregion
