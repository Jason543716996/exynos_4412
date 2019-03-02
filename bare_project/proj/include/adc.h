#ifndef ADC_H_
#define ADC_H_

#include <lib.h>

#define ADCCON 		0x126c0000 
#define ADCDLY 		0x126c0008
#define ADCDAT 		0x126c000C
#define CLRINTADC 	0x126c0018 
#define ADCMUX 		0x126c001C 

#define IESR2		0x10440020

extern void adc_init(void);
extern int get_adc_val_irq(int channel);
extern int get_adc_val_polling(int channel);

#endif
