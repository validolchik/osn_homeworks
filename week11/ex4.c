/*code from https://stackoverflow.com/ was used*/
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char const *argv[]){
	int fdin, fdout;
	char *src, *dst;
	struct stat statbuf;
	int mode = 0x0777;
	char file_name1[] = "ex1.txt";
	char file_name2[] = "ex2.memcpy.txt";

 	/* open the input file */
	if ((fdin = open(file_name1, O_RDONLY)) < 0){
		printf("can't open %s for reading", argv[1]);
		return 0;
	}

	/* open/create the output file */
	if ((fdout = open(file_name2, O_RDWR | O_CREAT | O_TRUNC, mode )) < 0){
	 	printf ("can't create %s for writing", argv[2]);
	 	return 0;
	}

	 /* find size of input file */
	if (fstat (fdin,&statbuf) < 0){
		printf ("fstat error");
		return 0;
	}

	 /* go to the location corresponding to the last byte */
	if (lseek (fdout, statbuf.st_size - 1, SEEK_SET) == -1){
		printf ("lseek error");
		return 0;
	}

	 /* write a dummy byte at the last location */
	if (write (fdout, "", 1) != 1){
		printf ("write error");
		return 0;
	}

	 /* mmap the input file */
	if ((src = mmap (0, statbuf.st_size, PROT_READ, MAP_SHARED, fdin, 0)) == (__caddr_t) -1){
		printf ("mmap error for input");
		return 0;
	}

	 /* mmap the output file */
	if ((dst = mmap (0, statbuf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fdout, 0)) == (__caddr_t) -1){
		printf ("mmap error for output");
		return 0;
	}

	/* this copies the input file to the output file */
	memcpy (dst, src, statbuf.st_size);
	close(fdin);
	close(fdout);
	return 0;
}
