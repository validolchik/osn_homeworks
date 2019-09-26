#include<signal.h>
#include<stdio.h>
#include<stdlib.h>

void sigint(){
	printf("\nSIGINT was caught, exit\n");
	exit(0);
}

void killed(){
	printf("\nkilled\n");
	exit(0);
}

void stopped(){
	printf("\nstopped\n");
	exit(0);
}

void usr(){
	printf("\n usrsig was caught\n");
	exit(0);
}

int main(int argc, char const *argv[])
{
	signal(SIGKILL, killed);
	signal(SIGSTOP, stopped);
	signal(SIGUSR1, usr);
	while(1){
		;
	}
	return 0;
}