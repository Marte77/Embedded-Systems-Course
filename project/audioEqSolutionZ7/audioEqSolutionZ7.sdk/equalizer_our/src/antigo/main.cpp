#include "UserThread.h"
#include "AudioThread.h"

int initEqualizerOur(XEqualizer *eq, int id) {
	XEqualizer_Config *config;
	config = XEqualizer_LookupConfig(id);
	int status = XEqualizer_CfgInitialize(eq, config);
	if (status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	XEqualizer_Initialize(eq, id);
	return status;
}

int main_no_rtos() {
	XEqualizer eqXLeft, eqXRight;
	int status = initEqualizerOur(&eqXLeft, XPAR_XEQUALIZER_0_DEVICE_ID);
	xil_printf("equalizer left init status: %d (Failed status: %d | Success status: %d)\r\n", status, XST_FAILURE, XST_SUCCESS);
	status = initEqualizerOur(&eqXRight, XPAR_XEQUALIZER_1_DEVICE_ID);
	xil_printf("equalizer right init status: %d (Failed status: %d | Success status: %d)\r\n", status, XST_FAILURE, XST_SUCCESS);

	EqualizerOur eqLeft(&eqXLeft), eqRight(&eqXRight);
	xil_printf("Initializing equalizer settings\r\n");
	EQSettings eqSettings;
	xil_printf("Initializing user thread\r\n");
	float coeffs[5][6] = {
				{1.00135159, -1.99992692, 0.998648345, 1.00013518, -1.99992692, 0.999864817},
				{1.00518036, -1.99892628, 0.994819641, 1.00051808, -1.99892628, 0.999481976},
				{1.02044261, -1.98321366, 0.979557455, 1.0020442, -1.98321366, 0.997955739},
				{1.08531046, -1.68390632, 0.914689541, 1.00853109, -1.68390632, 0.991468966},
				{1.14412177, 0.822573423, 0.855878234, 1.01441216, 0.822573423, 0.985587835},
		};
	while (XEqualizer_IsReady(&eqXLeft) == 0); // Polling ready register
	XEqualizer_Set_mode(&eqXLeft, 2);
	XEqualizer_Write_coeffs_Words(&eqXLeft, 0, (int*)coeffs, sizeof(float)*5*6);
	XEqualizer_Start(&eqXLeft);
	while (XEqualizer_IsReady(&eqXRight) == 0); // Polling ready register
	XEqualizer_Set_mode(&eqXRight, 2);
	XEqualizer_Write_coeffs_Words(&eqXRight, 0, (int*)coeffs, sizeof(float)*5*6);
	XEqualizer_Start(&eqXRight);

	xil_printf("Initializing audio thread\r\n");
	AudioThreadOurs a(&eqSettings, &eqLeft, &eqRight);
	//eqSettings.disableEQ();
	while (1)
		a.run();
}

int main_antigo(bool usertos)
{

	if (!usertos) {
		main_no_rtos();
		return 0;
	}
	xil_printf("BOASSSSSSSSSSSSSSSSSS %d\r\n",configSUPPORT_DYNAMIC_ALLOCATION);
	XEqualizer eqXLeft, eqXRight;
	int status = initEqualizerOur(&eqXLeft, XPAR_XEQUALIZER_0_DEVICE_ID);
	xil_printf("equalizer left init status: %d (Failed status: %d | Success status: %d)\r\n", status, XST_FAILURE, XST_SUCCESS);
	status = initEqualizerOur(&eqXRight, XPAR_XEQUALIZER_1_DEVICE_ID);
	xil_printf("equalizer right init status: %d (Failed status: %d | Success status: %d)\r\n", status, XST_FAILURE, XST_SUCCESS);

	EqualizerOur eqLeft(&eqXLeft), eqRight(&eqXRight);
	xil_printf("Initializing equalizer settings\r\n");
	EQSettings eqSettings;
	xil_printf("Initializing user thread\r\n");
	UserThread u(&eqSettings);

	xil_printf("EQStuff size: %d", sizeof(EQSettings) + sizeof(XEqualizer) + sizeof(XEqualizer));
	xil_printf("UserThread size: %d", sizeof(UserThread));
	xil_printf("AudioThread size: %d", sizeof(AudioThreadOurs));

	xil_printf("Initializing audio thread\r\n");
	AudioThreadOurs a(&eqSettings, &eqLeft, &eqRight);
	xil_printf("Starting task scheduler\r\n");
	vTaskStartScheduler();
	xil_printf("ERROR HAPPENED"); // this should only be executed if the previous call somehow fails to start
	return 0;
}

