#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int xx, first = 0;
char cc;
int main(int argc, char *argv[]){
    int file = open("/dev/stdin", O_RDONLY, S_IRUSR);
    if(argc>1) if(strncmp(argv[1], "-a", 2) == 0) first = 1;
    while(read(file,&cc,1))
        for(int i=1+first;i<argc;i++){
            if(first) xx = open(argv[i], O_WRONLY | O_CREAT | O_APPEND);
            else xx = open(argv[i], O_WRONLY | O_CREAT | O_TRUNC);
            write(xx, &cc, 1);
            close(xx);
            first = 1;
        }
}