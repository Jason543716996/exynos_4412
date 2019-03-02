
arm:     file format elf32-littlearm


Disassembly of section .text:

50000000 <_start>:
50000000:	e92d5fff 	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
50000004:	eb000000 	bl	5000000c <main>
50000008:	e8bd9fff 	pop	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}

5000000c <main>:
5000000c:	e92d48f0 	push	{r4, r5, r6, r7, fp, lr}
50000010:	e28db014 	add	fp, sp, #20
50000014:	e24dd010 	sub	sp, sp, #16
50000018:	e320f000 	nop	{0}

5000001c <pc>:
5000001c:	e1a0700f 	mov	r7, pc

50000020 <next>:
50000020:	e320f000 	nop	{0}

50000024 <lable>:
50000024:	e320f000 	nop	{0}
50000028:	e59f6074 	ldr	r6, [pc, #116]	; 500000a4 <lable+0x80>
5000002c:	e59f5074 	ldr	r5, [pc, #116]	; 500000a8 <lable+0x84>
50000030:	e24f401c 	sub	r4, pc, #28
50000034:	e320f000 	nop	{0}
50000038:	e50b7018 	str	r7, [fp, #-24]
5000003c:	e50b601c 	str	r6, [fp, #-28]
50000040:	e50b5020 	str	r5, [fp, #-32]
50000044:	e50b4024 	str	r4, [fp, #-36]	; 0x24
50000048:	e59f3040 	ldr	r3, [pc, #64]	; 50000090 <lable+0x6c>
5000004c:	e59f0040 	ldr	r0, [pc, #64]	; 50000094 <lable+0x70>
50000050:	e51b1018 	ldr	r1, [fp, #-24]
50000054:	e12fff33 	blx	r3
50000058:	e59f3030 	ldr	r3, [pc, #48]	; 50000090 <lable+0x6c>
5000005c:	e59f0034 	ldr	r0, [pc, #52]	; 50000098 <lable+0x74>
50000060:	e51b101c 	ldr	r1, [fp, #-28]
50000064:	e12fff33 	blx	r3
50000068:	e59f3020 	ldr	r3, [pc, #32]	; 50000090 <lable+0x6c>
5000006c:	e59f0028 	ldr	r0, [pc, #40]	; 5000009c <lable+0x78>
50000070:	e51b1020 	ldr	r1, [fp, #-32]
50000074:	e12fff33 	blx	r3
50000078:	e59f3010 	ldr	r3, [pc, #16]	; 50000090 <lable+0x6c>
5000007c:	e59f001c 	ldr	r0, [pc, #28]	; 500000a0 <lable+0x7c>
50000080:	e51b1024 	ldr	r1, [fp, #-36]	; 0x24
50000084:	e12fff33 	blx	r3
50000088:	e24bd014 	sub	sp, fp, #20
5000008c:	e8bd88f0 	pop	{r4, r5, r6, r7, fp, pc}
50000090:	43e11a2c 	.word	0x43e11a2c
50000094:	500000ac 	.word	0x500000ac
50000098:	500000b8 	.word	0x500000b8
5000009c:	500000c4 	.word	0x500000c4
500000a0:	500000d4 	.word	0x500000d4
500000a4:	50000020 	.word	0x50000020
500000a8:	50000024 	.word	0x50000024
