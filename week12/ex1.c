#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
FILE *fp;
FILE *out;

int main(int argc, char const *argv[])
{	
	int randomData = open("/dev/random", O_RDONLY);
	unsigned random_numbers[20];
	if (randomData < 0){
    	// something went wrong
    	printf("error: can not get fd of dev/random\n");
	}else{
	    char myRandomData[20];
	    size_t randomDataLen = 0;
	    while (randomDataLen < sizeof myRandomData){
	        ssize_t result = read(randomData, myRandomData + randomDataLen, (sizeof myRandomData) - randomDataLen);
	        if (result < 0)
	        {
	            // something went wrong
	            printf("can not read\n");
	        }
	        randomDataLen += result;
	    }
	    out = fopen("ex1.txt", "w");
	    for(int i = 0; i < 20; i++){
			unsigned number = abs(myRandomData[i]%126);
			if(number < 32) number += 32;
			fprintf(out, "%c", number);
		}
		fclose(out);
	}

	// unsigned random_numbers[20];
	// char random_string[20];
	// fp = fopen("/dev/random", "r");
	// // fscanf(fp, "%20s", random_string);
	// for(int i = 0; i < 20; i++){
	// 	fscanf(fp, "%u", &random_numbers[i]);
	// 	printf("%u\n", random_numbers[i]);
	// }
	// fclose(fp);

	// out = fopen("ex1.txt", "w");
	// fprintf(out, "%s\n", random_string);
	// fclose(out);
	return 0;
}