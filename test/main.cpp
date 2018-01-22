#include <stdlib.h>
#include <stdio.h>
#include "../instrument/visa.h"
#include "../instrument/CConnect.h"

#pragma comment(lib,"../Debug/instrument.lib")


int main() {

	ViConstRsrc addr = "TCPIP0::222.195.68.216::inst0::INSTR";
	CConnect(addr);
	return 0;
}