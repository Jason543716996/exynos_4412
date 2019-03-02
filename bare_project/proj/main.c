#include <led.h>
#include <adc.h>
#include <key.h>
#include <uart.h>
#include <lcd.h>
#include <font.h>
#include <mmu.h>
#include <vector.h>
#include <wdt.h>
#include <timer.h>
#include <rtc.h>
#include <tp.h>

void do_data_abt(void)
{
	uprintf("occur a data abort exception...\n");
}

void do_unde(void)
{
	uprintf("occur a undefined exception...\n");
}

void do_svc(u32 imm)
{
	uprintf("svc call %d\n", imm);
}

void do_wdt(void)
{
	uprintf("wdt timer...\n");
	iowrite32(9527, WTCLRINT);
}

int main(void)
{
	uart0_init();
	char buf[64];

	uprintf("boot project arm.bin successfull...\n");
	uprintf("boot project arm.bin successfull...\n");
	uprintf("boot project arm.bin successfull...\n");
	uprintf("boot project arm.bin successfull...\n");
	uprintf("boot project arm.bin successfull...\n");

	/*创建异常矢量表*/
	cp_vector_table((void *)TTB_BASE, VECTOR_BASE);

	led_init();

	led_on(0);
	led_on(1);
	led_on(2);
	led_on(3);

	uprintf("[project@demo]# ");
	while (1) {
		ugets(buf);	
		uprintf("command not find.\n");
		uprintf("[project@demo]# ");
	}

	return 0;
}
