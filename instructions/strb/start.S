@我们一起沁园春《雪》
//我们一起沁园春《雪》
/*我们一起沁园春《雪》*/
#if 0
我们一起沁园春《雪》
#endif
.align 2
.text 
.global _start

_start:
	stmfd sp!, {r0-r12, lr}
	bl main
	ldmfd sp!, {r0-r12, pc}


