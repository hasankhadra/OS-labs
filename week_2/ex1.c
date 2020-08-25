#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char const *argv[]){
    int i = INT_MAX;;
    float f = FLT_MAX;
    double d = DBL_MAX;

    printf("Max int value: %d\nInt size: %ld\nMax float value: %f\nFloat size: %ld\nMax double value: %lf\nDouble size: %ld\n", i, sizeof i, f, sizeof f, d, sizeof d);

    return 0;
}
