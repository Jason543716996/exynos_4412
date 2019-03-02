#ifndef XCM_LIB_H_
#define XCM_LIB_H_

#define printf(...)  (((int (*)(const char *, ...))0x43e11a2c)(__VA_ARGS__))

//int (*printf)(const char *, ...) = (void *)0x43e11a2c;

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern void delay(u32 n);
extern int strcmp(const char *s1, const char *s2);

#endif
