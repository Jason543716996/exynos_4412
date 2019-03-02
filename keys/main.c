#include <led.h>
#include <key.h>

void do_api_key(int stat, int num)
{
	if (stat == DOWN) {
		switch (num) {
			case 1:
				printf("shot ...\n");
				break;
			case 2:
				printf("stop shot...\n");
				break;
			case 3:
				printf("shot again...\n");
				break;
			case 4:
				printf("fire to dead all...\n");
				break;
		}
	} else if (stat == UP){
		printf("game over with key%d...\n", num);	
	} else {
		printf("what???\n");
	}
}

int main(void)
{
	key_init();

	while (1) {
		check_key_dnup(do_api_key);	
	}

	return 0;
}
