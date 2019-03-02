
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
50000018:	e3a03000 	mov	r3, #0
5000001c:	e50b3010 	str	r3, [fp, #-16]
50000020:	e3a03001 	mov	r3, #1
50000024:	e50b3014 	str	r3, [fp, #-20]
50000028:	e3a03064 	mov	r3, #100	; 0x64
5000002c:	e50b3018 	str	r3, [fp, #-24]
50000030:	e51b3014 	ldr	r3, [fp, #-20]
50000034:	e51b2018 	ldr	r2, [fp, #-24]
50000038:	e51b1010 	ldr	r1, [fp, #-16]
5000003c:	e1a04001 	mov	r4, r1
50000040:	e320f000 	nop	{0}
50000044:	e1a00003 	mov	r0, r3

50000048 <guohao>:
50000048:	e1500002 	cmp	r0, r2
5000004c:	ca000003 	bgt	50000060 <end>
50000050:	e0844000 	add	r4, r4, r0
50000054:	e2800001 	add	r0, r0, #1
50000058:	eafffffa 	b	50000048 <guohao>
5000005c:	e320f000 	nop	{0}

50000060 <end>:
50000060:	e50b4010 	str	r4, [fp, #-16]
50000064:	e59f3010 	ldr	r3, [pc, #16]	; 5000007c <end+0x1c>
50000068:	e59f0010 	ldr	r0, [pc, #16]	; 50000080 <end+0x20>
5000006c:	e51b1010 	ldr	r1, [fp, #-16]
50000070:	e12fff33 	blx	r3
50000074:	e24bd008 	sub	sp, fp, #8
50000078:	e8bd8810 	pop	{r4, fp, pc}
5000007c:	43e11a2c 	.word	0x43e11a2c
50000080:	50000084 	.word	0x50000084
