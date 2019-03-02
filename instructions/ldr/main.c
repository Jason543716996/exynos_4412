#include <lib.h>

#if 0
		the two instruction uses equal each other 

		"ldr r0, =pc\n"

		"adr r0, pc\n"
#endif

void main(void)
{
	int pc, next, lable, pc2;
	/*
	 	pc = 0x50000024
		pc2 = 0x5000001c
		next = 0x50000020
		lable = 0x50000024
	 */

	__asm__ __volatile__(
		"nop\n"
		"pc:\n"
			"mov %[pc], pc\n"
		"next:\n"
			"nop\n"
		"lable:\n"
			"nop\n"
		"ldr %[next], =next\n"
		"ldr %[lable], =lable\n"
//		"ldr %[pc2], =pc\n"
		"adr %[pc2], pc\n" //get the lable address to store register...
		"nop\n"
		:[pc]"=&r"(pc),[next]"=&r"(next),
		 [lable]"=&r"(lable),[pc2]"=&r"(pc2)
	);
	printf("pc = %#x\n", pc);
	printf("next = %#x\n", next);
	printf("lable = %#x\n", lable);
	printf("pc2 = %#x\n", pc2);
}
