/************************************************************************
 * This program is free software; you can redistribute it and/or modify *
 * it under the terms of the GNU General Public License as published by *
 * the Free Software Foundation; either version 2 of the License, or    *
 * (at your option) any later version.                                  *
 *                                                                      *
 * Author: Yury Ovcharenko <amwsoft@gmail.com>                          *
 ************************************************************************/

#ifndef _FLASH_H
#define _FLASH_H

#include "at91sam7.h"

#define	FLASH_ADDR_MASK		0xFFFFF
#define	FLASH_SIZE		(1024 * 256)
#define	FLASH_LOCKBITS		16
#define	FLASH_PAGESIZE		256
#define	FLASH_LOCKSIZE		(FLASH_SIZE / FLASH_LOCKBITS)
#define	FLASH_LOCKPAGES		(FLASH_SIZE / FLASH_PAGESIZE / FLASH_LOCKBITS)

void flash_init();
/**
 * flash_writepage
 * @param	addr address to be writen to,
 * @param	buf data to be writen
 * @param	pagesize EFC Page Size in bytes
 */
int flash_writepage(unsigned long *addr, unsigned long *buf, unsigned long pagesize);
int flash_unlock(unsigned long *addr, unsigned long pagesize);
int flash_unlockpage(unsigned long page);

#endif /* _FLASH_H */
