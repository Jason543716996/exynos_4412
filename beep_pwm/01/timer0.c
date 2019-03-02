#include <timer.h>

void timer0_init(u32 periodus, u32 dutyus)
{
	u32 val;

	/*第一级分频后的频率为1MHz*/
	val = ioread32(TCFG0);
	val &= ~0xff;
	val |= 99;
	iowrite32(val, TCFG0);
	/*第二级分频后的频率为1MHz*/
	val = ioread32(TCFG1);
	val &= ~0xf;
	iowrite32(val, TCFG1);

	// f = 1000000HZ, T=1/f = 1us;
	iowrite32(periodus, TCNTB0);
	iowrite32(periodus - dutyus, TCMPB0);

	val = ioread32(TCON);
	val &= ~0xf;
	iowrite32(val, TCON);

	/*将TCNTB0和TCMPB0里的值更新进逻辑单元*/
	val = ioread32(TCON);
	val |= (1 << 3) | (1 << 1); 
	iowrite32(val, TCON);

	val = ioread32(TCON);
	val &= ~(1 << 1);
	iowrite32(val, TCON);

	/*启动timer4工作和设置自动加载功能*/
	val = ioread32(TCON);
	val |= (1 << 0);
	iowrite32(val, TCON);
}

void beep_set_hz(u32 freq)
{
#define USPERSEC 1000000UL
	u32 tmp = USPERSEC/freq;
	u32 val;

	/*设置GPD0的0引脚为TOU0*/
	val = ioread32(GPD0CON);
	val &= ~0xf;
	val |= 0x2;
	iowrite32(val, GPD0CON);

	timer0_init(tmp, tmp >> 1);
}


