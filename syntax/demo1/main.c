#include <lib.h>

void main(void)
{
	__asm__(
		"nop\n"
		"nop"
	);

	asm(
		"nop\n"
		"nop"
	);

	__asm__ __volatile__(
		"nop\n"
		"nop"
	);

	asm volatile(
		"nop\n"
		"nop"
	);
}
