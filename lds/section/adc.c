#include <adc.h>
#include <gic.h>

//#define ADC_IRQ_WAY 9527

#define ADCID 42

static u32 if_conv_ok = 0;
static u32 adc_val;

static void do_adc(void)
{
	/*clear中断*/	
	iowrite32(1, CLRINTADC);
	adc_val = ioread32(ADCDAT)&0xfff;
	if_conv_ok = 1;
}

void adc_init(void)
{
	u32 val;

	val = (1 << 16) | (1 << 14) | (99 << 6);
	iowrite32(val, ADCCON);

	iowrite32(0xffff, ADCDLY);
#ifdef ADC_IRQ_WAY	
	irq_request_cpu0(ADCID, do_adc, 0);

	/*使能ADC的中断*/
	val = ioread32(IESR2);
	val |= 1 << 19;
	iowrite32(val, IESR2);
#endif
}

int get_adc_val_irq(int channel)
{
	u32 val;
	int cnt;

	iowrite32(channel, ADCMUX);

	if_conv_ok = 0;

	/*启动ADC开始转换*/
	val = ioread32(ADCCON);
	val |= 1 << 0;
	iowrite32(val, ADCCON);

	cnt = 0;
	while(!if_conv_ok) {
		cnt++;
		udelay(1);
		if (cnt > 200) {
			return -1;
		}
	}	

	return adc_val;
}

int get_adc_val_polling(int channel)
{
	int cnt;
	u32 val;

	iowrite32(channel, ADCMUX);
	
	/*启动ADC开始转换*/
	val = ioread32(ADCCON);
	val |= 1 << 0;
	iowrite32(val, ADCCON);

	cnt = 0;
	do {
		val = ioread32(ADCCON);
		val &= 1 << 15;
		cnt++;
		udelay(1);
		if (cnt > 200) {
			return -1;
		}
	} while (!val);


	return ioread32(ADCDAT)&0xfff;
}
