#include "CConnect.h"

bool CConnect(ViConstRsrc &addr) {
	ViSession defaultRM, vi;
	char buf[256] = { 0 };
	/* Open session to LAN device at address  */
	viOpenDefaultRM(&defaultRM);
	viOpen(defaultRM, addr, VI_NULL, VI_NULL, &vi);
	/* Send an *IDN? string to the device */
	viPrintf(vi, "*IDN?\n");
	/* Read results */
	viScanf(vi, "%t", buf);
	/* Print results */
	printf("%s\n", buf);
	/* Close session */
	viClose(vi);
	viClose(defaultRM);
	return 0;
}
