#pragma once
#include <stdio.h>
#include "visa.h"

#pragma comment(lib,"../Debug/visa32.lib")

__declspec(dllexport) int CConnect(ViConstRsrc &addr);//test
__declspec(dllexport) bool CConnect(ViConstRsrc &addr,ViSession &defaultRM, ViSession &vi);