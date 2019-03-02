#include <stdio.h>

__asm__(
	"demo_func:\n"	

	"mov ip, sp\n"
	"push {fp, ip, lr, pc}\n"
	"sub fp, ip, #4\n"

	"ldr r0, =str\n"
	"ldr r1, data\n"

	"bl printf\n"	

	"sub sp, fp, #12\n"
	"ldm sp, {fp, sp, pc}\n"

	"str:\n"
		".string \"New year happy %d\\n\"\n"
	"data:\n"
		".word 2018\n"
);

int main(void)
{
	__asm__ __volatile__(
		"bl demo_func\n"
	);

	printf("come back to %s\n", __func__);

	return 0;
}

/*
 	__func__, __LINE__, __FILE__, __DATE__
 */
