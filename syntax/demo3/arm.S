
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
50000018:	e3a03016 	mov	r3, #22
5000001c:	e50b3018 	str	r3, [fp, #-24]
50000020:	e3a03017 	mov	r3, #23
50000024:	e50b301c 	str	r3, [fp, #-28]
50000028:	e3a03018 	mov	r3, #24
5000002c:	e50b3020 	str	r3, [fp, #-32]
50000030:	e51b3018 	ldr	r3, [fp, #-24]
50000034:	e51bc01c 	ldr	ip, [fp, #-28]
50000038:	e51be020 	ldr	lr, [fp, #-32]
5000003c:	e320f000 	nop	{0}
50000040:	e1a00003 	mov	r0, r3
50000044:	e1a06000 	mov	r6, r0
50000048:	e1a0100c 	mov	r1, ip
5000004c:	e1a05001 	mov	r5, r1
50000050:	e1a0200e 	mov	r2, lr
50000054:	e1a04002 	mov	r4, r2
50000058:	e320f000 	nop	{0}
5000005c:	e50b6024 	str	r6, [fp, #-36]	; 0x24
50000060:	e50b5028 	str	r5, [fp, #-40]	; 0x28
50000064:	e50b402c 	str	r4, [fp, #-44]	; 0x2c
50000068:	e51b3018 	ldr	r3, [fp, #-24]
5000006c:	e51bc01c 	ldr	ip, [fp, #-28]
50000070:	e51be020 	ldr	lr, [fp, #-32]
50000074:	e320f000 	nop	{0}
50000078:	e1a00003 	mov	r0, r3
5000007c:	e1a06000 	mov	r6, r0
50000080:	e1a0100c 	mov	r1, ip
50000084:	e1a05001 	mov	r5, r1
50000088:	e1a0200e 	mov	r2, lr
5000008c:	e1a04002 	mov	r4, r2
50000090:	e320f000 	nop	{0}
50000094:	e50b6024 	str	r6, [fp, #-36]	; 0x24
50000098:	e50b5028 	str	r5, [fp, #-40]	; 0x28
5000009c:	e50b402c 	str	r4, [fp, #-44]	; 0x2c
500000a0:	e51b3018 	ldr	r3, [fp, #-24]
500000a4:	e51bc01c 	ldr	ip, [fp, #-28]
500000a8:	e51be020 	ldr	lr, [fp, #-32]
500000ac:	e320f000 	nop	{0}
500000b0:	e1a00003 	mov	r0, r3
500000b4:	e1a06000 	mov	r6, r0
500000b8:	e1a0100c 	mov	r1, ip
500000bc:	e1a05001 	mov	r5, r1
500000c0:	e1a0200e 	mov	r2, lr
500000c4:	e1a04002 	mov	r4, r2
500000c8:	e320f000 	nop	{0}
500000cc:	e50b6024 	str	r6, [fp, #-36]	; 0x24
500000d0:	e50b5028 	str	r5, [fp, #-40]	; 0x28
500000d4:	e50b402c 	str	r4, [fp, #-44]	; 0x2c
500000d8:	e59f3030 	ldr	r3, [pc, #48]	; 50000110 <main+0x104>
500000dc:	e59f0030 	ldr	r0, [pc, #48]	; 50000114 <main+0x108>
500000e0:	e51b1024 	ldr	r1, [fp, #-36]	; 0x24
500000e4:	e12fff33 	blx	r3
500000e8:	e59f3020 	ldr	r3, [pc, #32]	; 50000110 <main+0x104>
500000ec:	e59f0024 	ldr	r0, [pc, #36]	; 50000118 <main+0x10c>
500000f0:	e51b1028 	ldr	r1, [fp, #-40]	; 0x28
500000f4:	e12fff33 	blx	r3
500000f8:	e59f3010 	ldr	r3, [pc, #16]	; 50000110 <main+0x104>
500000fc:	e59f0018 	ldr	r0, [pc, #24]	; 5000011c <main+0x110>
50000100:	e51b102c 	ldr	r1, [fp, #-44]	; 0x2c
50000104:	e12fff33 	blx	r3
50000108:	e24bd010 	sub	sp, fp, #16
5000010c:	e8bd8870 	pop	{r4, r5, r6, fp, pc}
50000110:	43e11a2c 	.word	0x43e11a2c
50000114:	50000120 	.word	0x50000120
50000118:	5000012c 	.word	0x5000012c
5000011c:	50000138 	.word	0x50000138
