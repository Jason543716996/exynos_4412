#include <led.h>
#include <key.h>
#include <uart.h>
#include <lcd.h>
#include <font.h>
#include <mmu.h>
#include <vector.h>
#include <wdt.h>
#include <timer.h>

void do_data_abt(void)
{
	printf("occur a data abort exception...\n");
}

void do_unde(void)
{
	printf("occur a undefined exception...\n");
}

void do_svc(u32 imm)
{
	printf("svc call %d\n", imm);
}

void do_wdt(void)
{
	printf("wdt timer...\n");
	iowrite32(9527, WTCLRINT);
}

int main(void)
{
	/*创建异常矢量表*/
	cp_vector_table((void *)TTB_BASE, VECTOR_BASE);

	timer4_init(2000);

	return 0;
}
