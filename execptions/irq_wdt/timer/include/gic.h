#ifndef TINY4412_GIC_H_
#define TINY4412_GIC_H_

#include <lib.h>

#define ICCICR_CPU0	0x10480000
#define ICCPMR_CPU0	0x10480004
#define ICCIAR_CPU0	0x1048000c
#define ICCEOIR_CPU0	0x10480010
#define ICDDCR		0x10490000

#define ICDIPR0_CPU0	0x10490400
#define ICDIPTR0_CPU0	0x10490800
#define ICDISER0_CPU0	0x10490100

typedef void (*do_irq_t)(void);

/*
   本函数根木中断ID设置GIC的监测、转发中断的属性；
   将准备的中断处理函数地址放到和中断ID相关的函数指针数组里。
   使能CPU核心对中断的处理。

   @irqnum: 中断源的中断ID
   @func ： 和中断源对应的中断处理函数
   @pri  :  中断优先级
 */
extern void irq_request_cpu0(int irqnum, do_irq_t func, int pri);

#endif
