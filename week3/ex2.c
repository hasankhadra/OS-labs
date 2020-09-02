#include <stdio.h>

void swap(int *p1, int *p2){

    // swap two integers by reference
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void bubble_sort(int *a, int n){

    // A function that sorts an array (a) of n integers in place.
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j] > a[j+1]){
                swap(&a[j], &a[j+1]);
            }
        }
    }

}

int n, a[10000];
int main() {

    // testing the program
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    bubble_sort(a, n);
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);

    return 0;
}
