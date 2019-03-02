#ifndef WDT_H_
#define WDT_H_

#include <lib.h>
#include <gic.h>

#define WTCON 		0x10060000 
#define WTDAT 		0x10060004 
#define WTCNT 		0x10060008 
#define WTCLRINT 	0x1006000C 

#define AUTOMATIC_WDT_RESET_DISABLE	0x10020408
#define MASK_WDT_RESET_REQUEST		0x1002040c

#define WDTID		75

extern void wdt_timer_set(int ms, void (*do_wdt)(void));
extern void wdt_reset_set(int ms);

#endif
