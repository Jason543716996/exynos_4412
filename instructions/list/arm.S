
arm:     file format elf32-littlearm


Disassembly of section .text:

50000000 <_start>:
50000000:	e92d5fff 	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
50000004:	eb000000 	bl	5000000c <main>
50000008:	e8bd9fff 	pop	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}

5000000c <main>:
5000000c:	e92d4810 	push	{r4, fp, lr}
50000010:	e28db008 	add	fp, sp, #8
50000014:	e24dd024 	sub	sp, sp, #36	; 0x24
50000018:	e24b3018 	sub	r3, fp, #24
5000001c:	e24b2020 	sub	r2, fp, #32
50000020:	e24bc028 	sub	ip, fp, #40	; 0x28
50000024:	e320f000 	nop	{0}
50000028:	e1a04003 	mov	r4, r3
5000002c:	e1a00003 	mov	r0, r3
50000030:	e59f1084 	ldr	r1, [pc, #132]	; 500000bc <main+0xb0>
50000034:	e4801004 	str	r1, [r0], #4
50000038:	e1a01002 	mov	r1, r2
5000003c:	e5801000 	str	r1, [r0]
50000040:	e59f0078 	ldr	r0, [pc, #120]	; 500000c0 <main+0xb4>
50000044:	e4810004 	str	r0, [r1], #4
50000048:	e1a0000c 	mov	r0, ip
5000004c:	e5810000 	str	r0, [r1]
50000050:	e59f106c 	ldr	r1, [pc, #108]	; 500000c4 <main+0xb8>
50000054:	e4801004 	str	r1, [r0], #4
50000058:	e3a01000 	mov	r1, #0
5000005c:	e5801000 	str	r1, [r0]
50000060:	e320f000 	nop	{0}
50000064:	e50b4010 	str	r4, [fp, #-16]
50000068:	ea000008 	b	50000090 <main+0x84>
5000006c:	e51b3010 	ldr	r3, [fp, #-16]
50000070:	e5932000 	ldr	r2, [r3]
50000074:	e59f3034 	ldr	r3, [pc, #52]	; 500000b0 <main+0xa4>
50000078:	e59f0034 	ldr	r0, [pc, #52]	; 500000b4 <main+0xa8>
5000007c:	e1a01002 	mov	r1, r2
50000080:	e12fff33 	blx	r3
50000084:	e51b3010 	ldr	r3, [fp, #-16]
50000088:	e5933004 	ldr	r3, [r3, #4]
5000008c:	e50b3010 	str	r3, [fp, #-16]
50000090:	e51b3010 	ldr	r3, [fp, #-16]
50000094:	e3530000 	cmp	r3, #0
50000098:	1afffff3 	bne	5000006c <main+0x60>
5000009c:	e59f300c 	ldr	r3, [pc, #12]	; 500000b0 <main+0xa4>
500000a0:	e59f0010 	ldr	r0, [pc, #16]	; 500000b8 <main+0xac>
500000a4:	e12fff33 	blx	r3
500000a8:	e24bd008 	sub	sp, fp, #8
500000ac:	e8bd8810 	pop	{r4, fp, pc}
500000b0:	43e11a2c 	.word	0x43e11a2c
500000b4:	500000c8 	.word	0x500000c8
500000b8:	500000d0 	.word	0x500000d0
500000bc:	00009527 	.word	0x00009527
500000c0:	00003856 	.word	0x00003856
500000c4:	00007788 	.word	0x00007788
