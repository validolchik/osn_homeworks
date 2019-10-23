#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char const *argv[])
{	
	struct dirent *pDirent;
	struct stat sfile; //pointer to stat struct
	DIR *dir;
	char name[] = "/home/renat/homeworks/week10/tmp";
  	stat("link1", &sfile); //stat system call
  	dir = opendir(name);
  	printf("st_mode = %o nlink = %lu", sfile.st_mode, sfile.st_nlink); //accessing st_mode (data member of stat struct)

    if (dir == NULL) {
        printf ("Cannot open directory '%s'\n", name);
        return 1;
    }

    while ((pDirent = readdir(dir)) != NULL) {
    	stat(pDirent->d_name, &sfile);
        printf ("[%s] %lu %lu\n", pDirent->d_name, sfile.st_nlink, sfile.st_ino);
    }
    closedir (dir);
    
  	return 0;
}