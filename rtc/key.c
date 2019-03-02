#include <key.h>

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
