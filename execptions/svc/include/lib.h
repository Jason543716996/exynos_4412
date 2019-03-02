#ifndef ARMBARE_H_
#define ARMBARE_H_

#define printf(...) (((int (*)(const char *, ...))0x43e11a2c)(__VA_ARGS__))
#define udelay(x)	((void (*)(int))0x43e26480)(x)

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern u32 ioread32(u32 reg);
extern void iowrite32(u32 val, u32 reg);
extern u8 ioread8(u32 reg);
extern void iowrite8(u8 val, u32 reg);
extern void *memcpy(void *dest, const void *src, u32 n);

#endif
