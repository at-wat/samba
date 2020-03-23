/************************************************************************
 * This program is free software; you can redistribute it and/or modify *
 * it under the terms of the GNU General Public License as published by *
 * the Free Software Foundation; either version 2 of the License, or    *
 * (at your option) any later version.                                  *
 *                                                                      *
 * Author: Yury Ovcharenko <amwsoft@gmail.com>                          *
 ************************************************************************/

#include "at91sam7.h"
#include "pmc.h"

unsigned long get_clktype()
{
	struct PMC_t *PMC = PMC_BASE;
	return PMC->MCKR & 3;
}


unsigned long get_postscale()
{
	struct PMC_t *PMC = PMC_BASE;
	return (1 << ((PMC->MCKR & (0x7 << 2)) >> 2));
}

unsigned long get_pllmul()
{
	struct PMC_t *PMC = PMC_BASE;
	return (((PMC->PLLR & 0x07FF0000) >> 16) + 1);
}

unsigned long get_plldiv()
{
	struct PMC_t *PMC = PMC_BASE;
	return (PMC->PLLR & 0xFF);
}

unsigned long get_sysfreq()
{
	struct PMC_t *PMC = PMC_BASE;
	switch (get_clktype())
	{
		case 0:
			/* RC oscillator */
			return (F_RC_OSC / get_postscale());
			break;
		case 1:
			/* Main oscillator */
			return (F_OSC / get_postscale());
			break;
		case 3:
			return (((F_OSC * get_pllmul()) / get_plldiv()) / get_postscale());
			break;
		default:
			return (0);
			break;
	}
}
