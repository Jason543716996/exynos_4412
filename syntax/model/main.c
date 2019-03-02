#define printf(...) (((int (*)(const char *, ...))0x43e11a2c)(__VA_ARGS__))

void main(void)
{
	printf("hello, snow ...\n");
}
