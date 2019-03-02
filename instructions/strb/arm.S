
arm:     file format elf32-littlearm


Disassembly of section .text:

50000000 <_start>:
50000000:	e92d5fff 	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
50000004:	eb000000 	bl	5000000c <main>
50000008:	e8bd9fff 	pop	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}

5000000c <main>:
5000000c:	e92d4800 	push	{fp, lr}
50000010:	e28db004 	add	fp, sp, #4
50000014:	e24dd008 	sub	sp, sp, #8
50000018:	e24b3008 	sub	r3, fp, #8
5000001c:	e320f000 	nop	{0}
50000020:	e1a00003 	mov	r0, r3
50000024:	e3a01056 	mov	r1, #86	; 0x56
50000028:	e4c01001 	strb	r1, [r0], #1
5000002c:	e3a01038 	mov	r1, #56	; 0x38
50000030:	e4c01001 	strb	r1, [r0], #1
50000034:	e3a01027 	mov	r1, #39	; 0x27
50000038:	e4c01001 	strb	r1, [r0], #1
5000003c:	e3a01095 	mov	r1, #149	; 0x95
50000040:	e4c01001 	strb	r1, [r0], #1
50000044:	e320f000 	nop	{0}
50000048:	e51b2008 	ldr	r2, [fp, #-8]
5000004c:	e59f3010 	ldr	r3, [pc, #16]	; 50000064 <main+0x58>
50000050:	e59f0010 	ldr	r0, [pc, #16]	; 50000068 <main+0x5c>
50000054:	e1a01002 	mov	r1, r2
50000058:	e12fff33 	blx	r3
5000005c:	e24bd004 	sub	sp, fp, #4
50000060:	e8bd8800 	pop	{fp, pc}
50000064:	43e11a2c 	.word	0x43e11a2c
50000068:	5000006c 	.word	0x5000006c
