#define GPM4BASE  0x11000000
#define GPM4CON   0x2e0
#define GPM4DAT   0x2e4

.align 2
.text
.global _start

_start:
	
	mov ip, sp
	push {fp, ip, lr, pc}
	sub fp, ip, #4

	@set GPM4[0:3] as output
	ldr r0, =GPM4BASE
	ldr r1, [r0, #GPM4CON]
	bic r1, #0xff
	bic r1, #0xff00
	orr r1, #0x11
	orr r1, #0x1100
	str r1, [r0, #GPM4CON]

	@loop turn on led
	ldr r0, =GPM4BASE
	mov r2, #1		//
	mov r1, #0		//i = 0;
loop:
	lsl r3, r2, r1		//1 << 0;
	mvn r3, r3		//~1  = 0xfffffffe;
	ldr r4, [r0, #GPM4DAT] 
	orr r4, #0xf
	and r4, r3
	str r4, [r0, #GPM4DAT] 

	add r1, #1
	cmp r1, #4
	moveq r1, #0

	bl delay

	b loop

	sub sp, fp, #12
	ldm sp, {fp, sp, pc}
delay:
	stmfd sp!, {r0-r12, lr}

	ldr r0, =0x15273856
	mov r1, #0
loopdelay:
	cmp r1, r0
	beq end
	add r1, #1
	b loopdelay
end:
	ldmfd sp!, {r0-r12, pc}
