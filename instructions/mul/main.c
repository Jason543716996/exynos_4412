#include <lib.h>

void main(void)
{
	int a0, a1, result;

	a0 = 8000; 
	a1 = 4000;

	__asm__ __volatile__(
		"nop\n"
		"mul %[result], %[a0], %[a1]\n"
		"nop"

		:[result]"=&r"(result)
		:[a0]"r"(a0),[a1]"r"(a1)
	);

	printf("mul: %d\n", result);
}
