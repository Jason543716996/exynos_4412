
arm:     file format elf32-littlearm


Disassembly of section .text:

50000000 <_start>:
50000000:	e92d5fff 	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
50000004:	eb000000 	bl	5000000c <main>
50000008:	e8bd9fff 	pop	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}

5000000c <main>:
5000000c:	e92d4830 	push	{r4, r5, fp, lr}
50000010:	e28db00c 	add	fp, sp, #12
50000014:	e24dd008 	sub	sp, sp, #8
50000018:	e320f000 	nop	{0}
5000001c:	e10f5000 	mrs	r5, CPSR
50000020:	e385020f 	orr	r0, r5, #-268435456	; 0xf0000000
50000024:	e129f000 	msr	CPSR_fc, r0
50000028:	e10f4000 	mrs	r4, CPSR
5000002c:	e320f000 	nop	{0}
50000030:	e50b5010 	str	r5, [fp, #-16]
50000034:	e50b4014 	str	r4, [fp, #-20]
50000038:	e59f3020 	ldr	r3, [pc, #32]	; 50000060 <main+0x54>
5000003c:	e59f0020 	ldr	r0, [pc, #32]	; 50000064 <main+0x58>
50000040:	e51b1010 	ldr	r1, [fp, #-16]
50000044:	e12fff33 	blx	r3
50000048:	e59f3010 	ldr	r3, [pc, #16]	; 50000060 <main+0x54>
5000004c:	e59f0014 	ldr	r0, [pc, #20]	; 50000068 <main+0x5c>
50000050:	e51b1014 	ldr	r1, [fp, #-20]
50000054:	e12fff33 	blx	r3
50000058:	e24bd00c 	sub	sp, fp, #12
5000005c:	e8bd8830 	pop	{r4, r5, fp, pc}
50000060:	43e11a2c 	.word	0x43e11a2c
50000064:	5000006c 	.word	0x5000006c
50000068:	50000078 	.word	0x50000078
