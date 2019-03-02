
.align 2
.text
.global _start

_start:
	ldr sp, =0x02060000

	/* init system clock */
	bl      system_clock_init
	
	/* Memory initialize */
	bl      mem_ctrl_asm_init_r1

	/*copy and jump to bootloader*/
	bl jump_to_bootloader
step:
	b step
