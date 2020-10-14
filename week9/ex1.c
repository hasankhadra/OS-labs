#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int frames = 10;
const int max_bit = 30;

int total, misses;
int hit, lowest;

int main(){
    int ram[frames], a[frames];
    memset(ram, -1, sizeof(ram));
    FILE* in = fopen("input.txt", "r");
    int input;

    while(fscanf(in,"%d",&input) == 1){
        printf("%d\n", input);
        if(input == 0)break;
        hit = lowest = 0;
        total++;

        for(int i=0;i<frames;i++){
            a[i] >>= 1;

            if(ram[i]==input){
                a[i]|=(1<<(max_bit-1));
                hit = 1;
            }
            if(ram[i]==-1)
                lowest=i;
            else if(a[i]<a[lowest])
                lowest=i;
        }
        if(hit)continue;

        ++misses;
        a[lowest]=(1<<(max_bit-1));
        ram[lowest]=input;
    }

    printf("frames => %d\t in total => %d\t #hits => %d\t #misses => %d\n", frames, total, total - misses, misses);
    printf("hits/miss => %.2f\n", (double)(total-misses)/(misses));

}
