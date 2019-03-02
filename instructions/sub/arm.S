
arm:     file format elf32-littlearm


Disassembly of section .text:

50000000 <_start>:
50000000:	e92d5fff 	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
50000004:	eb000000 	bl	5000000c <main>
50000008:	e8bd9fff 	pop	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}

5000000c <main>:
5000000c:	e92d4870 	push	{r4, r5, r6, fp, lr}
50000010:	e28db010 	add	fp, sp, #16
50000014:	e24dd01c 	sub	sp, sp, #28
50000018:	e3a03d7d 	mov	r3, #8000	; 0x1f40
5000001c:	e50b3018 	str	r3, [fp, #-24]
50000020:	e3a03efa 	mov	r3, #4000	; 0xfa0
50000024:	e50b301c 	str	r3, [fp, #-28]
50000028:	e51b3018 	ldr	r3, [fp, #-24]
5000002c:	e51b201c 	ldr	r2, [fp, #-28]
50000030:	e320f000 	nop	{0}
50000034:	e3e00000 	mvn	r0, #0
50000038:	e2904058 	adds	r4, r0, #88	; 0x58
5000003c:	e0a34002 	adc	r4, r3, r2
50000040:	e320f000 	nop	{0}
50000044:	e50b6020 	str	r6, [fp, #-32]
50000048:	e50b5024 	str	r5, [fp, #-36]	; 0x24
5000004c:	e50b4028 	str	r4, [fp, #-40]	; 0x28
50000050:	e59f3010 	ldr	r3, [pc, #16]	; 50000068 <main+0x5c>
50000054:	e59f0010 	ldr	r0, [pc, #16]	; 5000006c <main+0x60>
50000058:	e51b1028 	ldr	r1, [fp, #-40]	; 0x28
5000005c:	e12fff33 	blx	r3
50000060:	e24bd010 	sub	sp, fp, #16
50000064:	e8bd8870 	pop	{r4, r5, r6, fp, pc}
50000068:	43e11a2c 	.word	0x43e11a2c
5000006c:	50000070 	.word	0x50000070
