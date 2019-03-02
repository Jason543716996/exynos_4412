#include <lib.h>

/*
 	ldr: load a word value from memory into register.
	str: store a word value from register into memory.
 */

void main(void)
{
	int array[3] = { 0 };

	__asm__ __volatile__(
		"nop\n"
		"mov r0, %[array]\n"
		"mov r1, #95\n"
		"str r1, [r0], #4\n"   ////// *r0  =  r1;
		"mov r1, #83\n"
		"str r1, [r0], #4\n"   ////// *r0  =  r1;
		"mov r1, #38\n"
		"str r1, [r0]\n"   ////// *r0  =  r1;
		"nop\n"
		:
		:[array]"r"(array)
		:"r0","r1"
	);

	int i;
	for (i = 0; i < 3; i++) {
		printf("array[%d] = %d\n", i, array[i]);
	}
}

/*
 	cpsr = 0x600001d3
	cpsr_r = 0xf00001d3

	0xd3 = 0b 1101 0011 -> 10011
 */
