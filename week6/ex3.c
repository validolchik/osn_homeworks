#include<signal.h>
#include<stdio.h>
#include<stdlib.h>

void sigint(){
	printf("\nSIGINT was caught, exit\n");
	exit(0);
}

int main(int argc, char const *argv[])
{	
	signal(SIGINT, sigint);
	while(1){
		;
	}
	return 0;
}