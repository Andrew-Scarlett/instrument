#include "test.h"
int test(int i, int(*call_back)(int a, int b))
{
	int aa;
	aa = i * i;
	call_back(i, aa);
	return 0;
}