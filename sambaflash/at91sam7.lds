/* Linker script, for RAM executable */

OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
__DYNAMIC = 0;

MEMORY
{
  CODE	(rwx)	:	ORIGIN = 0x00202000, LENGTH = 0x00001000
  STACK	(rw)	:	ORIGIN = 0x00203000, LENGTH = 0x00001000
}


/* Section Definitions */

SECTIONS
{
	_stack_size = 0x00001000;
	_stack = 0x00203000 + _stack_size;
	_stack_limit = _stack_size;
	
	/* Flash parameters */
	_pageaddr = 0x00203000 + _stack_size;		/* Page number to write */
	_pagelen = _pageaddr + 4;			/* Page size in bytes */
	_retval = _pagelen + 4;				/* Return value */
	_buffer = _retval + 4;				/* buffer containing uploaded data to be programmed */
	
	PROVIDE (__executable_start = 0x00202000); . = 0x00202000;

	/* first section is .text which is used for code */

	.text :
	{
		*crt0.o (.text)		/* Startup code */
		*(.text)		/* remaining code */
	} >CODE =0
	. = ALIGN(4);

	/* .rodata section which is used for read-only data (constants) */

	.rodata :
	{
		*(.rodata)
	} >CODE =0

	. = ALIGN(4);

	_etext = . ;
	PROVIDE (etext = .);

	/* .data section which is used for initialized data */

	/*.data : AT (_etext)*/
	.data :
	{
		_data = . ;
		*(.data)
	} >CODE =0
	
	. = ALIGN(4);

	_edata = . ;
	PROVIDE (edata = .);

	/* .bss section which is used for uninitialized data */

	.bss :
	{
		__bss_start = . ;
		__bss_start__ = . ;
		*(.bss)
		*(COMMON)
	} >CODE =0
	
	. = ALIGN(4);
	
	__bss_end = . ;
	__bss_end__ = . ;

	_end = .;
	PROVIDE (end = .);
	
	/* Stabs debugging sections.  */
	.stab          0 : { *(.stab) }
	.stabstr       0 : { *(.stabstr) }
	.stab.excl     0 : { *(.stab.excl) }
	.stab.exclstr  0 : { *(.stab.exclstr) }
	.stab.index    0 : { *(.stab.index) }
	.stab.indexstr 0 : { *(.stab.indexstr) }
	.comment       0 : { *(.comment) }
	/* DWARF debug sections.
	Symbols in the DWARF debugging sections are relative to the beginning
	of the section so we begin them at 0.  */
	/* DWARF 1 */
	.debug          0 : { *(.debug) }
	.line           0 : { *(.line) }
	/* GNU DWARF 1 extensions */
	.debug_srcinfo  0 : { *(.debug_srcinfo) }
	.debug_sfnames  0 : { *(.debug_sfnames) }
	/* DWARF 1.1 and DWARF 2 */
	.debug_aranges  0 : { *(.debug_aranges) }
	.debug_pubnames 0 : { *(.debug_pubnames) }
	/* DWARF 2 */
	.debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
	.debug_abbrev   0 : { *(.debug_abbrev) }
	.debug_line     0 : { *(.debug_line) }
	.debug_frame    0 : { *(.debug_frame) }
	.debug_str      0 : { *(.debug_str) }
	.debug_loc      0 : { *(.debug_loc) }
	.debug_macinfo  0 : { *(.debug_macinfo) }
	/* SGI/MIPS DWARF 2 extensions */
	.debug_weaknames 0 : { *(.debug_weaknames) }
	.debug_funcnames 0 : { *(.debug_funcnames) }
	.debug_typenames 0 : { *(.debug_typenames) }
	.debug_varnames  0 : { *(.debug_varnames) }	
}
