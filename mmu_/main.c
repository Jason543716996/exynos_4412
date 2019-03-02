#include <led.h>
#include <key.h>
#include <uart.h>
#include <lcd.h>
#include <font.h>
#include <mmu.h>

#define TTB_BASE 0x77000000

int main(void)
{
	u32 *table = (u32 *)TTB_BASE;
	u32 *p = (void *)0x66009520;
	*p = 0x96785602;

	CREATE_DESCRIPTOR(table, 0xabc09520, 0x66009520);	
	CREATE_DESCRIPTOR(table, 0xcba09520, 0x66009520);	
	CREATE_DESCRIPTOR(table, 0xbac09520, 0x66009520);	
	CREATE_DESCRIPTOR(table, 0xcab09520, 0x66009520);	

	global_map(table);

	printf("*((u32 *)0xabc09520)  = %#x\n", *((u32 *)0xabc09520));	
	printf("*((u32 *)0xcba09520)  = %#x\n", *((u32 *)0xcba09520));	
	printf("*((u32 *)0xbac09520)  = %#x\n", *((u32 *)0xbac09520));	
	printf("*((u32 *)0xcab09520)  = %#x\n", *((u32 *)0xcab09520));	
	printf("*((u32 *)0x66009520)  = %#x\n", *((u32 *)0x66009520));	

	return 0;
}
