#include <lib.h>

int mystrlen(const char *str)
{
	int len = 0;

	__asm__ __volatile__(
		"mov r0, %[str]\n"

		"loop:\n"
			"ldrb r1, [r0], #1\n"
			"cmp r1, #0\n"
			"beq tail\n"
			"add %[len], #1\n"
		"b loop\n"

		"tail:\n"
		:[len]"+&r"(len)		
		:[str]"r"(str)
		:"r0","r1"
	);

	return len;
}

void main(void)
{
	printf("mystrlen(\"hello\") = %d\n", mystrlen("hello"));
}
