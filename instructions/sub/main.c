#include <lib.h>

void main(void)
{
	int a0, a1, result0, result1, add;

	a0 = 8000; 
	a1 = 4000;

	__asm__ __volatile__(
		"nop\n"
//		"subs %[result0], %[a1], %[a0]\n"
//		"sbc %[result1], %[a1], %[a0]\n"
		"mvn r0, #0\n"
		"adds %[add], r0, #88\n"
		"adc %[add], %[a0], %[a1]\n"
		"nop"

		:[result0]"=&r"(result0),[result1]"=&r"(result1),[add]"=&r"(add)
		:[a0]"r"(a0),[a1]"r"(a1)
		:"r0"
	);

//	printf("%d - %d = %d\n", a1, a0, result0);
//	printf("%d - %d - c = %d\n", a1, a0, result1);
	printf("add: %d\n", add);
}
