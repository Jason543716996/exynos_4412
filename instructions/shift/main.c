#include <lib.h>

void main(void)
{
	int lsl, lsr, asr, ror;

	__asm__ __volatile__(
		"nop\n"

		"mov r0, #0x38\n"
		"ror %[ror], r0, #4\n"
		"lsl %[lsl], r0, #4\n"
		"lsr %[lsr], %[lsl], #4\n"

		"mov r1, #-38\n"
		"asr %[asr], r1, #32\n"

		"nop"

		:[lsl]"=&r"(lsl),[lsr]"=&r"(lsr),[asr]"=&r"(asr), [ror]"=&r"(ror)
		:
		:"r0","r1"
	);

	printf("lsl: %#x\n", lsl);
	printf("lsr: %#x\n", lsr);
	printf("asr: %#x\n", asr);
	printf("ror: %#x\n", ror);
}
