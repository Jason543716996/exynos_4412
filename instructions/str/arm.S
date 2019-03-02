
arm:     file format elf32-littlearm


Disassembly of section .text:

50000000 <_start>:
50000000:	e92d5fff 	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
50000004:	eb000000 	bl	5000000c <main>
50000008:	e8bd9fff 	pop	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}

5000000c <main>:
5000000c:	e92d4800 	push	{fp, lr}
50000010:	e28db004 	add	fp, sp, #4
50000014:	e24dd010 	sub	sp, sp, #16
50000018:	e24b3014 	sub	r3, fp, #20
5000001c:	e3a02000 	mov	r2, #0
50000020:	e5832000 	str	r2, [r3]
50000024:	e2833004 	add	r3, r3, #4
50000028:	e3a02000 	mov	r2, #0
5000002c:	e5832000 	str	r2, [r3]
50000030:	e2833004 	add	r3, r3, #4
50000034:	e3a02000 	mov	r2, #0
50000038:	e5832000 	str	r2, [r3]
5000003c:	e2833004 	add	r3, r3, #4
50000040:	e24b3014 	sub	r3, fp, #20
50000044:	e320f000 	nop	{0}
50000048:	e1a00003 	mov	r0, r3
5000004c:	e3a0105f 	mov	r1, #95	; 0x5f
50000050:	e4801004 	str	r1, [r0], #4
50000054:	e3a01053 	mov	r1, #83	; 0x53
50000058:	e4801004 	str	r1, [r0], #4
5000005c:	e3a01026 	mov	r1, #38	; 0x26
50000060:	e5801000 	str	r1, [r0]
50000064:	e320f000 	nop	{0}
50000068:	e3a03000 	mov	r3, #0
5000006c:	e50b3008 	str	r3, [fp, #-8]
50000070:	ea00000d 	b	500000ac <main+0xa0>
50000074:	e51b2008 	ldr	r2, [fp, #-8]
50000078:	e3e0300f 	mvn	r3, #15
5000007c:	e1a02102 	lsl	r2, r2, #2
50000080:	e24b1004 	sub	r1, fp, #4
50000084:	e0812002 	add	r2, r1, r2
50000088:	e0823003 	add	r3, r2, r3
5000008c:	e5932000 	ldr	r2, [r3]
50000090:	e59f3028 	ldr	r3, [pc, #40]	; 500000c0 <main+0xb4>
50000094:	e59f0028 	ldr	r0, [pc, #40]	; 500000c4 <main+0xb8>
50000098:	e51b1008 	ldr	r1, [fp, #-8]
5000009c:	e12fff33 	blx	r3
500000a0:	e51b3008 	ldr	r3, [fp, #-8]
500000a4:	e2833001 	add	r3, r3, #1
500000a8:	e50b3008 	str	r3, [fp, #-8]
500000ac:	e51b3008 	ldr	r3, [fp, #-8]
500000b0:	e3530002 	cmp	r3, #2
500000b4:	daffffee 	ble	50000074 <main+0x68>
500000b8:	e24bd004 	sub	sp, fp, #4
500000bc:	e8bd8800 	pop	{fp, pc}
500000c0:	43e11a2c 	.word	0x43e11a2c
500000c4:	500000c8 	.word	0x500000c8
