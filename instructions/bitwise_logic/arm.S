
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
5000001c:	e3a00096 	mov	r0, #150	; 0x96
50000020:	e2007069 	and	r7, r0, #105	; 0x69
50000024:	e3806069 	orr	r6, r0, #105	; 0x69
50000028:	e2205069 	eor	r5, r0, #105	; 0x69
5000002c:	e3c04080 	bic	r4, r0, #128	; 0x80
50000030:	e320f000 	nop	{0}
50000034:	e50b7018 	str	r7, [fp, #-24]
50000038:	e50b601c 	str	r6, [fp, #-28]
5000003c:	e50b5020 	str	r5, [fp, #-32]
50000040:	e50b4024 	str	r4, [fp, #-36]	; 0x24
50000044:	e59f3040 	ldr	r3, [pc, #64]	; 5000008c <main+0x80>
50000048:	e59f0040 	ldr	r0, [pc, #64]	; 50000090 <main+0x84>
5000004c:	e51b1018 	ldr	r1, [fp, #-24]
50000050:	e12fff33 	blx	r3
50000054:	e59f3030 	ldr	r3, [pc, #48]	; 5000008c <main+0x80>
50000058:	e59f0034 	ldr	r0, [pc, #52]	; 50000094 <main+0x88>
5000005c:	e51b101c 	ldr	r1, [fp, #-28]
50000060:	e12fff33 	blx	r3
50000064:	e59f3020 	ldr	r3, [pc, #32]	; 5000008c <main+0x80>
50000068:	e59f0028 	ldr	r0, [pc, #40]	; 50000098 <main+0x8c>
5000006c:	e51b1020 	ldr	r1, [fp, #-32]
50000070:	e12fff33 	blx	r3
50000074:	e59f3010 	ldr	r3, [pc, #16]	; 5000008c <main+0x80>
50000078:	e59f001c 	ldr	r0, [pc, #28]	; 5000009c <main+0x90>
5000007c:	e51b1024 	ldr	r1, [fp, #-36]	; 0x24
50000080:	e12fff33 	blx	r3
50000084:	e24bd014 	sub	sp, fp, #20
50000088:	e8bd88f0 	pop	{r4, r5, r6, r7, fp, pc}
5000008c:	43e11a2c 	.word	0x43e11a2c
50000090:	500000a0 	.word	0x500000a0
50000094:	500000ac 	.word	0x500000ac
50000098:	500000b8 	.word	0x500000b8
5000009c:	500000c4 	.word	0x500000c4
