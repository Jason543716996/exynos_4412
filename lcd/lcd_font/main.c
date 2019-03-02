#include <led.h>
#include <key.h>
#include <uart.h>
#include <lcd.h>
#include <font.h>

#define RED 0xff0000
#define BG  0x4E9A06

void change_buf(int n)
{
	if (!n) {
		iowrite32(FRAMBUFF0, VIDW00ADD0B0);
		iowrite32(FRAMBUFF0 + 800*480*4, VIDW00ADD1B0);
	} else {
		iowrite32(FRAMBUFF1, VIDW00ADD0B0);
		iowrite32(FRAMBUFF1 + 800*480*4, VIDW00ADD1B0);
	}
}

int main(void)
{
	char *words = "Happy New Year!!";
	int i = 799;
	int buf_flag;

	lcd_init();

	clr_screen(0, BG);
	clr_screen(1, BG);

	buf_flag = 1;
	display_string_buf(0, i, 229, words, BG);	

	while (1) {
		if (buf_flag) {
			change_buf(0);
			udelay(1000);
			display_string_buf(1, i+1, 229, words, BG);	
			i--;
			if (i < 0) {
				i = 799;
			}
			display_string_buf(1, i, 229, words, RED);	
		} else {
			change_buf(1);
			udelay(1000);
			display_string_buf(0, i+1, 229, words, BG);	
			i --;
			if (i < 0) {
				i = 799;
			}
			display_string_buf(0, i, 229, words, RED);	
		}
		buf_flag ^= 1;
	}

	return 0;
}
