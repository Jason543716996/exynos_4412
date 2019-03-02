#include <led.h>
#include <key.h>
#include <uart.h>
#include <lcd.h>
#include <font.h>

#define RED 0xff0000
#define BG  0x4E9A06

int main(void)
{
	char *words = "Happy New Year!!";
	int i = 0,val = 0;
	display_string(0, 229, words, RED);	
	while(1){
		for(i = 0;i < 480 - 22;i++){
			val = ioread32(VIDW00ADD0B0);
			val += 800*4;
			iowrite32(val, VIDW00ADD0B0);

			val = ioread32(VIDW00ADD1B0);
			val += 800*4;
			iowrite32(val, VIDW00ADD1B0);
		}
		for(i = 0;i < 480 - 22;i++){
			val = ioread32(VIDW00ADD0B0);
			val -= 800*4;
			iowrite32(val, VIDW00ADD0B0);

			val = ioread32(VIDW00ADD1B0);
			val -= 800*4;
			iowrite32(val, VIDW00ADD1B0);
		}
	}

	lcd_init();
	clr_screen(BG);


	return 0;
}
