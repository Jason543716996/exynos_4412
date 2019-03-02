#ifndef UART_H_
#define UART_H_

#include <lib.h>

#define CLK_SRC_PERIL0 0x1003c250
#define CLK_DIV_PERIL0 0x1003c550

#define GPA0CON  0x11400000

#define ULCON0		0x13800000
#define UCON0 		0x13800004
#define UFCON0		0x13800008
#define UMCON0		0x1380000C
#define UTRSTAT0	0x13800010
#define UERSTAT0	0x13800014
#define UFSTAT0 	0x13800018
#define UMSTAT0 	0x1380001C
#define UTXH0 		0x13800020
#define URXH0 		0x13800024
#define UBRDIV0 	0x13800028
#define UFRACVAL0 	0x1380002C
#define UINTP0 		0x13800030
#define UINTSP0 	0x13800034
#define UINTM0 		0x13800038 

extern void uart0_init(void);
extern void uputchar(int c);
extern int ugetchar(void);
extern char *ugets(char *b);
extern void uputs(const char *s);
extern void uprintf(const char *fmt, ...);

#endif
