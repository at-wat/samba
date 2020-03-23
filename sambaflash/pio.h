/************************************************************************
 * This program is free software; you can redistribute it and/or modify *
 * it under the terms of the GNU General Public License as published by *
 * the Free Software Foundation; either version 2 of the License, or    *
 * (at your option) any later version.                                  *
 *                                                                      *
 * Author: Yury Ovcharenko <amwsoft@gmail.com>                          *
 ************************************************************************/

#ifndef _PIO_H
#define _PIO_H

#ifdef DEBUG_MODE

void pio_init();
void pio_write(unsigned long d);

#else /* DEBUG_MODE */

#define pio_init()	/* No code if not _DEBUG_MODE */
#define pio_write(x)	/* No code if not _DEBUG_MODE */

#endif /* DEBUG_MODE */

#endif /* _PIO_H */
