bin_PROGRAMS = samba
samba_SOURCES = \
	batch.c \
	cmdline.c \
	comm.c \
	crc-1021.c \
	fsio.c \
	sam.c \
	samba.c \
	sambaflash.c \
	sambareset.c

# set the include path found by configure
INCLUDES = $(all_includes)

# the library search path.
samba_LDFLAGS = $(all_libraries) 
samba_LDADD = -lreadline -lncurses
noinst_HEADERS = cmdline.h defs.h comm.h sam.h fsio.h crc-1021.h batch.h

