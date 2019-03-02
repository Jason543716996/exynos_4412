#ifndef KEY_H_
#define KEY_H_

#include <lib.h>

enum {DOWN, UP};

/*GPX3[2:5]*/

#define GPX3CON 0x11000c60 
#define GPX3DAT 0x11000c64

#define EXT_INT43_PEND 		0x11000f4c
#define EXT_INT43_MASK 		0x11000f0c
#define EXT_INT43_FLTCON0	0x11000e98
#define EXT_INT43_FLTCON1	0x11000e9c
#define EXT_INT43CON		0x11000e0c

extern void key_init(void);
extern void check_key_dnup(void (*do_key)(int stat, int num));

/*中断机制实现按键的驱动*/
extern void key_eint_register(void);

#endif
