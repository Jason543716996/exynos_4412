
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
5000001c:	e3a00038 	mov	r0, #56	; 0x38
50000020:	e1a04260 	ror	r4, r0, #4
50000024:	e1a07200 	lsl	r7, r0, #4
50000028:	e1a06227 	lsr	r6, r7, #4
5000002c:	e3e01025 	mvn	r1, #37	; 0x25
50000030:	e1a05041 	asr	r5, r1, #32
50000034:	e320f000 	nop	{0}
50000038:	e50b7018 	str	r7, [fp, #-24]
5000003c:	e50b601c 	str	r6, [fp, #-28]
50000040:	e50b5020 	str	r5, [fp, #-32]
50000044:	e50b4024 	str	r4, [fp, #-36]	; 0x24
50000048:	e59f3040 	ldr	r3, [pc, #64]	; 50000090 <main+0x84>
5000004c:	e59f0040 	ldr	r0, [pc, #64]	; 50000094 <main+0x88>
50000050:	e51b1018 	ldr	r1, [fp, #-24]
50000054:	e12fff33 	blx	r3
50000058:	e59f3030 	ldr	r3, [pc, #48]	; 50000090 <main+0x84>
5000005c:	e59f0034 	ldr	r0, [pc, #52]	; 50000098 <main+0x8c>
50000060:	e51b101c 	ldr	r1, [fp, #-28]
50000064:	e12fff33 	blx	r3
50000068:	e59f3020 	ldr	r3, [pc, #32]	; 50000090 <main+0x84>
5000006c:	e59f0028 	ldr	r0, [pc, #40]	; 5000009c <main+0x90>
50000070:	e51b1020 	ldr	r1, [fp, #-32]
50000074:	e12fff33 	blx	r3
50000078:	e59f3010 	ldr	r3, [pc, #16]	; 50000090 <main+0x84>
5000007c:	e59f001c 	ldr	r0, [pc, #28]	; 500000a0 <main+0x94>
50000080:	e51b1024 	ldr	r1, [fp, #-36]	; 0x24
50000084:	e12fff33 	blx	r3
50000088:	e24bd014 	sub	sp, fp, #20
5000008c:	e8bd88f0 	pop	{r4, r5, r6, r7, fp, pc}
50000090:	43e11a2c 	.word	0x43e11a2c
50000094:	500000a4 	.word	0x500000a4
50000098:	500000b0 	.word	0x500000b0
5000009c:	500000bc 	.word	0x500000bc
500000a0:	500000c8 	.word	0x500000c8
