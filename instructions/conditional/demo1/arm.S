
arm:     file format elf32-littlearm


Disassembly of section .text:

50000000 <_start>:
50000000:	e92d5fff 	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
50000004:	eb000000 	bl	5000000c <main>
50000008:	e8bd9fff 	pop	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}

5000000c <main>:
5000000c:	e92d4810 	push	{r4, fp, lr}
50000010:	e28db008 	add	fp, sp, #8
50000014:	e24dd014 	sub	sp, sp, #20
50000018:	e59f3044 	ldr	r3, [pc, #68]	; 50000064 <main+0x58>
5000001c:	e50b3010 	str	r3, [fp, #-16]
50000020:	e59f303c 	ldr	r3, [pc, #60]	; 50000064 <main+0x58>
50000024:	e50b3014 	str	r3, [fp, #-20]
50000028:	e51b3010 	ldr	r3, [fp, #-16]
5000002c:	e51b2014 	ldr	r2, [fp, #-20]
50000030:	e320f000 	nop	{0}
50000034:	e1530002 	cmp	r3, r2
50000038:	c3a04001 	movgt	r4, #1
5000003c:	b3e04000 	mvnlt	r4, #0
50000040:	03a04000 	moveq	r4, #0
50000044:	e320f000 	nop	{0}
50000048:	e50b4018 	str	r4, [fp, #-24]
5000004c:	e59f3014 	ldr	r3, [pc, #20]	; 50000068 <main+0x5c>
50000050:	e59f0014 	ldr	r0, [pc, #20]	; 5000006c <main+0x60>
50000054:	e51b1018 	ldr	r1, [fp, #-24]
50000058:	e12fff33 	blx	r3
5000005c:	e24bd008 	sub	sp, fp, #8
50000060:	e8bd8810 	pop	{r4, fp, pc}
50000064:	00013880 	.word	0x00013880
50000068:	43e11a2c 	.word	0x43e11a2c
5000006c:	50000070 	.word	0x50000070
