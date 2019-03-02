#include <lib.h>

void main(void)
{
	//&, |, ~, ^
	int and, orr, eor, bic;

	__asm__ __volatile__(
		"nop\n"
		"mov r0, #0x96\n"
		"and %[and], r0, #0x69\n"
		"orr %[orr], r0, #0x69\n"
		"eor %[eor], r0, #0x69\n"
		"bic %[bic], r0, #(1 << 7)\n"
		"nop"

		:[and]"=&r"(and),[orr]"=&r"(orr),[eor]"=&r"(eor), [bic]"=&r"(bic)
		:
		:"r0","r1"
	);

	printf("and: %#x\n", and);
	printf("orr: %#x\n", orr);
	printf("eor: %#x\n", eor);
	printf("bic: %#x\n", bic);
}
