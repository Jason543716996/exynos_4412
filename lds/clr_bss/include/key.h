#ifndef KEY_H_
#define KEY_H_

#include <lib.h>

enum {DOWN, UP};

/*GPX3[2:5]*/

#define GPX3CON 0x11000c60 
#define GPX3DAT 0x11000c64

extern void key_init(void);
extern void check_key_dnup(void (*do_key)(int stat, int num));

#endif
