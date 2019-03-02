
arm:     file format elf32-littlearm


Disassembly of section .text:

50000000 <_start>:
50000000:	e92d5ff0 	push	{r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
50000004:	eb000016 	bl	50000064 <main>
50000008:	e8bd9ff0 	pop	{r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}

5000000c <demo_func>:
5000000c:	e1a0c00d 	mov	ip, sp
50000010:	e92dd800 	push	{fp, ip, lr, pc}
50000014:	e24cb004 	sub	fp, ip, #4


5000005c:	e24bd00c 	sub	sp, fp, #12
50000060:	e89da800 	ldm	sp, {fp, sp, pc}

50000064 <main>:
50000064:	e1a0c00d 	mov	ip, sp
50000068:	e92dd9f0 	push	{r4, r5, r6, r7, r8, fp, ip, lr, pc}
5000006c:	e24cb004 	sub	fp, ip, #4
50000070:	e24dd014 	sub	sp, sp, #20
50000074:	e3a00001 	mov	r0, #1
50000078:	e3a01002 	mov	r1, #2
5000007c:	e3a02003 	mov	r2, #3
50000080:	e3a03004 	mov	r3, #4
50000084:	e3a05005 	mov	r5, #5
50000088:	e3a06006 	mov	r6, #6
5000008c:	e92d0060 	push	{r5, r6}
50000090:	ebffffdd 	bl	5000000c <demo_func>
50000094:	e1a08000 	mov	r8, r0
50000098:	e50b8028 	str	r8, [fp, #-40]	; 0x28
5000009c:	e50b702c 	str	r7, [fp, #-44]	; 0x2c
500000a0:	e50b4030 	str	r4, [fp, #-48]	; 0x30
500000a4:	e59f3024 	ldr	r3, [pc, #36]	; 500000d0 <main+0x6c>
500000a8:	e59f0024 	ldr	r0, [pc, #36]	; 500000d4 <main+0x70>
500000ac:	e51b1028 	ldr	r1, [fp, #-40]	; 0x28
500000b0:	e12fff33 	blx	r3
500000b4:	e59f3014 	ldr	r3, [pc, #20]	; 500000d0 <main+0x6c>
500000b8:	e59f0018 	ldr	r0, [pc, #24]	; 500000d8 <main+0x74>
500000bc:	e51b102c 	ldr	r1, [fp, #-44]	; 0x2c
500000c0:	e51b2030 	ldr	r2, [fp, #-48]	; 0x30
500000c4:	e12fff33 	blx	r3
500000c8:	e24bd020 	sub	sp, fp, #32
500000cc:	e89da9f0 	ldm	sp, {r4, r5, r6, r7, r8, fp, sp, pc}
500000d0:	43e11a2c 	.word	0x43e11a2c
500000d4:	500000dc 	.word	0x500000dc
500000d8:	500000e8 	.word	0x500000e8
