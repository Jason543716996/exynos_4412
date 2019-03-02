#include <gic.h>

static do_irq_t gics[160];

/*中断发生后被核心响应执行*/
void do_irq(void)
{
	do_irq_t func;
	u32 irqid;
	/*拿到产生中断的中断号*/
	irqid = ioread32(ICCIAR_CPU0);

	/*根据中断号获取与中断号对应的处理函数，并调用处理函数*/
	func = gics[irqid&0x3ff];
	func();

	/*清除GIC对核心的中断转发*/
	iowrite32(irqid, ICCEOIR_CPU0);
}

/*中断请求之前做好准备设置*/
void irq_request_cpu0(int irqnum, do_irq_t func, int pri)
{
	u32 tmp;
	u32 index, area;

	/*根据中断号设置GIC控制器内部寄存器*/
	/*使能GIC和CPU0的接口*/
	iowrite32(1, ICCICR_CPU0);

	/*设置GIC要给CPU0所转发的中断优先级的一个阈值*/
	iowrite32(0xff, ICCPMR_CPU0);

	/*使能GIC监听及转发中断信号给核心*/
	iowrite32(1, ICDDCR);

	/*设置中断号为irqnum的优先级为pri*/
	index = irqnum/4;
	area  = irqnum%4;
	tmp = ioread32(ICDIPR0_CPU0 + index*4);
	tmp &= ~(0xff << (area*8));
	tmp |= pri << (area*8);
	iowrite32(tmp, ICDIPR0_CPU0 + index*4);

	/*转发中断信号给CPU0*/
	index = irqnum/4;
	area  = irqnum%4;
	tmp = ioread32(ICDIPTR0_CPU0 + index*4);
	tmp &= ~(0xff << (area*8));
	tmp |= (1 << (area*8));
	iowrite32(tmp, ICDIPTR0_CPU0 + index*4);

	/*使能中断号为irqnum的中断*/
	index = irqnum/32;
	area  = irqnum%32;
	tmp = ioread32(ICDISER0_CPU0 + index*4);
	tmp |= 1 << area; 
	iowrite32(tmp, ICDISER0_CPU0 + index*4);

	/*将与irqnum这个中断号对应的处理函数的地址存放到gics数组*/
	gics[irqnum] = func;	

	/*使能ARM核心对中断的响应，CPSR[7]: I*/
	__asm__ __volatile__(
		"mrs r0, cpsr\n"	
		"bic r0, #(1 << 7)\n" 
		"msr cpsr, r0\n"
	);
}
