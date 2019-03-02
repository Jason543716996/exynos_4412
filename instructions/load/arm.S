
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
50000018:	e59f2068 	ldr	r2, [pc, #104]	; 50000088 <main+0x7c>
5000001c:	e24b302c 	sub	r3, fp, #44	; 0x2c
50000020:	e8920007 	ldm	r2, {r0, r1, r2}
50000024:	e8830007 	stm	r3, {r0, r1, r2}
50000028:	e24b302c 	sub	r3, fp, #44	; 0x2c
5000002c:	e320f000 	nop	{0}
50000030:	e1a00003 	mov	r0, r3
50000034:	e5906000 	ldr	r6, [r0]
50000038:	e5b05004 	ldr	r5, [r0, #4]!
5000003c:	e5904004 	ldr	r4, [r0, #4]
50000040:	e320f000 	nop	{0}
50000044:	e50b6018 	str	r6, [fp, #-24]
50000048:	e50b501c 	str	r5, [fp, #-28]
5000004c:	e50b4020 	str	r4, [fp, #-32]
50000050:	e59f3034 	ldr	r3, [pc, #52]	; 5000008c <main+0x80>
50000054:	e59f0034 	ldr	r0, [pc, #52]	; 50000090 <main+0x84>
50000058:	e51b1018 	ldr	r1, [fp, #-24]
5000005c:	e12fff33 	blx	r3
50000060:	e59f3024 	ldr	r3, [pc, #36]	; 5000008c <main+0x80>
50000064:	e59f0028 	ldr	r0, [pc, #40]	; 50000094 <main+0x88>
50000068:	e51b101c 	ldr	r1, [fp, #-28]
5000006c:	e12fff33 	blx	r3
50000070:	e59f3014 	ldr	r3, [pc, #20]	; 5000008c <main+0x80>
50000074:	e59f001c 	ldr	r0, [pc, #28]	; 50000098 <main+0x8c>
50000078:	e51b1020 	ldr	r1, [fp, #-32]
5000007c:	e12fff33 	blx	r3
50000080:	e24bd010 	sub	sp, fp, #16
50000084:	e8bd8870 	pop	{r4, r5, r6, fp, pc}
50000088:	500000c0 	.word	0x500000c0
5000008c:	43e11a2c 	.word	0x43e11a2c
50000090:	5000009c 	.word	0x5000009c
50000094:	500000a8 	.word	0x500000a8
50000098:	500000b4 	.word	0x500000b4
