#ifndef LED_H_
#define LED_H_

#include <lib.h>

#define GPM4CON 0x110002e0
#define GPM4DAT 0x110002e4

/*led api*/
extern void led_init(void);
extern void led_on(u8);
extern void led_off(u8);
extern void led_allon(void);
extern void led_alloff(void);

#endif
