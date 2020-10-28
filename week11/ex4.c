#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

char *f1, *f2;
size_t n;
int x1, x2;

int main(){
    x1 = open("ex1.txt", O_RDONLY);
    x2 = open("ex1.memcpy.txt", O_RDWR|O_CREAT, 0666);

    n = lseek(x1, 0, SEEK_END);

    f1 = mmap(NULL, n, PROT_READ, MAP_PRIVATE, x1, 0);
    ftruncate(x2, n);
    f2 = mmap(NULL, n, PROT_READ|PROT_WRITE, MAP_SHARED, x2, 0);

    memcpy(f2, f1, n);
    munmap(f2, n);
    munmap(f1, n);
    close(x1); close(x2);
    return 0;
}