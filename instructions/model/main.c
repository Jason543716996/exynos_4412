#include <lib.h>

void main(void)
{
	__asm__ __volatile__(
		"nop\n"
		"mov r0, #0xff\n" 
		"nop\n"
	);
}
