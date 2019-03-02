#include <lib.h>

typedef struct node {
	int val;
	struct node *next;
}node_t;

void main(void)
{
	node_t *h, n0, n1, n2;

	__asm__ __volatile__(
		"nop\n"

		"mov %[h], %[addn0]\n"
		
		"mov r0, %[addn0]\n"
		"ldr r1, =0x9527\n"
		"str r1, [r0], #4\n"
		"mov r1, %[addn1]\n"
		"str r1, [r0]\n"    //r1 = &n1;

		"ldr r0, =0x3856\n"
		"str r0, [r1], #4\n"
		"mov r0, %[addn2]\n"  //r0 = &n2;
		"str r0, [r1]\n"

		"ldr r1, =0x7788\n"
		"str r1, [r0], #4\n"
		"mov r1, #0\n"
		"str r1, [r0]\n"
		
		"nop\n"

		:[h]"=&r"(h)
		:[addn0]"r"(&n0),[addn1]"r"(&n1),[addn2]"r"(&n2)
		:"r0","r1"
	);

	while (h) {
		printf("%#x  ", h->val);
		h = h->next;
	}
	printf("\n");
}

/*
 	cpsr = 0x600001d3
	cpsr_r = 0xf00001d3

	0xd3 = 0b 1101 0011 -> 10011
 */
