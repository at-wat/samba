/************************************************************************
 * This program is free software; you can redistribute it and/or modify *
 * it under the terms of the GNU General Public License as published by *
 * the Free Software Foundation; either version 2 of the License, or    *
 * (at your option) any later version.                                  *
 *                                                                      *
 * Author: Atsushi Watanabe <atsushi.w@ieee.org>                        *
 ************************************************************************/

#include "at91sam7.h"
#include "stdint.h"

int main(void)
{
  // Wait 1s to avoid reset during USB communication
  // (2250000loops = 1s based on the experiment)
  for (volatile register int32_t cnt asm("r3") = 2250000; cnt > 0; cnt--) {}

  struct RSTC_t *RSTC = RSTC_BASE;
  RSTC->RCR = 0xA5000000 | RSTC_RCR_PROCRST | RSTC_RCR_PERRST | RSTC_RCR_EXTRST;

  while(1);

	return 0;
}
