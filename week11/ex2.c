#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char const *argv[]){
   char buff[1024];

   memset( buff, '\0', sizeof( buff ));
   setvbuf(stdout, buff, _IOLBF, 1024);
   fprintf(stdout, "h");
   sleep(1);
   fprintf(stdout, "e");
   sleep(1);
   fprintf(stdout, "l");
   sleep(1);
   fprintf(stdout, "l");
   sleep(1);
   fprintf(stdout, "o");
   sleep(1);
   fprintf(stdout, "\n");

   return(0);
}
