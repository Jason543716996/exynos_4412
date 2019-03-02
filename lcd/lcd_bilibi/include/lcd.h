#ifndef LCD_H_
#define LCD_H_

#include <lib.h>

/*GPIO*/
#define  GPF0CON  0x11400180 
#define  GPF1CON  0x114001A0 
#define  GPF2CON  0x114001C0 
#define  GPF3CON  0x114001E0 

/*DISPLAY CONTROLLER*/
#define VIDCON0 		0x11c00000 
#define VIDCON1 		0x11c00004 
#define VIDCON2 		0x11c00008 
#define VIDCON3 		0x11c0000C 
#define VIDTCON0		0x11c00010 
#define VIDTCON1		0x11c00014 
#define VIDTCON2		0x11c00018 
#define VIDTCON3		0x11c0001C 
#define WINCON0 		0x11c00020 
#define WINCON1 		0x11c00024 
#define WINCON2 		0x11c00028 
#define WINCON3 		0x11c0002C 
#define WINCON4 		0x11c00030 
#define SHADOWCON		0x11c00034 
#define WINCHMAP2		0x11c0003C 
#define VIDOSD0A 		0x11c00040 
#define VIDOSD0B 		0x11c00044 
#define VIDOSD0C 		0x11c00048 
#define VIDOSD1A 		0x11c00050 
#define VIDOSD1B 		0x11c00054 
#define VIDOSD1C 		0x11c00058 
#define VIDOSD1D 		0x11c0005C 
#define VIDOSD2A 		0x11c00060 
#define VIDOSD2B 		0x11c00064 
#define VIDOSD2C 		0x11c00068 
#define VIDOSD2D 		0x11c0006C 
#define VIDOSD3A 		0x11c00070 
#define VIDOSD3B 		0x11c00074 
#define VIDOSD3C 		0x11c00078 
#define VIDOSD4A 		0x11c00080 
#define VIDOSD4B 		0x11c00084 
#define VIDOSD4C 		0x11c00088 
#define VIDW00ADD0B0 		0x11c000A0 
#define VIDW00ADD0B1 		0x11c000A4 
#define VIDW00ADD0B2 		0x11c020A0 
#define VIDW01ADD0B0 		0x11c000A8 
#define VIDW01ADD0B1 		0x11c000AC 
#define VIDW01ADD0B2 		0x11c020A8 
#define VIDW02ADD0B0 		0x11c000B0 
#define VIDW02ADD0B1 		0x11c000B4 
#define VIDW02ADD0B2 		0x11c020B0 
#define VIDW03ADD0B0 		0x11c000B8 
#define VIDW03ADD0B1 		0x11c000BC 
#define VIDW03ADD0B2 		0x11c020B8 
#define VIDW04ADD0B0 		0x11c000C0 
#define VIDW04ADD0B1 		0x11c000C4 
#define VIDW04ADD0B2 		0x11c020C0
#define VIDW00ADD1B0 		0x11c000D0 
#define VIDW00ADD1B1 		0x11c000D4 
#define VIDW00ADD1B2 		0x11c020D0 
#define VIDW01ADD1B0 		0x11c000D8 
#define VIDW01ADD1B1 		0x11c000DC 
#define VIDW01ADD1B2 		0x11c020D8 
#define VIDW02ADD1B0 		0x11c000E0 
#define VIDW02ADD1B1 		0x11c000E4 
#define VIDW02ADD1B2 		0x11c020E0 
#define VIDW03ADD1B0 		0x11c000E8 
#define VIDW03ADD1B1 		0x11c000EC 
#define VIDW03ADD1B2 		0x11c020E8 
#define VIDW04ADD1B0 		0x11c000F0 
#define VIDW04ADD1B1 		0x11c000F4 
#define VIDW04ADD1B2 		0x11c020F0 
#define VIDW00ADD2		0x11c00100 
#define VIDW01ADD2		0x11c00104 
#define VIDW02ADD2		0x11c00108 
#define VIDW03ADD2		0x11c0010C 
#define VIDW04ADD2		0x11c00110 
#define VIDINTCON0		0x11c00130 
#define VIDINTCON1		0x11c00134 
#define W1KEYCON0 		0x11c00140 

//1860

/*CMU*/


/*system register*/
#define LCDBLK_CFG   0x10010210
#define CLK_DIV_LCD  0x1003c534
#define CLK_SRC_LCD0 0x1003c234

extern void lcd_init(void);
extern void draw_point(int x, int y, int col);
extern void draw_line(int lx, int ly, int col, int len);
extern void clr_screen(int col);

/*window0's buf0 frambuffer start address*/
#define FRAMBUFF0 0x60000000

#endif
