#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define SIZE 600
#define ITER 20

int main(int argc, char const *argv[])
{
	for (int i = 0; i < ITER; ++i)
	{
		int *pointer = (int *)malloc(SIZE*1024*1024);
		memset(pointer, 0, SIZE*1024*1024);
		sleep(1);
	}

	return 0;
}