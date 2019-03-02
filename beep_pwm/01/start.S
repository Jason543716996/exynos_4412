
.align 2
.text
.global _start

_start:
	b  reset				@0x0
	ldr     pc, _undefined_instruction	@0x4
	ldr     pc, _software_interrupt
	ldr     pc, _prefetch_abort
	ldr     pc, _data_abort			@0x10
	nop					@0x14
	ldr     pc, _irq
	ldr     pc, _fiq			@0x1c

_undefined_instruction: .word undefined_instruction
_software_interrupt:    .word software_interrupt
_prefetch_abort:        .word prefetch_abort
_data_abort:            .word data_abort
_irq:                   .word irq 
_fiq:                   .word fiq 

@svc mode
reset:
	stmfd sp!, {r0-r12, lr}

	@change mode to irq
	mrs r0, cpsr
	bic r0, #0x1f
	orr r0, #0x12
	msr cpsr, r0

	ldr sp, =0x7e400000

	@change mode to svc
	mrs r0, cpsr
	bic r0, #0x1f
	orr r0, #0x13
	msr cpsr, r0

	bl main
	ldmfd sp!, {r0-r12, pc}

undefined_instruction:
	ldr sp, =0x7e200000
	stmfd sp!, {r0-r12, lr}
	bl do_unde
	ldmfd sp!, {r0-r12, pc}^

software_interrupt:

	stmfd sp!, {r0-r12, lr}
	sub lr, #4
	ldr r0, [lr]
	and r0, #0xffffff
	bl do_svc
	ldmfd sp!, {r0-r12, pc}^

prefetch_abort:

data_abort:
	ldr sp, =0x7e300000
	sub lr, #4
	stmfd sp!, {r0-r12, lr}
	bl do_data_abt
	ldmfd sp!, {r0-r12, pc}^

irq:
	sub lr, #4
	stmfd sp!, {r0-r12, lr}
	bl do_irq
	ldmfd sp!, {r0-r12, pc}^

fiq:

.global all_end
all_end:
