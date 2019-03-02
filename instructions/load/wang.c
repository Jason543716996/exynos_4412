#include <lib.h>

/*
 	ldr: load a word value from memory into register.
 */

void main(void)
{
	char str[] = "lol";
	int wang;

	__asm__ __volatile__(
		"nop\n"
		"mov r0, %[str]\n"
		"ldr %[wang], [r0]\n"
		"nop\n"
		:[wang]"=&r"(wang)
		:[str]"r"(str)
		:"r0"
	);

	printf("wang = %s\n", (char *)(&wang));
}

/*
 	cpsr = 0x600001d3
	cpsr_r = 0xf00001d3

	0xd3 = 0b 1101 0011 -> 10011
 */
