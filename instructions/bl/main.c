#include <lib.h>

/*
   1.
 	b  lable

   2.   bl  lable

   	mov lr, next_instruction_add
	b lable
   
   3.  mov pc, register 

   4. ldr pc, =lable
 */

void main(void)
{
	int val;

	__asm__ __volatile__(
		"nop\n"
		"b hehe\n"
		
		"lala:\n"
			"add %[val], %[val], #1\n"
			"b end\n"

		"haha:\n"
			"sub %[val], %[val], #100\n"
			"mov pc, lr\n"
		"hehe:\n"
			"mov %[val], #100\n"
		//	"bl haha\n"
			"mov lr, pc\n"
			"ldr pc, =haha\n"
		//	"b haha\n"
			"b lala\n"
		"end:\n"
		"nop\n"
		:[val]"=&r"(val)
	);
	printf("val = %d\n", val);
}
