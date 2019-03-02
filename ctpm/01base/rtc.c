#include <rtc.h>
#include <gic.h>

/*将二进制数据转换为BCD码*/
u8 bin2bcd(u32 n)
{
	return (n%10) | ((n/10) << 4);		
}

/*转换BCD码为二进制*/
u32 bcd2bin(u8 n)
{
	return (n&0xf) + ((n>>4)&0xf)*10;
}

struct rtc_time* getrtctime(struct rtc_time *t)
{
	int v;

	v = ioread32(BCDYEAR)&0xff;
	t->year = bcd2bin(v);
	v = ioread32(BCDMON)&0x1f;	
	t->mon  = bcd2bin(v);
	v = ioread32(BCDDAY)&0x3f;
	t->day = bcd2bin(v);
	v = ioread32(BCDHOUR)&0x3f;
	t->hor = bcd2bin(v);
	v = ioread32(BCDMIN)&0x7f;
	t->min = bcd2bin(v);
	v = ioread32(BCDSEC)&0x7f;
	t->sec = bcd2bin(v);
	v = ioread32(BCDDAYWEEK)&0x7;
	t->dayweek = bcd2bin(v);
	
	return t;
}

void setrtctime(const struct rtc_time *t)
{
	int val;
	int v;

	/*使能对BCD开头的寄存器的写权限*/
	val = ioread32(RTCCON);
	val |= 1;
	iowrite32(val, RTCCON);

	v = bin2bcd(t->year);
	iowrite32(v, BCDYEAR);

	v = bin2bcd(t->mon);
	iowrite32(v, BCDMON);

	v = bin2bcd(t->day);
	iowrite32(v, BCDDAY);
	
	v = bin2bcd(t->hor);
	iowrite32(v, BCDHOUR);
	
	v = bin2bcd(t->min);
	iowrite32(v, BCDMIN);

	v = bin2bcd(t->sec);
	iowrite32(v, BCDSEC);

	v = bin2bcd(t->dayweek);
	iowrite32(v, BCDDAYWEEK);
	
	/*禁用对BCD开头的寄存器的写权限*/
	val = ioread32(RTCCON);
	val &= ~1;
	iowrite32(val, RTCCON);
}

void disrtctime(const struct rtc_time *t)
{
	printf("----- 20%02d year %02d month -----\n", t->year, t->mon);
	printf("----- day: %02d, week: %d -----\n", t->day, t->dayweek);
	printf("%02dh-%02dm-%2ds\n", t->hor, t->min, t->sec);
}

#define RTC_TICID 77 

static int i = 0;
static int alarm_flag = 0;

/*rtc的TIC定时处理函数*/
void do_tic(void)
{
	int v;
	struct rtc_time t;

	v = ioread32(INTP);

	if (v&0x1) {
		getrtctime(&t);
		disrtctime(&t);
		iowrite32(v, INTP); //清除tic中断

		if (alarm_flag) {
			i++;
			if (i == 20) {
				i = 0;
				alarm_flag = 0;
				printf("shut up dididi...\n");
			}
		}
	}
}

/*每个ms产生滴答定时中断*/
void tic_timer_init(int ms)
{
	int v = 33*ms - 1; 
	iowrite32(v, TICCNT);	

	v = ioread32(RTCCON);
	v |= 1 << 8;
	iowrite32(v, RTCCON);

	irq_request_cpu0(RTC_TICID, do_tic, 0);
}

void do_alarm(void)
{
	int val;

	val = ioread32(INTP);
	if (val&0x2) {
		alarm_flag = 1;
		printf("alarm ...dididi...dididi...\n");
		iowrite32(val, INTP);
	}
}

void rtc_alarm_set(struct rtc_time *t)
{
	int val;

	/*设置闹钟考虑时分秒, 使能闹钟*/
	iowrite32((0x7 | (1 << 6)), RTCALM);	

	val = bin2bcd(t->sec);
	iowrite32(val, ALMSEC);

	val = bin2bcd(t->min);
	iowrite32(val, ALMMIN);

	val = bin2bcd(t->hor);
	iowrite32(val, ALMHOUR);

	irq_request_cpu0(RTC_ALMID, do_alarm, 0);
}
