#include <lib.h>

void main(void)
{
	int l, r, v = 0;

	l = 1, r = 100;

	__asm__ __volatile__(
		"nop\n"

		"mov r0, %[l]\n"  //r0 = 1;
		"guohao:\n"
			"cmp r0, %[r]\n"  //if (r0 <= r)
			"bgt end\n"
			"add %[v], r0\n"
			"add r0, #1\n"
		"b guohao\n"

		"nop\n"
		"end:\n"

		:[v]"+&r"(v)
		:[l]"r"(l),[r]"r"(r)
		:"r0"
	);

	printf("1+2+...+100 = %d\n", v);
}
