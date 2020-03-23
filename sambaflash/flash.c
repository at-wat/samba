/************************************************************************
 * This program is free software; you can redistribute it and/or modify *
 * it under the terms of the GNU General Public License as published by *
 * the Free Software Foundation; either version 2 of the License, or    *
 * (at your option) any later version.                                  *
 *                                                                      *
 * Author: Yury Ovcharenko <amwsoft@gmail.com>                          *
 ************************************************************************/

#include "at91sam7.h"
#include "flash.h"
#include "serial.h"
#include "funcs.h"

void flash_init()
{
	struct EFC_t *EFC = EFC_BASE;

	while (!(EFC->FSR & MC_FSR_FRDY));
	EFC->FMR = (MC_FMR_FMCN_MASK & (100 << MC_FMR_FMCN_SHIFT)) | (1 < MC_FMR_FWS_SHIFT);
	while (!(EFC->FSR & MC_FSR_FRDY));
}

int flash_writepage(unsigned long *addr, unsigned long *buf, unsigned long pagesize)
{
	int retval;
	int i;
	unsigned long fsr;
	unsigned long page = (((unsigned long) addr)  & FLASH_ADDR_MASK) / pagesize;
	struct EFC_t *EFC = EFC_BASE;
	
	for (i = 0; i < (pagesize >> 2); i++)
		addr[i] = buf[i];
	
	while(!(EFC->FSR & MC_FSR_FRDY)) {;}
	retval = flash_unlock(addr, pagesize);
	if (retval < 0)
		return retval;
	EFC->FCR = (0x5A << MC_FCR_KEY_SHIFT) | (page << MC_FCR_PAGEN_SHIFT) | (MC_FCR_FCMD_WP);
	while(!((fsr = EFC->FSR) & MC_FSR_FRDY)) {;}
	fsr |= EFC->FSR;
	if (fsr & MC_FSR_PROGE)
		return -1;
	if (fsr & MC_FSR_LOCKE)
		return -2;
	
	return 0;
}

int flash_unlock(unsigned long *addr, unsigned long pagesize)
{
	unsigned long fsr;
	struct EFC_t *EFC = EFC_BASE;
	unsigned long page = (((unsigned long) addr) & FLASH_ADDR_MASK) / pagesize;
	unsigned long region = page / (pagesize >> 2); /* Pages per Lock region */

	if (EFC->FSR & ((1 << region) << MC_FSR_LOCK_SHIFT)) {
		EFC->FCR = (0x5A << MC_FCR_KEY_SHIFT) | (page << MC_FCR_PAGEN_SHIFT) | (MC_FCR_FCMD_CLB);
		while(!((fsr = EFC->FSR) & MC_FSR_FRDY)) {;}
		fsr |= EFC->FSR;
		if (fsr & MC_FSR_PROGE)
			return -1;
	}
	
	return 0;
}
