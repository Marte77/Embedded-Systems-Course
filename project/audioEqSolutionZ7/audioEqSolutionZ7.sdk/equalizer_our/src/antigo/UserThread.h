/*
 * UserThread.h
 *
 *  Created on: 15 Dec 2025
 *      Author: marti
 */

#ifndef SRC_USERTHREAD_H_
#define SRC_USERTHREAD_H_
#include "AbstractThread.h"
#include "EQSettings.h"
#include "xil_printf.h"
#include "xparameters.h"

class UserThread : public AbstractThread {
	EQSettings *eqSettings;
public:
	UserThread(EQSettings *eqSettings) : AbstractThread(eqSettings, "User",1,16+252) {}
	void run() override {
		xil_printf("UserThread::run()\r\n");
		char value_read = -1;
		while (1) {
restart_loop:
			xil_printf("Choose what to do: \r\n\t1- Activate EQ\r\n\t2- Dectivate EQ\r\n\t3- Change band on frequency\r\n");
			value_read = inbyte();
			xil_printf("%c\r\n", value_read);
			switch (value_read) {
				case '1': 
					if (eqSettings->eqState() == false){
						eqSettings->enableEQ();
						xil_printf("Succesfuly enabled the EQ\r\n");
					} else xil_printf("Already enabled\r\n");
					break;
				case '2': 
					if (eqSettings->eqState() == false){
						eqSettings->disableEQ();
						xil_printf("Succesfuly disabled the EQ\r\n");
					} else xil_printf("Already disabled\r\n");
					break;
				case '3': {
				// this whole mess of switch statements could be way better written but its 2 am and i dont have internet so i dont want to do it
					if (eqSettings->eqState() == false) xil_printf("Remember to enable the EQ afterwards\r\n");
					xil_printf("Select the frequency to change:\r\n\t");
					eqSettings->frequenciesAsString();
					value_read = inbyte();
					int freq = 0;
					switch (value_read) {
						case '1': // 60 Hz
							freq = 60;
						break;
						case '2': // 230 Hz
							freq = 230;
						break;
						case '3': // 910 Hz
							freq = 910;
						break;
						case '4': // 4000 Hz
							freq = 4000;
						break;
						case '5': // 14000 Hz
							freq = 14000;
						break;
						default:
						xil_printf("Unknown option \r\n");
						goto restart_loop;
					}
					xil_printf("Selected freq: %d Hz", freq);
					xil_printf("Select if gain is negative: 1- negative gain 2 - positive gain\r\n");
					value_read = inbyte();
					int gain = 1;
					switch (value_read) {
						case '1': // negative
							gain = -gain;
						break;
						case '2':
						break;
						default:
						xil_printf("Unknown option. gain is positive\r\n");
						break;
					}
					xil_printf("Select gain value: Type 0 to 6\r\n");
					value_read = inbyte();
					switch (value_read) {
						case '0':
						gain = gain * 0;
						break;
						case '1':
						break;
						case '2':
						gain = gain * 2;
						break;
						case '3':
						gain = gain * 3;
						break;
						case '4':
						gain = gain * 4;
						break;
						case '5':
						gain = gain * 5;
						break;
						case '6':
						gain = gain * 6;
						break;
						default:
						xil_printf("Unknown option \r\n");
						goto restart_loop;
					}
					eqSettings->setGain(freq, gain);}
					break;
				default:
					xil_printf("Unknown option \r\n");
					goto restart_loop;
			}
		}
	}
};




#endif /* SRC_USERTHREAD_H_ */
