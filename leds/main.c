#include <led.h>

#define TEST 0x110002C4

int main(void)
{
	u32 val;

	int i = 0;

	val = ioread32(TEST);
	val >>= 5;
	printf("val = %d\n", val);

	led_init();
	while (1){
		i = 0;
		while (1) {
			led_on(i);
			udelay(200000);
			led_off(i);
			i++;
			if (i >= 4) {
				break;
			}
		}

		i = 3;
		while (1) {
			led_on(i);	
			udelay(200000);
			led_off(i);
			i--;
			if (i < 0) {
				break;
			}
		}

		led_allon();
		udelay(200000);
		led_alloff();
		udelay(200000);
		led_allon();
		udelay(200000);
		led_alloff();
	}
	return 0;
}
