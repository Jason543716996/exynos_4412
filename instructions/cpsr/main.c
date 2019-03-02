#include <lib.h>

void main(void)
{
	int cpsr, cpsr_r;

	__asm__ __volatile__(
		"nop\n"
		/*mrs: 将cpsr寄存器的值读出付给一般寄存器*/
		"mrs %[cpsr], cpsr\n"
		"orr r0, %[cpsr], #(0xf << 28)\n"

		/*msr: 将一般寄存器的值写入cpsr*/
		"msr cpsr, r0\n"
		"mrs %[cpsr_r], cpsr\n"
		"nop\n"

		:[cpsr]"=&r"(cpsr),[cpsr_r]"=&r"(cpsr_r)
	);

	printf("cpsr = %#x\n", cpsr);
	printf("cpsr_r = %#x\n", cpsr_r);
}

/*
 	cpsr = 0x600001d3
	cpsr_r = 0xf00001d3

	0xd3 = 0b 1101 0011 -> 10011
 */
