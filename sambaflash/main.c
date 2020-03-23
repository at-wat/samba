/************************************************************************
 * This program is free software; you can redistribute it and/or modify *
 * it under the terms of the GNU General Public License as published by *
 * the Free Software Foundation; either version 2 of the License, or    *
 * (at your option) any later version.                                  *
 *                                                                      *
 * Author: Yury Ovcharenko <amwsoft@gmail.com>                          *
 ************************************************************************/

#include "at91sam7.h"
#include "pio.h"
#include "serial.h"
#include "funcs.h"
#include "flash.h"

extern unsigned long _pageaddr;
extern unsigned long _pagelen;
extern unsigned long _buffer;

#ifdef DEBUG_MODE
	char buf[257];
#endif

int main(void)
{
	unsigned long pageaddr = _pageaddr;
	unsigned long pagesize = _pagelen;
	unsigned long *pagebuf = &_buffer;

	int retval;
	int tryes;
	unsigned long *x, *y;
	int i;
#ifdef DEBUG_MODE
	char *C;
#endif
	struct EFC_t *EFC = EFC_BASE;

	pio_init();
	serial_init();
	flash_init();
	
	for (tryes = 0; tryes < 4; tryes++) {
		retval = flash_writepage((unsigned long *)pageaddr, pagebuf, pagesize);
	
		if (retval == 0) {
			x = (unsigned long *)pageaddr;
			y = pagebuf;
			for (i = 0; i < (pagesize >> 2); i++) {
				if (x[i] != y[i]) {
#ifdef DEBUG_MODE
					C = buf;
					C = hexl(C, (unsigned long)&x[i]); *C++ = ':'; *C++ = ' ';
					C = hexl(C, x[i]); *C++ = ' '; *C++ = '!'; *C++ = '='; *C++ = ' ';
					C = hexl(C, y[i]); *C++ = ' ';
					*C++ = '\r'; *C++ = '\n'; *C = 0;
					puts(buf);
#endif
					retval = -3;
				}
			}
		}
		if (retval = 0)
			break;
	}
	
	pio_write(0x7);
	
	return retval;
}
