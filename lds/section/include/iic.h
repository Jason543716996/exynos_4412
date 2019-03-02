#ifndef TINY4412_IIC_H_
#define TINY4412_IIC_H_

#include <lib.h>

#define GPD1CON	0x114000c0

#define I2CCON 	0x13870000 
#define I2CSTAT 0x13870004 
#define I2CADD 	0x13870008
#define I2CDS 	0x1387000C

extern void iic1_init(void);
extern int read_data(char *data, int len);
extern void do_tp(void);

#endif
