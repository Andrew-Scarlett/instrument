#include "CConnect.h"
int CConnect() {
	ViSession defaultRM, vi;
	char buf[256] = { 0 };
	/* Open session to LAN device at address  */
	viOpenDefaultRM(&defaultRM);
	viOpen(defaultRM, "TCPIP0::222.195.68.216::inst0::INSTR", VI_NULL, VI_NULL, &vi);
	/* Send an *IDN? string to the device */
	viPrintf(vi, "*IDN?\n");
	/* Read results */
	viScanf(vi, "%t", buf);
	/* Print results */
	printf("Instrument identification string: Building a VISA Application in Windows 2 Agilent VISA User¡¯s Guide 17 %s\n", buf);
		/* Close session */
	viClose(vi);
	viClose(defaultRM);
	return 0;
}