#include <lcd.h>
#include <backlight.h>

static void window1_init(void);

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
	window1_init();

	
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

void draw_point_win0(int x, int y, int col)
{
	*((int *)FRAMBUFF0 + y*800 + x)	= col;
}

void draw_point_win1(int x, int y, int col)
{
	*((int *)WIN1FRAMBUF0 + y*800 + x)	= col;
}
#if 0
void draw_line(int lx, int ly, int col, int len)
{
	
}
#endif

#if 0
static void window1_init(void)
{
	u32 val, sz;

	val = (1 << 15) | (0xb << 2) | (0x1 << 0);
	sz = 800*480;
	/*设置了window1使用BUF0作为要显示的数据，设置窗口支持的数据格式，使能窗口*/
	iowrite32(val, WINCON1);

	/*设置window0显示区域的左上角坐标*/
	val = (600 << 11) | (0 << 0);
	write32(val, VIDOSD1A);
	
	/*设置window0显示区域的右下角坐标*/
	val = (799 << 11) | (479 << 0);
	write32(val, VIDOSD1B);

	val = ((200*4) << 0) | ((600*4) << 13);
	write32(val, VIDW01ADD2);


	val = read32(VIDOSD1C);
	val &= ~(0xffffff);
	val |= 0x666666;
	write32(val, VIDOSD1C);

	/*设置window0要显示的图像所占内存空间的大小，单位为字*/
	write32(sz, VIDOSD1D);

	/*设置了window1要显示的数据所在内存的起始地址和结束地址*/
	write32(WIN1FRAMBUF0, VIDW01ADD0B0);
	write32(WIN1FRAMBUF0 + sz*4, VIDW01ADD1B0);

	/*窗口0选择通道0，通道0选择窗口0*/
	val = read32(WINCHMAP2);
	val &= ~((0x7 << 19) | (0x7 << 3));
	val |= ((0x2 << 19) | (0x2 << 3));
	write32(val, WINCHMAP2);
	
	/*禁用本地通道0， 使能DMA的通道0*/
	val = read32(SHADOWCON);
	val &= ~(1 << 6);
	val |= 0x1 << 1;
	write32(val, SHADOWCON);
}

#endif

#if 1
static void window1_init(void)
{
	u32 val, sz;

	val = (1 << 15) | (0xb << 2) | (0x1 << 0);
	sz = 800*480;

	/*设置了window1使用BUF0作为要显示的数据，设置窗口支持的数据格式，使能窗口*/
	iowrite32(val, WINCON1);

	/*设置window0显示区域的左上角坐标*/
	iowrite32(0, VIDOSD1A);

	/*设置window0显示区域的右下角坐标*/
	val = (799 << 11) | (479 << 0);
	iowrite32(val, VIDOSD1B);

#if 1
	/*key color*/
	val = ioread32(W1KEYCON1);
	val &= ~0xffffff;
	val |= 0xff << 0;
	iowrite32(val, W1KEYCON1);//设置的关键色为0x0000ff，蓝色

	val = ioread32(W1KEYCON0);
	val |= 0x1 << 25;
	iowrite32(val, W1KEYCON0);//enable key color
#endif

	/*透明度*/
	val = ioread32(VIDOSD1C);
	val &= ~(0xffffff);
	val |= 0xffffff;
	iowrite32(val, VIDOSD1C);

	/*设置window0要显示的图像所占内存空间的大小，单位为字*/
	iowrite32(sz, VIDOSD1D);

	/*设置了window1要显示的数据所在内存的起始地址和结束地址*/
	iowrite32(WIN1FRAMBUF0, VIDW01ADD0B0);
	iowrite32(WIN1FRAMBUF0 + sz*4, VIDW01ADD1B0);

	/*窗口0选择通道0，通道0选择窗口0*/
	val = ioread32(WINCHMAP2);
	val &= ~((0x7 << 19) | (0x7 << 3));
	val |= ((0x2 << 19) | (0x2 << 3));
	iowrite32(val, WINCHMAP2);
	
	/*禁用本地通道0， 使能DMA的通道0*/
	val = ioread32(SHADOWCON);
	val &= ~(1 << 6);
	val |= 0x1 << 1;
	iowrite32(val, SHADOWCON);
}
#endif
