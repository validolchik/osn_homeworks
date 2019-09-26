//the part of the code retrieved from https://www.geeksforgeeks.org/pipe-system-call/
#include <stdlib.h>
#include <stdio.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MSGSIZE 64

int main(){
	char buffer[MSGSIZE] = "";
	char msg[MSGSIZE] = "message";
	int p[2], pid, nbytes; 
	//p[0] = read p[1] = write

	printf("buffer before reading = '%s'\n", buffer);

	if (pipe(p) < 0) 
		exit(1); 

	if ((pid = fork()) > 0) { 
		write(p[1], msg, MSGSIZE);

		// Adding this line will 
		// not hang the program 
		// close(p[1]); 
		// wait(NULL); 
	}
	else{ 
		// Adding this line will 
		// not hang the program 
		// close(p[1]); 
		// while ((nbytes = read(p[0], buffer, MSGSIZE)) > 0)
		read(p[0], buffer, MSGSIZE);
			// printf("%s\n", buffer);
		printf("buffer after reading = '%s'\n", buffer);
		if (nbytes != 0) 
			exit(2); 
		printf("Finished reading\n"); 
	}

	return 0; 
} 
