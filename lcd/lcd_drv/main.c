#include <led.h>
#include <key.h>
#include <uart.h>
#include <lcd.h>

#define YELLOW 0xF7E026

int main(void)
{
	int i, j;

	lcd_init();

	for (i = 0; i < 480; i++) {
		for (j = 0; j < 800; j++) {
			draw_point(j, i, YELLOW);
		}
	}

	return 0;
}
