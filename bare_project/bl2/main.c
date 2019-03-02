
#define EXTERNAL_FUNC_ADDRESS 0x02020030

typedef unsigned int u32;

#define SDMMC_ReadBlocks(uStartBlk, uNumOfBlks, uDstAddr)       \
	        (((void(*)(u32, u32, u32*))(*((u32 *)EXTERNAL_FUNC_ADDRESS)))(uStartBlk, uNumOfBlks, uDstAddr))


void jump_to_bootloader(void)
{
	void (*jump) (void) = (void *)0x43e00000;

	/*copy bootloader from sdcard to ddrsdram*/
	SDMMC_ReadBlocks(49, 656, (u32 *)0x43e00000);

	/*jump to ddrsdram*/
	jump();
}
