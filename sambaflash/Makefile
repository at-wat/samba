#
# Makefile for SAM-BA Flash
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# Author: Yury Ovcharenko <amwsoft@gmail.com>
#

CROSS		= arm-elf-
CC		= $(CROSS)gcc
AS		= $(CROSS)as
LD		= $(CROSS)ld
OBJDUMP		= $(CROSS)objdump
OBJCOPY		= $(CROSS)objcopy

HOST_CC		= gcc

INCLUDES	= at91sam7.h pio.h serial.h pmc.h funcs.h flash.h

OBJS		= crt0.o main.o pio.o serial.o pmc.o funcs.o flash.o

ELF		= sambaflash.elf
BIN		= sambaflash.bin
DUMP		= sambaflash.dump
IMAGE		= sambaflash.c

LDS		= at91sam7.lds
LIBPATH		= -L/usr/local/arm/lib/gcc-lib/arm-elf/3.3.6
LIBS		= -lgcc

CPPFLAGS	=
CFLAGS		= -g
ASFLAGS		=
LDFLAGS		= -T$(LDS)
##  DEBUG_MODE Used by developer
##CPPFLAGS	+= -DDEBUG_MODE

CONVERTOR	= bin2c

all: $(IMAGE) $(CONVERTOR)

$(IMAGE): $(BIN) $(CONVERTOR)
	$(CONVERTOR) $(BIN) > $(IMAGE)

$(CONVERTOR): $(CONVERTOR).c
	$(HOST_CC) -o $@ $<

$(BIN): $(ELF)
	$(OBJDUMP) -SD $(ELF) > $(DUMP)
	$(OBJCOPY) -O binary $(ELF) $(BIN)

$(ELF): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS) $(LIBPATH) $(LIBS)

%.o: %.c $(INCLUDES)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

%.o: %.S $(INCLUDES)
	$(CC) -E $(CPPFLAGS) $< | $(AS) $(ASFLAGS) -o $@

clean:
	@echo "==========================================="
	rm -f *.o
	rm -f sambaflash.*
	rm -f $(CONVERTOR)
	@echo "==========================================="

.PHONY: all clean
