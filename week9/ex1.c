#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int frames1 = 10;
const int frames2 = 50;
const int frames3 = 100;
const int max_bit = 31;

int total, misses;
int hit, lowest;

int main(){
    int ram[frames1], a[frames1];
    memset(ram, -1, sizeof(ram));
    memset(a, 0, sizeof(a));
    FILE* in = fopen("C:\\Users\\prhas\\Desktop\\input.txt", "r");
    int input;
    fscanf (in, "%d", &input);
    while(!feof(in)){
        hit = lowest = 0;
        total++;
        for(int i=0;i<frames1;i++){
            if (a[i] != -1){
                a[i] /= 2;
            }
            if(ram[i]==input){
                a[i]|=(1<<(max_bit-1));
                hit = 1;
            }
            if(ram[i]==-1){
                if (ram[lowest] != -1){
                    lowest=i;
                }
            }
            else if(a[i]<a[lowest]){
                if (ram[lowest] != -1){
                    lowest=i;
                }
            }
        }
        int tt = input;
        fscanf (in, "%d", &input);
        if(hit)continue;
        ++misses;
        a[lowest]=(1<<(max_bit-1));
        ram[lowest]=tt;
    }

    printf("frames => %d\t in total => %d\t #hits => %d\t #misses => %d\n", frames1, total, total - misses, misses);
    printf("hits/miss => %.2f\n", (double)(total-misses)/(misses));
    fclose(in);
}
