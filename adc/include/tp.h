#ifndef TINY4412_TP_H_
#define TINY4412_TP_H_

#include <lib.h>

#define GPX1CON 		0x11000c20
#define EXT_INT41CON		0x11000e04
#define EXT_INT41_FLTCON1	0x11000e8c
#define EXT_INT41_MASK		0x11000f04
#define EXT_INT41_PEND		0x11000f44

extern void tp_int_init(void);

#endif
