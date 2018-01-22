#include "CAWG7082C.h"

CAWG7082C::CAWG7082C(ViConstRsrc addr) {
	this->addr = addr;
	char buf[256] = { 0 };
	if (!CConnect(this->addr,this->defaultRM, this->vi)) {
		this->defaultRM = 0;
		this->vi = 0;
	}
}

CAWG7082C::~CAWG7082C() {
}

INSTRUMENT_API CAWG7082C* CreateAwgObj(ViConstRsrc addr) {
	return new CAWG7082C(addr);
}

INSTRUMENT_API void DestroyAwgObj(CAWG7082C* CAWG) {
	CAWG->~CAWG7082C();
}

void CAWG7082C::test() {
	char buf[256] = { 0 };
	/* Send an *IDN? string to the device */
	viPrintf(vi, "*IDN?\n");
	/* Read results */
	viScanf(vi, "%t", buf);
	/* Print results */
	printf("%s\n", buf);
	/* Close session */
	viClose(vi);
	viClose(defaultRM);
}