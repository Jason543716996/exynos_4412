#include <led.h>
#include <key.h>
#include <uart.h>
#include <lcd.h>
#include <font.h>
#include <mmu.h>
#include <vector.h>

void do_unde(void)
{
	printf("occur a undefined exception...\n");
}

int main(void)
{
	/*创建异常矢量表*/
	cp_vector_table((void *)TTB_BASE, VECTOR_BASE);

	__asm__ __volatile__(
		".word 0x21445454\n"		
		".word 0x77777777\n"		
	);

	printf("here is %s.\n", __func__);

	return 0;
}
