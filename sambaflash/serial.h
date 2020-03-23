/************************************************************************
 * This program is free software; you can redistribute it and/or modify *
 * it under the terms of the GNU General Public License as published by *
 * the Free Software Foundation; either version 2 of the License, or    *
 * (at your option) any later version.                                  *
 *                                                                      *
 * Author: Yury Ovcharenko <amwsoft@gmail.com>                          *
 ************************************************************************/

#ifndef _SERIAL_H
#define _SERIAL_H

#ifdef DEBUG_MODE

void serial_init();
void putc(char c);
void puts(char *s);

#else /* DEBUG_MODE */

#define	serial_init()	/* No code if not _DEBUG_MODE */
#define	putc(x)		/* No code if not _DEBUG_MODE */
#define	puts(x)		/* No code if not _DEBUG_MODE */

#endif /* DEBUG_MODE */

#endif /* _SERIAL_H */
