
arm:     file format elf32-littlearm


Disassembly of section .text:

50000000 <_start>:
50000000:	e92d5fff 	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
50000004:	eb000000 	bl	5000000c <main>
50000008:	e8bd9fff 	pop	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}

5000000c <main>:
5000000c:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
50000010:	e28db000 	add	fp, sp, #0
50000014:	e320f000 	nop	{0}
50000018:	e3a000ff 	mov	r0, #255	; 0xff
5000001c:	e320f000 	nop	{0}
50000020:	e28bd000 	add	sp, fp, #0
50000024:	e8bd0800 	pop	{fp}
50000028:	e12fff1e 	bx	lr
