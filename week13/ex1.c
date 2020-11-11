#include <stdio.h>
#define n 5
#define m 3
int W[m], F[n], A[m], C[n][m], R[n][m], E[m];
int min(int x, int y){
    if (x < y) return x;
    return y;
}
int main(){

    FILE* file = fopen ("C:\\Users\\ASUS\\CLionProjects\\ex1\\ex1.txt", "r");
    for(int i=0;i<n;i++)
        fscanf(file, "%d", &E[i]);
    for(int i=0;i<n;i++)
        fscanf(file, "%d", &A[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            fscanf(file, "%d", &C[i][j]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            fscanf(file, "%d", &R[i][j]);

    for(int i=0;i<m;i++)
        W[i] = A[i];

    for(int i=0;i<n;i++){
        int allZeros = 1;
        for(int j=0;j<m;j++){
            if(R[i][j] != 0)
                allZeros = 0;
        }
        if(allZeros)F[i] = 1;
        else F[i] = 0;
    }
    int repeat = 1;
    int done = 0;
    while(repeat){
        for(int i=0;i<n;i++){
            int ok = 1;
            for(int j=0;j<m;j++){
                if(R[i][j] > W[j]){
                    ok = 0;
                    break;
                }
            }
            if(F[i] == 0 && ok){
                for(int k=0;k<m;k++) {
                    W[k] += C[i][k];
                    W[k] = min(W[k], E[k]);
                }
                F[i] = 1;
                break;
            }
            else {
                done = 1;
                break;
            }

        }
        if(!done)continue;
        int deadlocked = 0;
        for(int k=0;k<n;k++){
            if(F[k] == 0) {
                printf("Process %d is deadlocked.\n", k + 1);
                deadlocked = 1;
            }
        }
        if(!deadlocked)
            puts("no deadlock.");
        break;
    }
}