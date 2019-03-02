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

extern int _start_xiaomi;
extern int _end_xiaomi;

int liu6 __attribute__ ((unused, section(".xiaomi")))= 96;
int liu7 __attribute__ ((unused, section(".xiaomi")))= 97;
int liu5 __attribute__ ((unused, section(".xiaomi")))= 95;
int liu4 __attribute__ ((unused, section(".xiaomi")))= 94;
int liu3 __attribute__ ((unused, section(".xiaomi")))= 93;
int liu2 __attribute__ ((unused, section(".xiaomi")))= 92;

int main(void)
{
	int val;

	/*创建异常矢量表*/
	cp_vector_table((void *)TTB_BASE, VECTOR_BASE);

	adc_init();

	int *p = &_start_xiaomi;
	while (p < &_end_xiaomi) {
		printf("*p = %d\n", *p);
		p++;
	}
#if 0
	while (1) {
		udelay(500000);
		//val = get_adc_val_irq(0); 
		val = get_adc_val_polling(0); 
		if (val < 0) {
			printf("error adc...\n");
			break;
		}
		printf("digital(%04d) --> %04dmv\n", 
				val, val*1800/4095);
	}
#endif
	return 0;
}
