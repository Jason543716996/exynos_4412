#include <lib.h>

/*
 	cmp
 */

void main(void)
{
	int a, b, v;

	a = 80000,  b = 80000;

	__asm__ __volatile__(
		"nop\n"
		"cmp %[a], %[b]\n"
		"movgt %[v], #1\n"
		"movlt %[v], #-1\n"
		"moveq %[v], #0\n"
		"nop\n"

		:[v]"=&r"(v)
		:[a]"r"(a),[b]"r"(b)
	);
	printf("v = %d\n", v);
}
