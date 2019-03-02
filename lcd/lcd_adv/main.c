#include <led.h>
#include <key.h>
#include <uart.h>
#include <lcd.h>

int main(void)
{
	int i, j;

	lcd_init();

	for (i = 0; i < 480; i++) {
		for (j = 0; j < 800; j++) {
		if ((j-400)*(j-400) + (i-240)*(i-240) <= 10000)
			draw_point_win1(j, i, 0xff);
		}
	}

	return 0;
}
