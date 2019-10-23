#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#define BUF 512

int main(int argc, char const *argv[])
{	
	struct dirent *pDirent;
	struct stat sfile;
	DIR *dir;
	char name[] = "tmp/";

  	dir = opendir(name);
    if (dir == NULL) {
        printf ("Cannot open directory '%s'\n", name);
        return 1;
    }

    while ((pDirent = readdir(dir)) != NULL) {
    	char path[BUF];
    	strcpy(path, name);
    	strcat(path, pDirent->d_name);
    	stat(path, &sfile);
        if(sfile.st_nlink > 1){
        	printf("%s %lu\n", pDirent->d_name, sfile.st_ino);
        	DIR *dir1;
        	dir1 = opendir("tmp/");
        	struct dirent *pDirent1;
        	struct stat sfile1;
        	while ((pDirent1 = readdir(dir1)) != NULL) {
		        if(stat(pDirent1->d_name, &sfile1) == 0){
		        	if(sfile.st_ino == sfile1.st_ino){
			        	printf("%s links to %lu\n", pDirent1->d_name, sfile1.st_ino);
			        }
		        }
		    }
		    closedir(dir1);
        }
    }
    closedir (dir);
    
  	return 0;
}
