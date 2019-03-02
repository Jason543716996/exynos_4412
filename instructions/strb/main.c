#include <lib.h>

/*
 	ldr: load a word value from memory into register.
	str: store a word value from register into memory.
	strb: store a byte value from register into memory.
 */

void main(void)
{
	int endian; //0x95273856;

	__asm__ __volatile__(
		"nop\n"
		"mov r0, %[add]\n"
		"mov r1, #0x56\n"
		"strb r1, [r0], #1\n"
		"mov r1, #0x38\n"
		"strb r1, [r0], #1\n"
		"mov r1, #0x27\n"
		"strb r1, [r0], #1\n"
		"mov r1, #0x95\n"
		"strb r1, [r0], #1\n"
		"nop\n"

		:
		:[add]"r"(&endian)
		:"r0","r1"
	);

	printf("endian = %#x\n", endian);
}

/*
 	cpsr = 0x600001d3
	cpsr_r = 0xf00001d3

	0xd3 = 0b 1101 0011 -> 10011
 */
