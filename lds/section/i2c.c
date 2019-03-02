#include <iic.h>
#include <gic.h>
#include <lib.h>
#include <tp.h>

//将ctpm和4412相连的两个引脚设置成I2C_1_SCL 
//和 I2C_1_SDA专用。
static void iic1_gpio_init(void)
{
	int val;

	val = ioread32(GPD1CON);
	val &= ~(0xff << 8);
	val |= 0x22 << 8;
	iowrite32(val, GPD1CON);
}

/* iic1初始化设置 */
void iic1_init(void)
{
	int val;
	/* 将触摸屏控制模块的输出引脚所连接的GPIO口
 	   设置为IIC总线的sclk和sdat专用*/
	iic1_gpio_init();
		
	/* 对PCLK进行分频得到sclk的一个频率，使能收发中断*/
	val = (1<<7)|(1<<6)|(1<<5); //196KHz
	iowrite32(val, I2CCON);
	/*使能收发数据*/ 
	val = 1 << 4; //Flowcharts of Operations in Each Mode 3
	iowrite32(val, I2CSTAT);	
}


void resume_iic_scl(void)
{
	int val;
	val = ioread32(I2CCON);
	val &= ~(1<<4);
	iowrite32(val, I2CCON);
}

/*如果返回值为0说明发送成功
              1说明发送失败
*/
int wait_until_iic_irq(void)
{
	int i;
	int val;

	#define MAX_WAIT  0x3fff

	for (i = 0; i < MAX_WAIT; i++)
	{	
		val = ioread32(I2CCON);

		if (val & (1<<4))	
			return 0;
	}
	return -1;
}

void mxcdelay(int val)
{
        val *= 66; 

        while (val--)
                ;   
}

/*read_data: 从ft5206读取len个字节的数据存放在data指向的地址*/
int read_data(char *data, int len)
{
	int val;
	int i, ret = -1;
/*测试得到的从机(ft5206)地址*/
#define DEV_ADDR 0x38

	iowrite32((DEV_ADDR<<1)|1, I2CDS); //从机地址和读命令先放到I2CDS寄存器
	iowrite32(0xb0, I2CSTAT);
	resume_iic_scl();
	if (wait_until_iic_irq() < 0)
		goto END;

	val = ioread32(I2CSTAT);
	if (val & 1)
	{
		ret = -2;  //no ack
		goto END;
	}
	
	for (i = 0; i < len; i++)
	{
		resume_iic_scl();
		/*通过查询模式判断I2C控制器的中断是否发生，发生说明有可读数据*/
		if (wait_until_iic_irq() < 0)
			goto END;
		val = ioread32(I2CDS);	
		data[i] = val;
	}		
	ret = i;

END:
	iowrite32(0x90, I2CSTAT); // stop signal
	resume_iic_scl();
	mxcdelay(1000);
	
	return ret;
}

