#include <led.h>

void led_init(void)
{
	u32 tmp;
	u8 val;

	/*set GPM4[0:3] as output*/
	tmp = ioread32(GPM4CON);
	tmp &= ~0xffff;
	tmp |= 0x1111;
	iowrite32(tmp, GPM4CON);

	val = ioread8(GPM4DAT);
	val |= 0xf;
	iowrite8(val, GPM4DAT);
}

void led_on(u8 n)
{
	u8 val;

	if (n >= 4) {
		uprintf("there is no the number led...error!!!!\n");
		return;
	}

	val = ioread8(GPM4DAT);
	val &= ~(1 << n);
	iowrite8(val, GPM4DAT);
}

void led_off(u8 n)
{
	u8 val;

	if (n >= 4) {
		uprintf("there is no the number led...error!!!!\n");
		return;
	}

	val = ioread8(GPM4DAT);
	val |= (1 << n);
	iowrite8(val, GPM4DAT);
}

void led_allon(void)
{
	u8 val;
	val = ioread8(GPM4DAT);
	val &= ~0xf;
	iowrite8(val, GPM4DAT);

}

void led_alloff(void)
{
	u8 val;
	val = ioread8(GPM4DAT);
	val |= 0xf;
	iowrite8(val, GPM4DAT);
}
