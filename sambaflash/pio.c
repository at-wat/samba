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
#include "pio.h"


void pio_init()
{
	struct PIO_t *PIO = PIO_BASE;
	
	PIO->PER = 7;
	PIO->OER = 7;
	PIO->IFDR = 7;
	PIO->IDR = 7;
	PIO->MDDR = 7;
	PIO->PUDR = 7;
	PIO->SODR = 7;
	PIO->OWER = 7;
	
	PIO->PDR = 0xFFFFFFF8;
	
	PIO->ODR = 0;
	PIO->IFER = 0;
	PIO->CODR = 0;
	PIO->IER = 0;
	PIO->MDER = 0;
	PIO->PUER = 0;
	PIO->ASR = 0;
	PIO->BSR = 0;
	PIO->ABSR = 0;
	PIO->OWDR = 0;
}

void pio_write(unsigned long d)
{
	struct PIO_t *PIO = PIO_BASE;

	PIO->ODSR = d;
}

#endif /* DEBUG_MODE */
