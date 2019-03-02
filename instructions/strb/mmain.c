#include <lib.h>

/*
 	ldr: load a word value from memory into register.
	str: store a word value from register into memory.
	strh: store a half word value from register into memory.
	strb: store a byte value from register into memory.
 */

void main(void)
{
	int array[2];  //[0] = 0x95273856, [1] = 0x77889911; 

	__asm__ __volatile__(
		"nop\n"
		"mov r0, %[array]\n"

		"ldr r1, =0x3856\n"
		"strh r1, [r0], #2\n"

		"ldr r1, =0x9527\n"
		"strh r1, [r0], #2\n"

		"ldr r1, =0x9911\n"
		"strh r1, [r0], #2\n"

		"ldr r1, =0x7788\n"
		"strh r1, [r0]\n"
	
		"nop\n"

		:
		:[array]"r"(array)
		:"r0","r1"
	);

	printf("array[0] = %#x\n", array[0]);
	printf("array[1] = %#x\n", array[1]);
}

/*
 	cpsr = 0x600001d3
	cpsr_r = 0xf00001d3

	0xd3 = 0b 1101 0011 -> 10011
 */
