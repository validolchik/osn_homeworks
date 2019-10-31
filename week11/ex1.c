#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>

int main(void) {
	int myFile = open("ex1.txt", O_RDWR, (mode_t)0600);
	const char *text = "This is a nice day";

	if(myFile < 0){
		printf("open error\n");
	}
	struct stat myStat = {};
	if (fstat(myFile, &myStat)){
		printf("fstat error\n");
	}

	off_t size = myStat.st_size;
	char *addr;
	off_t string_size = strlen(text);
	
	if(ftruncate(myFile, string_size) == -1){
		printf("ftruncate error\n");
	}

	addr = mmap(NULL, string_size, PROT_READ|PROT_WRITE, MAP_SHARED, myFile, 0);
	if (addr == MAP_FAILED){
		printf("mmap error\n");
	}
	
	memcpy(addr, text, strlen(text));
	msync(addr, size, MS_SYNC);
	munmap(addr, size);
	close(myFile);
	return 0;
}
