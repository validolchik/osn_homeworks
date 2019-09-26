#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MSGSIZE 16

int main(int argc, char *argv[]){
	int p[2];

	if (pipe(p) < 0) exit(1);

	pid_t first = fork();
	// pid_t pid = getpid();

	if(first > 0){
		// parent
		int second = fork();
		int status;
		if(second > 0){
			// parent
			printf("Parent forks %d\n", second);
			int num_bytes = write(p[1], &second, sizeof(int));
			printf("Parent wrote in pipe %d\n", second);
			pid_t waited = waitpid(second, &status, 0);
			printf("The process with pid = %d changed status\n", waited);
			// wait(NULL);
		}
		else{
			// second
			while(1){
				;
			}
		}
	}else if(first == 0){
		// child first
		int s;
		read(p[0], &s, sizeof(int));
		printf("First child process had read %d\n", s);
		sleep(3);
		printf("First child process gonna stop process with pid %d\n", s);
		kill(s, SIGTERM);
		// SIGSTOP doesnt work on my pc, program status doesnt change
		printf("Killed\n");
		exit(EXIT_SUCCESS);
	}else{
		printf("Error\n");
	}

	return 0;
}