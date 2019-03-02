
arm:     file format elf32-littlearm


Disassembly of section .text:

50000000 <_start>:
50000000:	e92d5fff 	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
50000004:	eb000003 	bl	50000018 <main>
50000008:	e8bd9fff 	pop	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}

5000000c <array>:
5000000c:	00009527 	andeq	r9, r0, r7, lsr #10
50000010:	00003856 	andeq	r3, r0, r6, asr r8
50000014:	00007788 	andeq	r7, r0, r8, lsl #15

50000018 <main>:
50000018:	e92d48f0 	push	{r4, r5, r6, r7, fp, lr}
5000001c:	e28db014 	add	fp, sp, #20
50000020:	e24dd010 	sub	sp, sp, #16
50000024:	e320f000 	nop	{0}
50000028:	e59f007c 	ldr	r0, [pc, #124]	; 500000ac <main+0x94>
5000002c:	e4907004 	ldr	r7, [r0], #4
50000030:	e4906004 	ldr	r6, [r0], #4
50000034:	e5905000 	ldr	r5, [r0]
50000038:	e51f4034 	ldr	r4, [pc, #-52]	; 5000000c <array>
5000003c:	e320f000 	nop	{0}
50000040:	e50b7018 	str	r7, [fp, #-24]
50000044:	e50b601c 	str	r6, [fp, #-28]
50000048:	e50b5020 	str	r5, [fp, #-32]
5000004c:	e50b4024 	str	r4, [fp, #-36]	; 0x24
50000050:	e59f3040 	ldr	r3, [pc, #64]	; 50000098 <main+0x80>
50000054:	e59f0040 	ldr	r0, [pc, #64]	; 5000009c <main+0x84>
50000058:	e51b1018 	ldr	r1, [fp, #-24]
5000005c:	e12fff33 	blx	r3
50000060:	e59f3030 	ldr	r3, [pc, #48]	; 50000098 <main+0x80>
50000064:	e59f0034 	ldr	r0, [pc, #52]	; 500000a0 <main+0x88>
50000068:	e51b101c 	ldr	r1, [fp, #-28]
5000006c:	e12fff33 	blx	r3
50000070:	e59f3020 	ldr	r3, [pc, #32]	; 50000098 <main+0x80>
50000074:	e59f0028 	ldr	r0, [pc, #40]	; 500000a4 <main+0x8c>
50000078:	e51b1020 	ldr	r1, [fp, #-32]
5000007c:	e12fff33 	blx	r3
50000080:	e59f3010 	ldr	r3, [pc, #16]	; 50000098 <main+0x80>
50000084:	e59f001c 	ldr	r0, [pc, #28]	; 500000a8 <main+0x90>
50000088:	e51b1024 	ldr	r1, [fp, #-36]	; 0x24
5000008c:	e12fff33 	blx	r3
50000090:	e24bd014 	sub	sp, fp, #20
50000094:	e8bd88f0 	pop	{r4, r5, r6, r7, fp, pc}
50000098:	43e11a2c 	.word	0x43e11a2c
5000009c:	500000b0 	.word	0x500000b0
500000a0:	500000bc 	.word	0x500000bc
500000a4:	500000c8 	.word	0x500000c8
500000a8:	500000d4 	.word	0x500000d4
500000ac:	5000000c 	.word	0x5000000c
