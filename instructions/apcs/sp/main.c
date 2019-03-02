#include <lib.h>

/*
 	push {registers}/pop {}
	stmdb/ldmia
	stmfd/ldmfd
 */

void main(void)
{
	int a0, a1, a2;

	__asm__ __volatile__(
		"mov r0, #22\n"
		"mov r1, #33\n"
	
//		"push {r0-r1}\n"
//		"pop {r3-r4}\n"
//		"stmfd sp!, {r0-r1}\n"
//		"ldmfd sp!, {r3-r4}\n"
		
		"stmdb sp!, {r0-r1}\n"
		"ldmia sp!, {r3-r4}\n"

		"mov %[a0], r3\n"
		"mov %[a1], r4\n"

		:[a0]"=&r"(a0),[a1]"=&r"(a1)
		:
		:"r0","r3","r1","r4"
	);

	printf("a0 = %d\n", a0);
	printf("a1 = %d\n", a1);
}
