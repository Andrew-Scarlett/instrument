#include "CConnect.h"

//test function
int CConnect(ViConstRsrc &addr) {
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

bool CConnect(ViConstRsrc &addr, ViSession &defaultRM, ViSession &vi) {
	if (viOpenDefaultRM(&defaultRM) >= VI_SUCCESS) {
		if (viOpen(defaultRM, addr, VI_NULL, VI_NULL, &vi) >= VI_SUCCESS) {
			return true;
		}
		else
		{
			return false;
		}
	}
	else {
		return false;
	}
	return false;
}
