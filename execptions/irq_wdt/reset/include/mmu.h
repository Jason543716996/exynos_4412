#ifndef MMU_H_
#define MMU_H_

#include <lib.h>

/*
	TTB: 代表按照段映射的转换表的起始地址, 理解成u32 *类型。
 	VA： 代表要按照段映射的1M字节空间的虚拟地址
	PA： VA要映射到的物理地址
 */
#define CREATE_DESCRIPTOR(TTB, VA, PA)  \
		TTB[VA>>20] = ((PA&0xfff00000) | 0x2)

/*
 	ttb: 转换表的起始地址
	va： 虚拟地址
	sz：要映射的大小
	pa：va对应的映射物理地址
 */
extern void map_section(u32 *ttb, u32 va, u32 sz, u32 pa);

extern void global_map(u32 *ttb);

/*通过设置C1，C2， C3，实现MMU功能*/
extern void mmu_enable(u32 *ttb);

#endif
