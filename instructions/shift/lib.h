#ifndef ARMBARE_H_
#define ARMBARE_H_

#define printf(...) (((int (*)(const char *, ...))0x43e11a2c)(__VA_ARGS__))

#endif
