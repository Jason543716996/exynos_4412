#include <lib.h>

/*
 	ldr: load a word value from memory into register.
 */

void main(void)
{
	int array[] = { 11, 22, 33 };
	int a0, a1, a2;
#if 0
	__asm__ __volatile__(
		"nop\n"
		"mov r0, %[array]\n"
		"ldr %[a0], [r0], #4\n"
		"ldr %[a1], [r0], #4\n"
		"ldr %[a2], [r0]\n"
		"nop\n"
		:[a0]"=&r"(a0),[a1]"=&r"(a1),[a2]"=&r"(a2)
		:[array]"r"(array)
	);
#endif
#if 0
	__asm__ __volatile__(
		"nop\n"
		"mov r0, %[array]\n"
		"ldr %[a0], [r0]\n"
		"ldr %[a1], [r0, #4]\n"
		"ldr %[a2], [r0, #8]\n"
		"nop\n"
		:[a0]"=&r"(a0),[a1]"=&r"(a1),[a2]"=&r"(a2)
		:[array]"r"(array)
	);
#endif
	__asm__ __volatile__(
		"nop\n"
		"mov r0, %[array]\n"
		"ldr %[a0], [r0]\n"
		"ldr %[a1], [r0, #4]!\n" 
		"ldr %[a2], [r0, #4]\n"
		"nop\n"
		:[a0]"=&r"(a0),[a1]"=&r"(a1),[a2]"=&r"(a2)
		:[array]"r"(array)
	);
	printf("a0 = %d\n", a0);
	printf("a1 = %d\n", a1);
	printf("a2 = %d\n", a2);
}

/*
 	cpsr = 0x600001d3
	cpsr_r = 0xf00001d3

	0xd3 = 0b 1101 0011 -> 10011
 */
