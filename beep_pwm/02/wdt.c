#include <wdt.h>

void wdt_timer_set(int ms, void (*do_wdt)(void))
{
	u32 tmp;

	tmp = ms*3;
	iowrite32(tmp, WTCNT);
	iowrite32(tmp, WTDAT);
	
	tmp = (0xff << 8) | (0x1 << 5) | (0x3 << 3) | (0x1 << 2);
	iowrite32(tmp, WTCON);

	irq_request_cpu0(WDTID, do_wdt, 0);
}

void wdt_reset_set(int ms)
{
	u32 tmp;

	tmp = ms*3;
	iowrite32(tmp, WTCNT);
	
	tmp = (0xff << 8) | (0x1 << 5) | (0x3 << 3) | (0x1 << 0);
	iowrite32(tmp, WTCON);

	iowrite32(0, AUTOMATIC_WDT_RESET_DISABLE);
	iowrite32(0, MASK_WDT_RESET_REQUEST);
}
