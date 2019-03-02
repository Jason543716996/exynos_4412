#include <iic.h>
#include <gic.h>
#include <tp.h>

/*触摸屏中断处理函数*/
void do_tp(void)
{
	int i;
	char data[31];
	int val;

	val = ioread32(EXT_INT41_PEND);
	iowrite32(val, EXT_INT41_PEND);

	/*以主收模式读取ft5206触摸屏控制模块内部32个寄存器的值*/
	if ((i = read_data(data, sizeof(data))) == -2) 
	{
		if ((i = read_data(data, sizeof(data))) == -2)
		{
			printf("no ack\n");	
			return;
		}
	}

	if (i == -1) {
		return;
	}
	printf("i = %d\n", i);

	if (data[2] <= 0)
		return;

	printf("points=%d: ", data[2]&0xf);

	for (i = 0; i < (data[2]&0xf); i++)
	{
		printf("(x%d=%d,y%d=%d); ", i, ((data[i*6+3]&0xf)<<8)|\
		data[i*6+4], i, ((data[i*6+5]&0xf)<<8)|data[i*6+6]);
	}
	printf("\n\n");
}

/*设置XEINT14和GPX1[6]相连的引脚为外部中断专用，设置外部中断的相关功能*/
void tp_int_init(void)
{
	int val;

	/*设置GPX1[6] 为外部中断专用*/
	val = ioread32(GPX1CON);
	val |= 0xf << 24; //GPX1_6 [24:27] EXT_INT41
	iowrite32(val, GPX1CON);

	/*设置GPX1[6]引脚的中断触发方式为下降沿*/
	val = ioread32(EXT_INT41CON);
	val &= ~(0x7 << 24); //[24:26]
	val |= 2 << 24;	 //irq's trigger is failing edge
	iowrite32(val, EXT_INT41CON);

	/*设置INT41[6]使能滤波，选择数字滤波，设置滤波的周期总个数*/
	val = ioread32(EXT_INT41_FLTCON1);
	val |= 0xff<<16;
	iowrite32(val, EXT_INT41_FLTCON1);

	/*使能外部中断INT41[6]*/
	val = ioread32(EXT_INT41_MASK);
	val &= ~(1 << 6); //enable irq
	iowrite32(val, EXT_INT41_MASK);

#define TP_IRQ 62
	irq_request_cpu0(TP_IRQ, do_tp, 0);
	
	/*初始化I2C控制器1*/
	iic1_init();
}
