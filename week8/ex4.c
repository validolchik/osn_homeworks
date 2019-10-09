#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#define SIZE 10
#define ITER 10

int main(int argc, char const *argv[])
{
	struct rusage usage;
	for (int i = 0; i < ITER; ++i)
	{
		int *pointer = (int *)malloc(SIZE*1024*1024);
		memset(pointer, 0, SIZE*1024*1024);
		getrusage(RUSAGE_SELF, &usage);
		printf("Mem usage: %ld\n", usage.ru_maxrss);
		sleep(1);
	}

	return 0;
}