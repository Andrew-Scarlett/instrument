#pragma once
#include <stdio.h>
#include "visa.h"
#include "CConnect.h"

#pragma comment(lib,"../Debug/visa32.lib")

#ifdef INSTRUMENT_EXPORTS
#define INSTRUMENT_API __declspec(dllexport)
#else
#define INSTRUMENT_API __declspec(dllimport)
#endif

class INSTRUMENT_API CAWG7082C {

public:
	CAWG7082C(ViConstRsrc addr);
	~CAWG7082C();
	 void test();

private:
	ViConstRsrc addr;
	ViSession defaultRM, vi;

};

extern "C" INSTRUMENT_API CAWG7082C* CreateAwgObj(ViConstRsrc addr);
extern "C" INSTRUMENT_API void DestroyAwgObj(CAWG7082C* CAWG);