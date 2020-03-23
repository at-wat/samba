/************************************************************************
 * This program is free software; you can redistribute it and/or modify *
 * it under the terms of the GNU General Public License as published by *
 * the Free Software Foundation; either version 2 of the License, or    *
 * (at your option) any later version.                                  *
 *                                                                      *
 * Author: Yury Ovcharenko <amwsoft@gmail.com>                          *
 ************************************************************************/

#ifndef _PMC_H
#define _PMC_H

#define	F_OSC			(18432000L)	/* Hz */
#define	F_RC_OSC		(30000L)	/* Hz */


unsigned long get_clktype();
unsigned long get_postscale();
unsigned long get_pllmul();
unsigned long get_plldiv();
unsigned long get_sysfreq();

#endif /* _PMC_H */
