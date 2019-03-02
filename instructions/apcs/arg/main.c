#include <lib.h>

int demo_func(int a, int b, int c, int d, int f, int g)
{
	return a+b+c+d+f+g;
}

void main(void)
{
	int val, sp0, sp1;

	__asm__ __volatile__(
		"mov r0, #1\n"
		"mov r1, #2\n"
		"mov r2, #3\n"
		"mov r3, #4\n"

		"mov r5, #5\n"
		"mov r6, #6\n"

		"push {r5-r6}\n"

		"bl demo_func\n"
		"mov %[val], r0\n"

		:[val]"=&r"(val),[sp0]"=&r"(sp0),[sp1]"=&r"(sp1)
		:
		:"r0","r3","r1","r2","r5","r6"
	);

	printf("val = %d\n", val);
	printf("%#x : %#x\n", sp0, sp1);
}
