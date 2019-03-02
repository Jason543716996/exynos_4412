
arm:     file format elf32-littlearm


Disassembly of section .text:

50000000 <_start>:
50000000:	e92d5fff 	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
50000004:	eb000000 	bl	5000000c <main>
50000008:	e8bd9fff 	pop	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}

5000000c <main>:
5000000c:	e92d4810 	push	{r4, fp, lr}
50000010:	e28db008 	add	fp, sp, #8
50000014:	e24dd00c 	sub	sp, sp, #12
50000018:	e320f000 	nop	{0}
5000001c:	ea000003 	b	50000030 <hehe>

50000020 <lala>:
50000020:	e2844001 	add	r4, r4, #1
50000024:	ea000005 	b	50000040 <end>

50000028 <haha>:
50000028:	e2444064 	sub	r4, r4, #100	; 0x64
5000002c:	e1a0f00e 	mov	pc, lr

50000030 <hehe>:
50000030:	e3a04064 	mov	r4, #100	; 0x64
50000034:	e1a0e00f 	mov	lr, pc
50000038:	e59ff028 	ldr	pc, [pc, #40]	; 50000068 <end+0x28>
5000003c:	eafffff7 	b	50000020 <lala>

50000040 <end>:
50000040:	e320f000 	nop	{0}
50000044:	e50b4010 	str	r4, [fp, #-16]
50000048:	e59f3010 	ldr	r3, [pc, #16]	; 50000060 <end+0x20>
5000004c:	e59f0010 	ldr	r0, [pc, #16]	; 50000064 <end+0x24>
50000050:	e51b1010 	ldr	r1, [fp, #-16]
50000054:	e12fff33 	blx	r3
50000058:	e24bd008 	sub	sp, fp, #8
5000005c:	e8bd8810 	pop	{r4, fp, pc}
50000060:	43e11a2c 	.word	0x43e11a2c
50000064:	5000006c 	.word	0x5000006c
50000068:	50000028 	.word	0x50000028
