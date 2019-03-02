#ifndef VECTOR_H_
#define VECTOR_H_

#include <lib.h>

/*MMU的转换表地址*/
#define TTB_BASE      0x7e000000

/*异常矢量基地址要映射到的物理地址*/
#define VECTOR_BASE  0x7e1f0000 

extern u32 _start;
extern u32 all_end;

/*创建异常矢量表*/
extern void cp_vector_table(u32 *ttb,  u32 phy_vectorbase);

#endif
