
arm:     file format elf32-littlearm


Disassembly of section .text:

50000000 <_start>:
50000000:	e92d5ff0 	push	{r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
50000004:	eb000000 	bl	5000000c <main>
50000008:	e8bd9ff0 	pop	{r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}

5000000c <main>:
5000000c:	e1a0c00d 	mov	ip, sp
50000010:	e92dd800 	push	{fp, ip, lr, pc}
50000014:	e24cb004 	sub	fp, ip, #4
50000018:	e24ddc02 	sub	sp, sp, #512	; 0x200
5000001c:	e24bd00c 	sub	sp, fp, #12
50000020:	e89da800 	ldm	sp, {fp, sp, pc}
