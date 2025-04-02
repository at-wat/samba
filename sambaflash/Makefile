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

CROSS		= arm-none-eabi-
CC		= $(CROSS)gcc
AS		= $(CROSS)as
LD		= $(CROSS)gcc
OBJDUMP		= $(CROSS)objdump
OBJCOPY		= $(CROSS)objcopy

HOST_CC		= gcc

INCLUDES	= at91sam7.h pio.h serial.h pmc.h funcs.h flash.h

FLASH_OBJS		= crt0.o main.o pio.o serial.o pmc.o funcs.o flash.o

FLASH_ELF		= sambaflash.elf
FLASH_BIN		= sambaflash.bin
FLASH_DUMP		= sambaflash.dump
FLASH_IMAGE		= sambaflash.c

RESET_OBJS		= crt0.o reset.o

RESET_ELF		= sambareset.elf
RESET_BIN		= sambareset.bin
RESET_DUMP		= sambareset.dump
RESET_IMAGE		= sambareset.c

LDS		= at91sam7.lds
LIBPATH		= -L/usr/arm-none-eabi/lib
LIBS		= -lc_nano

CPPFLAGS	=
CFLAGS		= -Os -g -mcpu=arm7tdmi -marm
ASFLAGS		=
LDFLAGS		= -Os -T$(LDS) -nostartfiles
##  DEBUG_MODE Used by developer
##CPPFLAGS	+= -DDEBUG_MODE

CONVERTOR	= bin2c

all: $(FLASH_IMAGE) $(RESET_IMAGE) $(CONVERTOR)

$(FLASH_IMAGE): $(FLASH_BIN) $(CONVERTOR)
	./$(CONVERTOR) $(FLASH_BIN) > $(FLASH_IMAGE)

$(RESET_IMAGE): $(RESET_BIN) $(CONVERTOR)
	./$(CONVERTOR) $(RESET_BIN) > $(RESET_IMAGE)
	sed -s 's/sambaflash/sambareset/g' -i $(RESET_IMAGE)

$(CONVERTOR): $(CONVERTOR).c
	$(HOST_CC) -o $@ $<

$(FLASH_BIN): $(FLASH_ELF)
	$(OBJDUMP) -SD $(FLASH_ELF) > $(FLASH_DUMP)
	$(OBJCOPY) -O binary $(FLASH_ELF) $(FLASH_BIN)

$(FLASH_ELF): $(FLASH_OBJS)
	$(LD) $(LDFLAGS) -o $@ $(FLASH_OBJS) $(LIBPATH) $(LIBS)

$(RESET_BIN): $(RESET_ELF)
	$(OBJDUMP) -SD $(RESET_ELF) > $(RESET_DUMP)
	$(OBJCOPY) -O binary $(RESET_ELF) $(RESET_BIN)

$(RESET_ELF): $(RESET_OBJS)
	$(LD) $(LDFLAGS) -o $@ $(RESET_OBJS) $(LIBPATH) $(LIBS)

%.o: %.c $(INCLUDES)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

%.o: %.S $(INCLUDES)
	$(CC) -E $(CPPFLAGS) $< | $(AS) $(ASFLAGS) -o $@

clean:
	@echo "==========================================="
	rm -f *.o
	rm -f sambaflash.* sambareset.*
	rm -f $(CONVERTOR)
	@echo "==========================================="

.PHONY: all clean
