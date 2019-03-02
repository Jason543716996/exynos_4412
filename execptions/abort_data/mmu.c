#include <mmu.h>

void map_section(u32 *ttb, u32 va, u32 va_end, u32 pa)
{
	while (va < va_end) {
		CREATE_DESCRIPTOR(ttb, va, pa);	
		va += 0x100000;
		pa += 0x100000;
	}
}

void mmu_enable(u32 *ttb)
{
	__asm__ __volatile__(

		"mov r0, %[ttb]\n"
		"mcr p15, 0, r0, c2, c0, 0\n" //将转换表的起始地址写入C2

		"mvn r0, #0\n"
		"mcr p15, 0, r0, c3, c0, 0\n"

		"mrc p15, 0, r0, c1, c0, 0\n"
		"orr r0, #0x1\n" //enable mmu
		"orr r0, #(0x1 << 13)\n" //select high vector baseaddress as 0xffff0000
		"mcr p15, 0, r0, c1, c0, 0\n"

		:
		:[ttb]"r"(ttb)
		:"r0"
	);
}

/*根据exynos4412数据手册的编址做一对一映射*/
void global_map(u32 *ttb)
{
	map_section(ttb, 0x0, 0x8000000, 0x0);
	map_section(ttb, 0xce00000, 0x14000000, 0xce00000);
	map_section(ttb, 0x40000000, 0x80000000, 0x40000000);
	
	mmu_enable(ttb);
}

