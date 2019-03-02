#include <vector.h>
#include <mmu.h>

void cp_vector_table(u32 *ttb,  u32 phy_vectorbase)
{
	CREATE_DESCRIPTOR(ttb, 0xffff0000, phy_vectorbase);	
	global_map(ttb);	
	memcpy((void *)0xffff0000, &_start, (&all_end - &_start)*4);
}
