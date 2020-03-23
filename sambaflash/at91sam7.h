/************************************************************************
 * This program is free software; you can redistribute it and/or modify *
 * it under the terms of the GNU General Public License as published by *
 * the Free Software Foundation; either version 2 of the License, or    *
 * (at your option) any later version.                                  *
 *                                                                      *
 * Author: Yury Ovcharenko <amwsoft@gmail.com>                          *
 ************************************************************************/

#ifndef _AT91SYS_H
#define _AT91SYS_H

#define FLASH_START_ADDR	0x001000000
#define RAM_START_ADDR		0x002000000

#define DBGU_BASE	(struct DBGU_t *)0xFFFFF200
#define PIO_BASE	(struct PIO_t *)0xFFFFF400
#define PMC_BASE	(struct PMC_t *)0xFFFFFC00
#define MC_BASE		(struct MC_t *)0xFFFFFF00
#define EFC_BASE	(struct EFC_t *)0xFFFFFF60

struct DBGU_t {
	volatile unsigned long CR;
	volatile unsigned long MR;
	volatile unsigned long IER;
	volatile unsigned long IDR;
	volatile unsigned long IMR;
	volatile unsigned long SR;
	volatile unsigned long RHR;
	volatile unsigned long THR;
	volatile unsigned long BRGR;
};

struct PIO_t {
	volatile unsigned long PER;
	volatile unsigned long PDR;
	volatile unsigned long PSR;
	volatile unsigned long Reserved1;
	volatile unsigned long OER;
	volatile unsigned long ODR;
	volatile unsigned long OSR;
	volatile unsigned long Reserved2;
	volatile unsigned long IFER;
	volatile unsigned long IFDR;
	volatile unsigned long IFSR;
	volatile unsigned long Reserved3;
	volatile unsigned long SODR;
	volatile unsigned long CODR;
	volatile unsigned long ODSR;
	volatile unsigned long PDSR;
	volatile unsigned long IER;
	volatile unsigned long IDR;
	volatile unsigned long IMR;
	volatile unsigned long ISR;
	volatile unsigned long MDER;
	volatile unsigned long MDDR;
	volatile unsigned long MDSR;
	volatile unsigned long Reserved4;
	volatile unsigned long PUDR;
	volatile unsigned long PUER;
	volatile unsigned long PUSR;
	volatile unsigned long Reserved5;
	volatile unsigned long ASR;
	volatile unsigned long BSR;
	volatile unsigned long ABSR;
	volatile unsigned long Reserved6[9];
	volatile unsigned long OWER;
	volatile unsigned long OWDR;
	volatile unsigned long OWSR;
};

struct PMC_t {
	volatile unsigned long SCER;
	volatile unsigned long SCDR;
	volatile unsigned long SCSR;
	volatile unsigned long Reserved1;
	volatile unsigned long PCER;
	volatile unsigned long PCDR;
	volatile unsigned long PCSR;
	volatile unsigned long Reserved2;
	volatile unsigned long MOR;
	volatile unsigned long MCFR;
	volatile unsigned long Reserved3;
	volatile unsigned long PLLR;
	volatile unsigned long MCKR;
	volatile unsigned long Reserved4;
	volatile unsigned long Reserved5;
	volatile unsigned long PCK0;
	volatile unsigned long PCK1;
	volatile unsigned long Reserved6[6];
	volatile unsigned long IER;
	volatile unsigned long IDR;
	volatile unsigned long SR;
	volatile unsigned long IMR;
};

#define MC_FMR_FRDY		0x00000001
#define MC_FMR_LOCKE		0x00000004
#define MC_FMR_PROGE		0x00000008
#define MC_FMR_NEPB		0x00000080
#define MC_FMR_FWS_MASK		0x00000300
#define MC_FMR_FWS_SHIFT	8
#define MC_FMR_FMCN_MASK	0x00FF0000
#define MC_FMR_FMCN_SHIFT	16

#define MC_FCR_FCMD_NOP		0x00000000
#define MC_FCR_FCMD_WP		0x00000001
#define MC_FCR_FCMD_SLB		0x00000002
#define MC_FCR_FCMD_WPL		0x00000003
#define MC_FCR_FCMD_CLB		0x00000004
#define MC_FCR_FCMD_EA		0x00000008
#define MC_FCR_FCMD_SGPB	0x0000000B
#define MC_FCR_FCMD_CGPB	0x0000000D
#define MC_FCR_FCMD_SSB		0x0000000F
#define MC_FCR_PAGEN_MASK	0x0003FF00
#define MC_FCR_PAGEN_SHIFT	8
#define MC_FCR_KEY_MASK		0xFF000000
#define MC_FCR_KEY_SHIFT	24

#define MC_FSR_FRDY		0x00000001
#define MC_FSR_LOCKE		0x00000004
#define MC_FSR_PROGE		0x00000008
#define MC_FSR_SECURITY		0x00000010
#define MC_FSR_GPNVM0		0x00000100
#define MC_FSR_GPNVM1		0x00000200
#define MC_FSR_LOCK_MASK	0xFFFF0000
#define MC_FSR_LOCK_SHIFT	16
#define MC_FSR_LOCK0		0x00010000
#define MC_FSR_LOCK1		0x00020000
#define MC_FSR_LOCK2		0x00040000
#define MC_FSR_LOCK3		0x00080000
#define MC_FSR_LOCK4		0x00100000
#define MC_FSR_LOCK5		0x00200000
#define MC_FSR_LOCK6		0x00400000
#define MC_FSR_LOCK7		0x00800000
#define MC_FSR_LOCK8		0x01000000
#define MC_FSR_LOCK9		0x02000000
#define MC_FSR_LOCK10		0x04000000
#define MC_FSR_LOCK11		0x08000000
#define MC_FSR_LOCK12		0x10000000
#define MC_FSR_LOCK13		0x20000000
#define MC_FSR_LOCK14		0x40000000
#define MC_FSR_LOCK15		0x80000000

struct MC_t {
	volatile unsigned long MCR;
	volatile unsigned long ASR;
	volatile unsigned long AASR;
};

struct EFC_t {
	volatile unsigned long FMR;
	volatile unsigned long FCR;
	volatile unsigned long FSR;
};

#endif
