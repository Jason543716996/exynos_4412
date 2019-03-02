#include <lcd.h>
#include <backlight.h>

static void fimd0_clock_select(void)
{
	u32 val;

	/*SCLK_FIMD0 = MOUTFIMD0/(FIMD0_RATIO + 1) = MOUTFIMD0/(7+1)*/
	val = ioread32(CLK_DIV_LCD);
	val &= ~0xf;
	val |= 0x7;
	iowrite32(val, CLK_DIV_LCD);

	/*SELECT MPLL_USER_T as MOUTFIMD0*/
	val = ioread32(CLK_SRC_LCD0);
	val &= ~0xf;
	val |= 0x6;
	iowrite32(val, CLK_SRC_LCD0);
}

static void window0_init(void)
{
	u32 val;

	/*set BPP888, WORD SWAP, enable*/
	val = (0x1 << 15) | (0xb << 2) | (1 << 0);
	iowrite32(val, WINCON0);

	/*set left top xy (0, 0)*/
	iowrite32(0, VIDOSD0A);

	/*set right bootm xy (799, 479)*/
	iowrite32((799 << 11) | (479 << 0), VIDOSD0B);

	/*the number of word of window0 */
	iowrite32(800*480, VIDOSD0C);
	/*set window0's frambuff's start and end address*/
	iowrite32(FRAMBUFF0, VIDW00ADD0B0);
	iowrite32(FRAMBUFF0 + 800*480*4, VIDW00ADD1B0);

	/*channel0 select window0, window0 selsect channel0*/
	val = ioread32(WINCHMAP2);
	val &= ~((0x7 << 16) | (0x7 << 0));
	val |= (0x1 << 16) | (0x1 << 0);
	iowrite32(val, WINCHMAP2);

	/*enable channel0, disable local path*/
	val = ioread32(SHADOWCON);
	val &= ~(1 << 5);
	val |= 1 << 0;
	iowrite32(val, SHADOWCON);
}

static void lcd_gpio_set(void)
{
	u32 val;

	iowrite32(0x22222222, GPF0CON);
	iowrite32(0x22222222, GPF1CON);
	iowrite32(0x22222222, GPF2CON);

	val = ioread32(GPF3CON);
	val &= ~0xffff;
	val |= 0x2222;
	iowrite32(val, GPF3CON);
}

void lcd_init(void)
{
	u32 val;

	/*set GFP0,GPF1, GPF2, GPF3[0:3] 24pins as display controller uses*/
	lcd_gpio_set();

	/*100MHz/(2+1) = 33.3MHz*/
	val = ioread32(VIDCON0);
	val &= ~(0xff << 6);
	val |= (0x2 << 6);
	iowrite32(val, VIDCON0);

	/*VCLK: rising, HSYNC/VSYNC: inverted*/
	val = (1 << 9) | (1 << 7) | (1 << 6) | (1 << 5);
	iowrite32(val, VIDCON1);

//	iowrite32(0, VIDCON2);

	/*set VSYNC TIMING ARG*/
	val = (12 << 16) | (21 << 8) | (9 << 0);
	iowrite32(val, VIDTCON0);

	/*set HSYNC TIMING ARG*/
	val = (25 << 16) | (209 << 8) | (19 << 0);
	iowrite32(val, VIDTCON1);

	/*set LCD HARD reselution*/
	iowrite32((479 << 11) | (799 << 0), VIDTCON2);

	window0_init();

	
	/*set 100MHz*/
	fimd0_clock_select();

	/*enable blklight*/
	val = ioread32(LCDBLK_CFG);
	val |= 1 << 1;
	iowrite32(val, LCDBLK_CFG);
	
	/*enable display controller control signal*/
	val = ioread32(VIDCON0);
	val |= 0x3;
	iowrite32(val, VIDCON0);
	
	set_backlight_start(127);
}

void draw_point(int x, int y, int col)
{
	*((int *)FRAMBUFF0 + y*800 + x)	= col;
}

#if 0
void draw_line(int lx, int ly, int col, int len)
{
	
}
#endif
