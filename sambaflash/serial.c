/************************************************************************
 * This program is free software; you can redistribute it and/or modify *
 * it under the terms of the GNU General Public License as published by *
 * the Free Software Foundation; either version 2 of the License, or    *
 * (at your option) any later version.                                  *
 *                                                                      *
 * Author: Yury Ovcharenko <amwsoft@gmail.com>                          *
 ************************************************************************/

#ifdef DEBUG_MODE

#include "at91sam7.h"
#include "serial.h"
#include "pmc.h"

void serial_init()
{
	struct DBGU_t *DBGU = DBGU_BASE;
	
	DBGU->CR = 0xAC;
	DBGU->CR = 0x50;
	DBGU->IER = 0;
	DBGU->IMR = 0;
	DBGU->IDR = 0xFFFFFFFF;
	DBGU->MR = 0x800;
	DBGU->BRGR = (get_sysfreq() / 115200) / 16;
}

void putc(char c)
{
	struct DBGU_t *DBGU = DBGU_BASE;

	while (!(DBGU->SR & 2)) {;}
	DBGU->THR = c;
}

void puts(char *s)
{
	while (*s) {
		putc(*s++);
	}
}

#endif /* DEBUG_MODE */
