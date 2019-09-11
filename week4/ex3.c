#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

int main(int argc, char const *argv[])
{
	char string[BUFFER_SIZE];

	while(fgets(string, BUFFER_SIZE, stdin)){
		system(string);
	}
	return 0;
}