
.align 2
.text
.global _start

_start:
	b  reset				@0x0
	ldr     pc, _undefined_instruction	@0x4
	ldr     pc, _software_interrupt
	ldr     pc, _prefetch_abort
	ldr     pc, _data_abort
	nop					@0x14
	ldr     pc, _irq
	ldr     pc, _fiq			@0x1c

_undefined_instruction: .word undefined_instruction
_software_interrupt:    .word software_interrupt
_prefetch_abort:        .word prefetch_abort
_data_abort:            .word data_abort
_irq:                   .word irq 
_fiq:                   .word fiq 

reset:
	stmfd sp!, {r0-r12, lr}
	bl main
	ldmfd sp!, {r0-r12, pc}

undefined_instruction:
	ldr sp, =0x7e200000
	stmfd sp!, {r0-r12, lr}
	bl do_unde
	ldmfd sp!, {r0-r12, pc}^
software_interrupt:

prefetch_abort:

data_abort:

irq:

fiq:

.global all_end
all_end:
