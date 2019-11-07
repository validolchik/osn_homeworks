#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  
#define BUFFER_SIZE 4096*2

FILE *fp;

int main(int argc, char const *argv[])
{		
	int n_of_files;
	int fd;
	int is_a = 0;
	char buffer[BUFFER_SIZE];
	int count = 0;
	int con = 1;
	char c;
	while((c = getchar()) != EOF && count < BUFFER_SIZE){
		buffer[count] = c;
		count++;
	}
	printf("%s", buffer);

	if(strcmp(argv[1], "-a") == 0){
		is_a = 1;
		n_of_files = argc - 2;
	}else{
		n_of_files = argc - 1;
	}

	printf("is a == %d\n", is_a);

	for (int i = 0; i < n_of_files; ++i)
	{	
		printf("i = %d\n", i);
		if(is_a){con = 2;}
		else{
			con = 1;
		}
		printf("i + con = %d\n", i + con);
		printf("%s\n", argv[i+con]);

		if(is_a){
			if((fd = open(argv[i+con], O_RDWR | O_CREAT | O_APPEND, 0777)) < 0){
				printf("open error\n");
			}
		}else{
			if((fd = open(argv[i+con], O_RDWR | O_CREAT | O_TRUNC, 0777)) < 0){
				printf("open error\n");
			}	
		}
		
		printf("%d\n", fd);
		// printf("%d", write (fd, buffer, BUFFER_SIZE));

		if (write (fd, buffer, count) < 0){
			printf ("write error %d", i);
			return 0;
		}
		close(fd);
	}

	printf("%s", buffer);

	return 0;
}