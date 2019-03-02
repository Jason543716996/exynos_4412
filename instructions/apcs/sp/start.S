.align 2
.text 
.global _start

_start:
	stmfd sp!, {r4-r12, lr}
	bl main
	ldmfd sp!, {r4-r12, pc}


