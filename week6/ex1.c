// some part of code retrieved from https://www.geeksforgeeks.org/pipe-system-call/
#include <stdlib.h>
#include <stdio.h> 
#include <unistd.h> 
#define MSGSIZE 16 

int main(){
	char str1[MSGSIZE] = "message";
	char str2[MSGSIZE] = "";
	
	int p[2], i; 

	if (pipe(p) < 0) exit(1); 

	printf("str2 before operations = '%s'\n", str2);

	write(p[1], str1, MSGSIZE);
	read(p[0], str2, MSGSIZE);

	printf("str2 after operations = '%s'\n", str2);
	return 0; 
} 
