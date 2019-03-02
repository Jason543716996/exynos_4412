
arm:     file format elf32-littlearm


Disassembly of section .text:

50000000 <_start>:
50000000:	e92d5fff 	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
50000004:	eb000000 	bl	5000000c <main>
50000008:	e8bd9fff 	pop	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}

5000000c <main>:
5000000c:	e92d4830 	push	{r4, r5, fp, lr}
50000010:	e28db00c 	add	fp, sp, #12
50000014:	e24dd028 	sub	sp, sp, #40	; 0x28
50000018:	e59f30b4 	ldr	r3, [pc, #180]	; 500000d4 <main+0xc8>
5000001c:	e24bc020 	sub	ip, fp, #32
50000020:	e893000f 	ldm	r3, {r0, r1, r2, r3}
50000024:	e88c000f 	stm	ip, {r0, r1, r2, r3}
50000028:	e24b3030 	sub	r3, fp, #48	; 0x30
5000002c:	e3a02000 	mov	r2, #0
50000030:	e5832000 	str	r2, [r3]
50000034:	e2833004 	add	r3, r3, #4
50000038:	e3a02000 	mov	r2, #0
5000003c:	e5832000 	str	r2, [r3]
50000040:	e2833004 	add	r3, r3, #4
50000044:	e3a02000 	mov	r2, #0
50000048:	e5832000 	str	r2, [r3]
5000004c:	e2833004 	add	r3, r3, #4
50000050:	e3a02000 	mov	r2, #0
50000054:	e5832000 	str	r2, [r3]
50000058:	e2833004 	add	r3, r3, #4
5000005c:	e24bc020 	sub	ip, fp, #32
50000060:	e24b5030 	sub	r5, fp, #48	; 0x30
50000064:	e320f000 	nop	{0}
50000068:	e1a0400c 	mov	r4, ip
5000006c:	e8b4000f 	ldm	r4!, {r0, r1, r2, r3}
50000070:	e1a04005 	mov	r4, r5
50000074:	e8a4000f 	stmia	r4!, {r0, r1, r2, r3}
50000078:	e320f000 	nop	{0}
5000007c:	e3a03000 	mov	r3, #0
50000080:	e50b3010 	str	r3, [fp, #-16]
50000084:	ea00000d 	b	500000c0 <main+0xb4>
50000088:	e51b2010 	ldr	r2, [fp, #-16]
5000008c:	e3e03023 	mvn	r3, #35	; 0x23
50000090:	e1a02102 	lsl	r2, r2, #2
50000094:	e24b100c 	sub	r1, fp, #12
50000098:	e0812002 	add	r2, r1, r2
5000009c:	e0823003 	add	r3, r2, r3
500000a0:	e5932000 	ldr	r2, [r3]
500000a4:	e59f302c 	ldr	r3, [pc, #44]	; 500000d8 <main+0xcc>
500000a8:	e59f002c 	ldr	r0, [pc, #44]	; 500000dc <main+0xd0>
500000ac:	e51b1010 	ldr	r1, [fp, #-16]
500000b0:	e12fff33 	blx	r3
500000b4:	e51b3010 	ldr	r3, [fp, #-16]
500000b8:	e2833001 	add	r3, r3, #1
500000bc:	e50b3010 	str	r3, [fp, #-16]
500000c0:	e51b3010 	ldr	r3, [fp, #-16]
500000c4:	e3530003 	cmp	r3, #3
500000c8:	daffffee 	ble	50000088 <main+0x7c>
500000cc:	e24bd00c 	sub	sp, fp, #12
500000d0:	e8bd8830 	pop	{r4, r5, fp, pc}
500000d4:	500000f0 	.word	0x500000f0
500000d8:	43e11a2c 	.word	0x43e11a2c
500000dc:	500000e0 	.word	0x500000e0
