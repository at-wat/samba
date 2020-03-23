/************************************************************************
 * This program is free software; you can redistribute it and/or modify *
 * it under the terms of the GNU General Public License as published by *
 * the Free Software Foundation; either version 2 of the License, or    *
 * (at your option) any later version.                                  *
 *                                                                      *
 * Author: Yury Ovcharenko <amwsoft@gmail.com>                          *
 ************************************************************************/

#ifndef _FUNCS_H
#define _FUNCS_H

#ifdef DEBUG_MODE

char *hexb(char *buf, char c);
char *hexw(char *buf, short s);
char *hexl(char *buf, long l);

#else /* DEBUG_MODE */

#define hexb(x, y)	/* No code if not _DEBUG_MODE */
#define hexw(x, y)	/* No code if not _DEBUG_MODE */
#define hexl(x, y)	/* No code if not _DEBUG_MODE */

#endif /* DEBUG_MODE */

#endif /* _FUNCS_H */
