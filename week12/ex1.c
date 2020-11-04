#include <stdio.h>

char letter;
char ss[20];
int main(){
    FILE *random = fopen("/dev/random", "r");
    for(int i=0;i<20;i++){
        fread(&letter,1,1,random);
        if((int)letter < 33 || (int)letter > 127){
            i--;
            continue;
        }
        ss[i] = letter;
    }
    for(int i=0;i<20;i++)
        printf("%c",ss[i]);
    puts("");
    fclose(random);
}