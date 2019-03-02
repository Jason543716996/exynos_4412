#include <uart.h>
#include <stdarg.h>

void uart0_init(void)
{
	u32 val;

	/*set GPA0_0, GPA0_1 as UART_0_TXD and UART_0_RXD*/
	val = ioread32(GPA0CON);
	val &= ~0xff;
	val |= 0x22;
	iowrite32(val, GPA0CON);

	/*UART*/
	/*8N1*/
	iowrite32(0x3, ULCON0);
	
	/*set R/T mode as polling*/
	iowrite32(0x5, UCON0);

	/*disable FIFO, select NOFIFO MODE*/
	iowrite32(0x0, UFCON0);

	/*disable AFC*/
	iowrite32(0x0, UMCON0);

	/*set Baudrate 115200*/
	iowrite32(53, UBRDIV0);
	iowrite32(4, UFRACVAL0);
}

static void wait_transmit_buffer_empty(void)
{
	int val;

	do {
		val = ioread32(UTRSTAT0);
		val >>= 1;
		val &= 1;
	} while (!val);
}

void uputchar(int c)
{
	wait_transmit_buffer_empty();

	iowrite8(c, UTXH0);

	if (c == '\n') {
		uputchar('\r');
	}
}

static void wait_receive_buffer_valid(void)
{
	int val;
	do {
		val = ioread32(UTRSTAT0);
		val &= 1;
	} while (!val);
}

int ugetchar(void)
{
	int c;

	wait_receive_buffer_valid();
	c = ioread8(URXH0);

	if (c == '\r') {
		c = '\n';
	}

	uputchar(c);

	return c;
}

char *ugets(char *b)
{
	int c;

	char *tmp = b;
	while ((c = ugetchar()) != '\n') {
		*b++ = c;
	}
	*b = '\0';

	return tmp;
}

void uputs(const char *s)
{
	while (*s) {
		uputchar(*s);
		s++;
	}
}

void uprintf(const char *fmt, ...)
{
	int val;
	va_list ap;
	char buf[128];

	va_start(ap, fmt);

	while (*fmt) {
		if (*fmt != '%') {
			uputchar(*fmt);
		} else {
			fmt++;
			switch (*fmt) {
			case 'd':
				val = va_arg(ap, int);
				if (val < 0) {
					uputchar('-');
					val = 0 - val;
				}
			//	itoa(val, buf);
				uputs(buf);
				break;
			case 'x':
				val = va_arg(ap, int);
			//	xtoa(val, buf);
				uputs(buf);
				break;
			case 's':
				uputs(va_arg(ap, char *));
				break;
			case 'c':
				uputchar(va_arg(ap, int));
				break;
			}
		}
		fmt++;
	}

	va_end(ap);
}
