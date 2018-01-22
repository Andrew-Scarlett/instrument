#include <stdlib.h>
#include <stdio.h>
#include "../instrument/visa.h"
#include "../instrument/CConnect.h"
#include "../instrument/CAWG7082C.h"

#pragma comment(lib,"../Debug/instrument.lib")


int main() {

	ViConstRsrc addr = "TCPIP0::222.195.68.216::inst0::INSTR";
	//CConnect(addr);
	CAWG7082C* awg = CreateAwgObj(addr);
	awg->test();
	return 0;
}