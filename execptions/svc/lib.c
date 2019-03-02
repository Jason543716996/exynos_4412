#include <lib.h>

u32 ioread32(u32 reg)
{
	return (*(volatile u32 *)reg);
}

void iowrite32(u32 val, u32 reg)
{
	(*(volatile u32 *)reg) = val;
}

u8 ioread8(u32 reg)
{
	return (*(volatile u8 *)reg);
}

void iowrite8(u8 val, u32 reg)
{
	(*(volatile u8 *)reg) = val;
}

void *memcpy(void *dest, const void *src, u32 n)
{
	char *dst = dest;
	const char *sou = src;

	while (n--) {
		*dst++ = *sou++;
	}

	return dest;
}
