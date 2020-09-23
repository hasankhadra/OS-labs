#include <stdio.h>

void swap(int *x, int *y){
    /*
     * swap two integers by reference
     */
    int temp = *x;
    *x = *y;
    *y = temp;
}

int n, arrival[1009], burst[1009], wait[1009], orig[1009], turnAround[1009];
double average_Wait = 0, average_TurnAround = 0;

int main(){
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Process (Arrival Time, Burst Time) as a pair (x, y):\n");
    for(int i=0;i<n;i++){
        scanf("%d %d", &arrival[i], &burst[i]);
        orig[i] = i + 1;
    }

    // sort the array according to the arrival time
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arrival[j] > arrival[j + 1]){
                swap(&arrival[j], &arrival[j + 1]);
                swap(&burst[j], &burst[j + 1]);
                swap(&orig[j], &orig[j + 1]);
            }
        }
    }

    for(int i=0;i<n;i++){
        if(i == 0){
            wait[i] = arrival[i];
            continue;
        }
        if(wait[i - 1] + burst[i - 1] > arrival[i])
            wait[i] = wait[i - 1] + burst[i - 1];
        else
            wait[i] = burst[i - 1];
        average_Wait += wait[i] - arrival[i];
    }
    average_Wait /= n;

    for(int i=0;i<n;i++){
        turnAround[i] = -arrival[0] + wait[i] + burst[i];
        average_TurnAround += turnAround[i];
    }
    average_TurnAround /= n;

    printf("\nAvg Waiting Time: %f", average_Wait);
    printf("\nAvg Turnaround Time: %f", average_TurnAround);
    printf("\nCompletion Time: %d", turnAround[n - 1] + arrival[n - 1]);

    for(int i=0;i<n;i++)
        printf("\nProcess number %d:\t Arrival time: %d\t Waiting time: %d\t Burst time: %d\t\tTurnaroud Time: %d", orig[i], arrival[i], wait[i] - arrival[i], burst[i], turnAround[i]);

    return 0;
}