#ifndef TINY4412_RTC_H_
#define TINY4412_RTC_H_

#include <lib.h>

#define INTP 		0x10070030 
#define RTCCON 		0x10070040 
#define TICCNT 		0x10070044 
#define RTCALM 		0x10070050 
#define ALMSEC 		0x10070054 
#define ALMMIN 		0x10070058 
#define ALMHOUR		0x1007005C 
#define ALMDAY 		0x10070060 
#define ALMMON 		0x10070064 
#define ALMYEAR		0x10070068 
#define BCDSEC 		0x10070070 
#define BCDMIN 		0x10070074 
#define BCDHOUR		0x10070078 
#define BCDDAY 		0x1007007C 
#define BCDDAYWEEK	0x10070080 
#define BCDMON 		0x10070084 
#define BCDYEAR 	0x10070088 
#define CURTICCNT 	0x10070090 

#define RTC_ALMID 76

struct rtc_time {
	int year;
	int mon;
	int day;
	int hor;
	int min;
	int sec;
	int dayweek;
};

extern struct rtc_time* getrtctime(struct rtc_time *t);
extern void setrtctime(const struct rtc_time *t);
extern void disrtctime(const struct rtc_time *t);
extern void rtc_alarm_set(struct rtc_time *t);
extern void tic_timer_init(int ms);

#endif
