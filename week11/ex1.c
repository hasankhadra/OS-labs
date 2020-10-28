#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>

char *addr;
int file;
int main(){
    file = open("ex1.txt", O_RDWR);
    struct stat s = {};
    fstat(file, &s);
    addr = mmap(NULL, s.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, file, 0);
    strncpy(addr, "This is a nice day", 18);
    return 0;
}