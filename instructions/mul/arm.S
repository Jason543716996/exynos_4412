
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
50000018:	e3a03d7d 	mov	r3, #8000	; 0x1f40
5000001c:	e50b3010 	str	r3, [fp, #-16]
50000020:	e3a03efa 	mov	r3, #4000	; 0xfa0
50000024:	e50b3014 	str	r3, [fp, #-20]
50000028:	e51b3010 	ldr	r3, [fp, #-16]
5000002c:	e51b2014 	ldr	r2, [fp, #-20]
50000030:	e320f000 	nop	{0}
50000034:	e0040293 	mul	r4, r3, r2
50000038:	e320f000 	nop	{0}
5000003c:	e50b4018 	str	r4, [fp, #-24]
50000040:	e59f3010 	ldr	r3, [pc, #16]	; 50000058 <main+0x4c>
50000044:	e59f0010 	ldr	r0, [pc, #16]	; 5000005c <main+0x50>
50000048:	e51b1018 	ldr	r1, [fp, #-24]
5000004c:	e12fff33 	blx	r3
50000050:	e24bd008 	sub	sp, fp, #8
50000054:	e8bd8810 	pop	{r4, fp, pc}
50000058:	43e11a2c 	.word	0x43e11a2c
5000005c:	50000060 	.word	0x50000060
