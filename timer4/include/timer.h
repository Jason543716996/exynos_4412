#ifndef XCM_TIIMER_H_
#define XCM_TIIMER_H_

#include <lib.h>

#define TCFG0 		0x139d0000
#define TCFG1 		0x139d0004
#define TCON 		0x139d0008 
#define TCNTB0 		0x139d000C 
#define TCMPB0 		0x139d0010 
#define TCNTO0 		0x139d0014 
#define TCNTB1 		0x139d0018 
#define TCMPB1 		0x139d001C 
#define TCNTO1 		0x139d0020 
#define TCNTB2 		0x139d0024 
#define TCMPB2 		0x139d0028 
#define TCNTO2 		0x139d002C 
#define TCNTB3 		0x139d0030 
#define TCMPB3 		0x139d0034 
#define TCNTO3 		0x139d0038 
#define TCNTB4 		0x139d003C 
#define TCNTO4 		0x139d0040 
#define TINT_CSTAT 	0x139d0044 

#define GPD0CON		0x114000a0

extern void timer0_init(u32 periodus, u32 dutyus);
extern void beep_set_hz(u32 freq);
extern void timer4_init(u32 periodms);

#endif
