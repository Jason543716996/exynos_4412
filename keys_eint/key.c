#include <key.h>
#include <gic.h>

void key_init(void)
{
	u32 tmp;

	/*set GPX3CON[2:5] as input*/
	tmp = ioread32(GPX3CON);
	tmp &= ~(0xffff << 8);
	iowrite32(tmp, GPX3CON);
}

void check_key_dnup(void (*do_key)(int stat, int num))
{
	u8 val;
	int n;

	do {
		val = ioread8(GPX3DAT);
		val >>= 2;
		val &= 0xf;
	} while (val == 0xf);

	switch (val) {
		case 0xe:
			n = 1;
			break;
		case 0xd:
			n = 2;
			break;
		case 0xb:
			n = 3;
			break;
		case 0x7:
			n = 4;
			break;
	}

	do_key(DOWN, n);

	do {
		val = ioread8(GPX3DAT);
		val >>= 2;
		val &= 0xf;
	} while (val != 0xf);

	do_key(UP, n);
}

void do_key(void)
{
	int val, tmp;

	tmp = val = ioread32(EXT_INT43_PEND);
	val >>= 2;
	val &= 0xf;

	switch(val) {
	case 1:
		printf("key down 1 ...\n");
		break;
	case 2:
		printf("key down 2 ...\n");
		break;
	case 4:
		printf("key down 3 ...\n");
		break;
	case 8:
		printf("key down 4 ...\n");
		break;
	default:
		break;
	}

	iowrite32(tmp, EXT_INT43_PEND);
}
/*
   按键中断为外部中断
 
   内部中断： SOC上的设备或控制器产生的中断信号属于内部中断，无须设置中断
   	      触发方式。
   外部中断： 仅仅连接在GPIO的外部设备，无其他SOC上的控制器控制，产生的
              中断电信号为外部中断，需要设置中断触发方式。
 */
void key_eint_register(void)
{
	u32 val;

	/*设置GPX3[2:5]为外部中断专用*/
	val = ioread32(GPX3CON);
	val |= (0xffff << 8);
	iowrite32(val, GPX3CON);

	/*设置GPX3[2：5]引脚的中断触发方式为下降边沿*/
	val = ioread32(EXT_INT43CON);
	val &= ~(0xffff << 8);
	val |= 0x2222 << 8;
	iowrite32(val, EXT_INT43CON);

	/*设置GPX3[2：5]引脚的中断的滤波器，数字滤波，滤波宽度*/
	val = ioread32(EXT_INT43_FLTCON0);
	val |= 0xffff << 16;
	iowrite32(val, EXT_INT43_FLTCON0);
	val = ioread32(EXT_INT43_FLTCON1);
	val |= 0xffff << 0;
	iowrite32(val, EXT_INT43_FLTCON1);

	/*使能外部中断GPX3[2:5]*/
	val = ioread32(EXT_INT43_MASK);
	val &= ~(0xf << 2);
	iowrite32(val, EXT_INT43_MASK);

	//EXT_INT43_PEND
#define KEYINT 64
	irq_request_cpu0(KEYINT, do_key, 0);
}

