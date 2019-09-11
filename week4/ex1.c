#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{	
	pid_t n = fork();
	pid_t pid = getpid();
	if(n == 0){
		// child
		printf("Hello from child %u\n", pid);
	}else if(n > 0){
		// parent
		printf("Hello from parent %u\n", pid);
	}else{
		printf("error\n");
	}
	return 0;
}