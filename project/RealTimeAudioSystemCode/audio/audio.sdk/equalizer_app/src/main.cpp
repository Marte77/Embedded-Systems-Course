#include "UserThread.h"
#include "AudioThread.h"

int initEqualizer(XEqualizer *eq, int id) {
	XEqualizer_Config *config;
	config = XEqualizer_LookupConfig(id);
	int status = XEqualizer_CfgInitialize(eq, config);
	if (status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	XEqualizer_Initialize(eq, id);
	return status;
}
int main_no_rtos();

int main()
{
	if (true) {
		main_no_rtos();
		return 0;
	}
	xil_printf("BOASSSSSSSSSSSSSSSSSS %d\r\n",configSUPPORT_DYNAMIC_ALLOCATION);
	XEqualizer eqXLeft, eqXRight;
	int status = initEqualizer(&eqXLeft, XPAR_EQ_LEFT_DEVICE_ID);
	xil_printf("equalizer left init status: %d (Failed status: %d | Success status: %d)\r\n", status, XST_FAILURE, XST_SUCCESS);
	status = initEqualizer(&eqXRight, XPAR_EQ_RIGHT_DEVICE_ID);
	xil_printf("equalizer right init status: %d (Failed status: %d | Success status: %d)\r\n", status, XST_FAILURE, XST_SUCCESS);

	Equalizer eqLeft(&eqXLeft), eqRight(&eqXRight);
	xil_printf("Initializing equalizer settings\r\n");
	EQSettings eqSettings;
	xil_printf("Initializing user thread\r\n");
	UserThread u(&eqSettings);

	xil_printf("EQStuff size: %d", sizeof(EQSettings) + sizeof(XEqualizer) + sizeof(XEqualizer));
	xil_printf("UserThread size: %d", sizeof(UserThread));
	xil_printf("AudioThread size: %d", sizeof(AudioThread));

	xil_printf("Initializing audio thread\r\n");
	AudioThread a(&eqSettings, &eqLeft, &eqRight);
	xil_printf("Starting task scheduler\r\n");
	vTaskStartScheduler();
	xil_printf("ERROR HAPPENED"); // this should only be executed if the previous call somehow fails to start
	return 0;
}

int main_no_rtos() {
	XEqualizer eqXLeft, eqXRight;
	int status = initEqualizer(&eqXLeft, XPAR_XEQUALIZER_0_DEVICE_ID);
	xil_printf("equalizer left init status: %d (Failed status: %d | Success status: %d)\r\n", status, XST_FAILURE, XST_SUCCESS);
	status = initEqualizer(&eqXRight, XPAR_XEQUALIZER_1_DEVICE_ID);
	xil_printf("equalizer right init status: %d (Failed status: %d | Success status: %d)\r\n", status, XST_FAILURE, XST_SUCCESS);

	Equalizer eqLeft(&eqXLeft), eqRight(&eqXRight);
	xil_printf("Initializing equalizer settings\r\n");
	EQSettings eqSettings;
	xil_printf("Initializing user thread\r\n");

	xil_printf("EQStuff size: %d", sizeof(EQSettings) + sizeof(XEqualizer) + sizeof(XEqualizer));
	xil_printf("UserThread size: %d", sizeof(UserThread));
	xil_printf("AudioThread size: %d", sizeof(AudioThread));
	//eqSettings.setGain(6, 60);
	//eqSettings.setGain(6, 230);
	
	xil_printf("Initializing audio thread\r\n");
	AudioThread a(&eqSettings, &eqLeft, &eqRight);
	eqSettings.disableEQ();
	while (1)
		a.run();
}
