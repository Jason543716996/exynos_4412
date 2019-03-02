#include <led.h>
#include <key.h>
#include <uart.h>

#define SZ 1024 

int main(void)
{
	int c;
	char buf[SZ];

	uart0_init();
#if 0
	while ((c = ugetchar()) != '@') {
		uputchar('\n');
		uputchar(c);
	}

	uputs(ugets(buf));
#endif
	uprintf("\nThe lesson is finished...\n");

	return 0;
}
