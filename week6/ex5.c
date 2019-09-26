#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

int msec = 0, trigger = 1000; 
/* in msec-s; 
set to 1000 to reach one second between outputs 
(but you will see that the buffer already full, that is not true)
set trigger from 5 to 25 to see how buffer
flling and then the fatal race cond
*/
clock_t before; // "timer"


int main(int argc, char *argv[]){
	before = clock();

	pid_t n = fork();
	pid_t pid = getpid();
	if(n == 0){
		// child
		while(1){
			clock_t difference = clock() - before;
			msec = difference * 1000 / CLOCKS_PER_SEC;
			if(msec >= trigger){
				before = clock();
				// printf("state_cons %d state_prod %d buffer %d\n", state_cons, state_prod, buffer);
				printf("I'm alive\n");
			}
		}
	}else if(n > 0){
		// parent
		sleep(10);
		kill(n, SIGTERM);
	}else{
		printf("error\n");
	}

	exit(NULL);
}