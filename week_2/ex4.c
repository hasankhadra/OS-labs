#include <stdio.h>
#include <stdlib.h>

void swap_integers(int *p, int *q){ // Swaps two integers by reference
    int tmp = *q;
    *q = *p;
    *p = tmp;
}

int main(int argc, char const *argv[]){
    int x, y;
    scanf("%d %d", &x, &y);

    swap_integers(&x, &y);

    printf("x: %d, y: %d\n", x, y);

    return 0;
}
