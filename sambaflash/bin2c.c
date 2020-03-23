/*************************************************************************
 * This program is free software; you can redistribute it and/or modify  *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation; either version 2 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * Author: Yury Ovcharenko <amwsoft@gmail.com>                           *
 *************************************************************************/

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int fd;
	unsigned char buf[16];
	int retval;
	struct stat st;
	int i, count;
	
	if (argc != 2) {
		fprintf(stderr, "%s: File not specified.\n", argv[0]);
		return 1;
	}
	
	retval = stat(argv[1], &st);
	if (retval < 0) {
		fprintf(stderr, "%s: Can not stat file '%s': %s.\n", argv[0], argv[1], strerror(errno));
		return 2;
	}
	
	fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		fprintf(stderr, "%s: Can not open file '%s': %s.\n", argv[0], argv[1], strerror(errno));
		return 3;
	}
	
	printf("/*********************************************\n");
	printf(" * Do not modify!                            *\n");
	printf(" * This file is generated from binary!       *\n");
	printf(" *********************************************/\n");
	printf("\n");
	printf("const int sambaflash_size = %d;\n", st.st_size);
	printf("\n");
	printf("const char sambaflash[] = {\n");

	count = 0;
	while ((retval = read(fd, buf, sizeof(buf))) > 0) {
		for (i = 0; i < retval; i++) {
			if (!((count + i) & 0xF))
				printf("\t");
			printf("0x%02X", buf[i]);
			if ((count + i) == (st.st_size - 1))
				printf("\n");
			else
			{
				if (((count + i) & 0xF) == 0xF)
					printf(",\n");
				else
					printf(", ");
			}

		}
		count += retval;
	}

	if (retval < 0) {
		fprintf(stderr, "%s: Can not read file '%s': %s.\n", argv[0], argv[1], strerror(errno));
		retval = 4;
	} else {
		retval = 0;
	}
	
	printf("};\n");

	close(fd);
	return retval;
}

/* End of file */
