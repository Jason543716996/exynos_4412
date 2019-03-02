#include <lib.h>

__asm__ (
	"array:\n"
		".word 0x9527, 0x3856, 0x7788\n"
);

void main(void)
{
	int o0, o1, o2;
	int other;

	__asm__ __volatile__(
		"nop\n"
		"ldr r0, =array\n"
		"ldr %[o0], [r0], #4\n"
		"ldr %[o1], [r0], #4\n"
		"ldr %[o2], [r0]\n"
		"ldr %[other], array\n" //3rd
		"nop\n"
		:[o0]"=&r"(o0),[o1]"=&r"(o1),
		 [o2]"=&r"(o2),[other]"=&r"(other)
		:
		:"r0"
	);
	printf("o0 = %#x\n", o0);
	printf("o1 = %#x\n", o1);
	printf("o2 = %#x\n", o2);
	printf("other = %#x\n", other);
}
