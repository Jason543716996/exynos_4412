
arm:     file format elf32-littlearm


Disassembly of section .text:

50000000 <_start>:
50000000:	e92d5fff 	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
50000004:	eb000000 	bl	5000000c <main>
50000008:	e8bd9fff 	pop	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}

5000000c <main>:
5000000c:	e92d4830 	push	{r4, r5, fp, lr}
50000010:	e28db00c 	add	fp, sp, #12
50000014:	e24dd010 	sub	sp, sp, #16
50000018:	e3a0304e 	mov	r3, #78	; 0x4e
5000001c:	e50b3010 	str	r3, [fp, #-16]
50000020:	e3a0304e 	mov	r3, #78	; 0x4e
50000024:	e50b3014 	str	r3, [fp, #-20]
50000028:	e3a03016 	mov	r3, #22
5000002c:	e50b3018 	str	r3, [fp, #-24]
50000030:	e3a03021 	mov	r3, #33	; 0x21
50000034:	e50b301c 	str	r3, [fp, #-28]
50000038:	e51b3018 	ldr	r3, [fp, #-24]
5000003c:	e51b201c 	ldr	r2, [fp, #-28]
50000040:	e320f000 	nop	{0}
50000044:	e3a0505f 	mov	r5, #95	; 0x5f
50000048:	e1a04002 	mov	r4, r2
5000004c:	e320f000 	nop	{0}
50000050:	e50b5010 	str	r5, [fp, #-16]
50000054:	e50b4014 	str	r4, [fp, #-20]
50000058:	e59f3020 	ldr	r3, [pc, #32]	; 50000080 <main+0x74>
5000005c:	e59f0020 	ldr	r0, [pc, #32]	; 50000084 <main+0x78>
50000060:	e51b1010 	ldr	r1, [fp, #-16]
50000064:	e12fff33 	blx	r3
50000068:	e59f3010 	ldr	r3, [pc, #16]	; 50000080 <main+0x74>
5000006c:	e59f0014 	ldr	r0, [pc, #20]	; 50000088 <main+0x7c>
50000070:	e51b1014 	ldr	r1, [fp, #-20]
50000074:	e12fff33 	blx	r3
50000078:	e24bd00c 	sub	sp, fp, #12
5000007c:	e8bd8830 	pop	{r4, r5, fp, pc}
50000080:	43e11a2c 	.word	0x43e11a2c
50000084:	5000008c 	.word	0x5000008c
50000088:	50000098 	.word	0x50000098
