#include <lib.h>

void main(void)
{
	int var0 = 78;
	int var1 = 78;
	int ro0 = 22;
	int ro1 = 33;

	__asm__ __volatile__(
		"nop\n"
		"mov %0, #95\n" //#号后面跟一个数，代表一个立即数（常量）
		"mov %1, %3\n" //#号后面跟一个数，代表一个立即数（常量）
		"nop"

		:"=r"(var0),"=r"(var1) //=代表此变量为输出变量，可以被赋值， 
 //r代表运算时此变量会被替换成通用寄存器
		:"r"(ro0),"r"(ro1)
	);

	printf("var0 = %d\n", var0);
	printf("var1 = %d\n", var1);
}
