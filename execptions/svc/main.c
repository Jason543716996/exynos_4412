#include <led.h>
#include <key.h>
#include <uart.h>
#include <lcd.h>
#include <font.h>
#include <mmu.h>
#include <vector.h>

#define DEFINE_FUNC(n)  \
		void func_##n(void)\
		{\
			printf("svc call: %s\n", #n);\
		}

DEFINE_FUNC(2018) 
DEFINE_FUNC(2019)
DEFINE_FUNC(3000)

void do_unde(void)
{
	printf("occur a undefined exception...\n");
}

void do_svc(u32 imm)
{
	switch (imm) {
		case 2018:
			func_2018();
			break;
		case 2019:
			func_2019();
			break;
		case 3000:
			func_3000();
			break;
	}
}

int main(void)
{
	/*创建异常矢量表*/
	cp_vector_table((void *)TTB_BASE, VECTOR_BASE);

	__asm__ __volatile__(
		".word 0x21445454\n"		
		".word 0x77777777\n"	//undefined exceptions
		"svc #2018\n"
		"swi #2019\n"
		"swi #3000\n"
	);

	printf("here is %s.\n", __func__);

	return 0;
}
