#include <lib.h>

#if 0
	increase/decrease --> i/d
	before/after  -->  b/a

	ldmib, ldmia, ldmdb, ldmda
	stmib, stmia, stmdb, stmda
#endif

void main(void)
{
	int src[4] = {4, 3, 2, 1};
	int dst[4] = {0};

	__asm__ __volatile__(
		"nop\n"
		"mov r4, %[src]\n"
		"ldmia r4!, {r0, r1, r2, r3}\n"
		"mov r4, %[dst]\n"
		"stmia r4!, {r0-r3}\n"
		"nop\n"
		:
		:[src]"r"(src),[dst]"r"(dst)
		:"r4","r0","r1","r2","r3"
	);

	int i;
	for (i = 0; i < 4; i++) {
		printf("dst[%d] = %d\n", i, dst[i]);
	}
}
