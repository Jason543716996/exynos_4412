#include <led.h>

int main(void)
{
	int val;
#define MPLL_CON0 0x10040108
	val = ioread32(MPLL_CON0);

	printf("M: %d, P:%d, S: %d\n", 
			(val>>16)&0x3ff, (val>>8)&0x3f, val&0x7);

	return 0;
}
