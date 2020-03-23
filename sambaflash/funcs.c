/************************************************************************
 * This program is free software; you can redistribute it and/or modify *
 * it under the terms of the GNU General Public License as published by *
 * the Free Software Foundation; either version 2 of the License, or    *
 * (at your option) any later version.                                  *
 *                                                                      *
 * Author: Yury Ovcharenko <amwsoft@gmail.com>                          *
 ************************************************************************/

#ifdef DEBUG_MODE

#include "funcs.h"

static const char H[] = {"0123456789ABCDEF"};

char *hexb(char *buf, char c)
{
	char *x = buf;
	*x++ = H[(c >> 4) & 0xF];
	*x++ = H[c & 0xF];
	
	return x;
}

char *hexw(char *buf, short s)
{
	char *x = buf;
	x = hexb(x, (s >> 8) & 0xFF);
	x = hexb(x, s & 0xFF);
	return x;
}

char *hexl(char *buf, long l)
{
	char *x = buf;
	x = hexb(x, (l >> 24) & 0xFF);
	x = hexb(x, (l >> 16) & 0xFF);
	x = hexb(x, (l >> 8) & 0xFF);
	x = hexb(x, l & 0xFF);
	return x;
}

#endif /* DEBUG_MODE */
