@--------------------------------------------------------
@ This program is free software; you can redistribute it and/or modify
@ it under the terms of the GNU General Public License as published by
@ the Free Software Foundation; either version 2 of the License, or
@ (at your option) any later version.
@
@ Author: Yury Ovcharenko <amwsoft@gmail.com>
@--------------------------------------------------------
@	
@--------------------------------------------------------
@	PIO controller
#ifdef	DEBUG_MODE
#define	PIO_BASE	0xFFFFF400

#define	PIO_PER		0x00
#define	PIO_PDR		0x04
#define	PIO_PSR		0x08

#define	PIO_OER		0x10
#define	PIO_ODR		0x14
#define	PIO_OSR		0x18

#define	PIO_IFER	0x20
#define	PIO_IFDR	0x24
#define	PIO_IFSR	0x28

#define	PIO_SODR	0x30
#define	PIO_CODR	0x34
#define	PIO_ODSR	0x38
#define	PIO_PDSR	0x3C

#define	PIO_IER		0x40
#define	PIO_IDR		0x44
#define	PIO_IMR		0x48
#define	PIO_ISR		0x4C

#define	PIO_MDER	0x50
#define	PIO_MDDR	0x54
#define	PIO_MDSR	0x58

#define	PIO_PUDR	0x60
#define	PIO_PUER	0x64
#define	PIO_PUSR	0x68

#define	PIO_ASR		0x70
#define	PIO_BSR		0x74
#define	PIO_ABSR	0x78

#define	PIO_OWER	0xA0
#define	PIO_OWDR	0xA4
#define	PIO_OWSR	0xA8

#endif /* DEBUG_MODE */
@--------------------------------------------------------
	.section .text
	.code	32
	.arm
@--------------------------------------------------------
@	Entry point
	.global _start
_start:
@--------------------------------------------------------
@ Setup stack
	ldr	sp, =_stack
@ Save SAM-BA return address
	stmdb	sp!, {lr}
@--------------------------------------------------------
#ifdef	DEBUG_MODE
	ldr	r0, =PIO_BASE

	mov	r1, #0x07
	str	r1, [r0, #PIO_PER]
	str	r1, [r0, #PIO_OER]
	str	r1, [r0, #PIO_IFDR]
	str	r1, [r0, #PIO_SODR]
	str	r1, [r0, #PIO_IDR]
	str	r1, [r0, #PIO_MDDR]
	str	r1, [r0, #PIO_PUDR]
	str	r1, [r0, #PIO_OWER]
	
	mov	r1, #0
	str	r1, [r0, #PIO_PDR]
	str	r1, [r0, #PIO_ODR]
	str	r1, [r0, #PIO_IFER]
	str	r1, [r0, #PIO_CODR]
	str	r1, [r0, #PIO_IER]
	str	r1, [r0, #PIO_MDER]
	str	r1, [r0, #PIO_PUER]
	str	r1, [r0, #PIO_ASR]
	str	r1, [r0, #PIO_BSR]
	str	r1, [r0, #PIO_OWDR]
#endif	/* DEBUG_MODE */
@--------------------------------------------------------
@	Test condition 1
#ifdef	DEBUG_MODE
	ldr	r0, =PIO_BASE
	mov	r1, #6
	str	r1, [r0, #PIO_ODSR]
#endif	/* DEBUG_MODE */
@--------------------------------------------------------
@ Initialize .data section
_data_init:
	ldr	r1, =_etext
	ldr	r2, =_data
	ldr	r3, =_edata
_data_reloc:
	cmp	r2, r3
	ldrlo	r0, [r1], #4
	strlo	r0, [r2], #4
	blo	_data_reloc
@--------------------------------------------------------
@	Test condition 2
#ifdef	DEBUG_MODE
	ldr	r0, =PIO_BASE
	mov	r1, #5
	str	r1, [r0, #PIO_ODSR]
#endif	/* DEBUG_MODE */
@--------------------------------------------------------
@ Clear .bss section
_bss_init:
	mov     r0, #0
	ldr     r1, =__bss_start__
	ldr     r2, =__bss_end__
_bss_zero:
	cmp	r1, r2
	strlo	r0, [r1], #4
	blo	_bss_zero
@--------------------------------------------------------
@	Test condition 3
#ifdef	DEBUG_MODE
	ldr	r0, =PIO_BASE
	mov	r1, #3
	str	r1, [r0, #PIO_ODSR]
#endif	/* DEBUG_MODE */
@--------------------------------------------------------
@ Call main
	bl	main
	ldr	r1, =_retval
	str	r0, [r1]
@--------------------------------------------------------
@	Return value from main()
#ifdef	DEBUG_MODE
	ldr	r1, =PIO_BASE
	str	r0, [r1, #PIO_ODSR]
#endif	/* DEBUG_MODE */
@--------------------------------------------------------
@ Restore SAM-BA return address
	ldmia	sp!, {r0}^
@ Return to SAM-BA
	bx	r0
@--------------------------------------------------------
