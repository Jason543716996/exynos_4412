
arm:     file format elf32-littlearm


Disassembly of section .text:

50000000 <_start>:
50000000:	e92d5ff0 	push	{r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
50000004:	eb00000a 	bl	50000034 <main>
50000008:	e8bd9ff0 	pop	{r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}

5000000c <demo_func>:
5000000c:	e59f0050 	ldr	r0, [pc, #80]	; 50000064 <main+0x30>
50000010:	e59f1016 	ldr	r1, [pc, #22]	; 5000002e <data>
50000014:	e1a0e00f 	mov	lr, pc
50000018:	e59ff048 	ldr	pc, [pc, #72]	; 50000068 <main+0x34>

5000001c <str>:
5000001c:	2077654e 	.word	0x2077654e
50000020:	72616579 	.word	0x72616579
50000024:	70616820 	.word	0x70616820
50000028:	25207970 	.word	0x25207970
5000002c:	0064      	.short	0x0064

5000002e <data>:
5000002e:	07e2      	.short	0x07e2
50000030:	0000      	.short	0x0000
	...

50000034 <main>:
50000034:	e1a0c00d 	mov	ip, sp
50000038:	e92dd800 	push	{fp, ip, lr, pc}
5000003c:	e24cb004 	sub	fp, ip, #4
50000040:	ebfffff1 	bl	5000000c <demo_func>
50000044:	e59f300c 	ldr	r3, [pc, #12]	; 50000058 <main+0x24>
50000048:	e59f000c 	ldr	r0, [pc, #12]	; 5000005c <main+0x28>
5000004c:	e59f100c 	ldr	r1, [pc, #12]	; 50000060 <main+0x2c>
50000050:	e12fff33 	blx	r3
50000054:	e89da800 	ldm	sp, {fp, sp, pc}
50000058:	43e11a2c 	.word	0x43e11a2c
5000005c:	5000006c 	.word	0x5000006c
50000060:	50000080 	.word	0x50000080
50000064:	5000001c 	.word	0x5000001c
50000068:	43e11a2c 	.word	0x43e11a2c
