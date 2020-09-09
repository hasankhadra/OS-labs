#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    int i = 0;
    while(i++<5){
        fork();
        sleep(5);
        system("pstree -p 9307");
    }
}