#include <stdio.h>
#include <unistd.h>

int main(){
    char* ss = "Hello";
    for(int i=0;i<5;i++){
        printf("%c", ss[i]);
        sleep(1);
    }
    puts("");
    return 0;
}