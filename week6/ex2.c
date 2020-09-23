#include <stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int n;
int arrival[1009], burst[1009], ct[1009], turnaround_time[1009], wt[1009];
float total_tarrival = 0, total_wt = 0;

int main() {

    printf("Enter number of processes:");
    scanf("%d", &n);

    printf("Enter (arrival time, Burst time) of process as a paiy (x, y):\n");
    for(int i = 0;i<n;i++)scanf("%d %d", &arrival[i], &burst[i]);


    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arrival[j] == arrival[j + 1]){
                if(burst[j] > burst[j + 1]){
                    swap (&arrival[j], &arrival[j + 1]);
                    swap (&burst[j], &burst[j + 1]);
                }
            }
            else if(arrival[j] > arrival[j + 1]){
                swap (&arrival[j], &arrival[j + 1]);
                swap (&burst[j], &burst[j + 1]);
            }

        }
    }

    wt[0] = 0;
    ct[0] = arrival[0] + burst[0];
    for(int i=1;i<n;i++)ct[i] = ct[i - 1] + burst[i];
    for(int i=0;i<n;i++){
        turnaround_time[i] = ct[i] - arrival[i];
        total_tarrival += turnaround_time[i];
        if(i){
            wt[i] = turnaround_time[i] - burst[i];
            total_wt += wt[i];
        }
    }

    printf("Avg Turnaround time = %f \n", total_tarrival / (float)n);
    printf("Avg Waiting time = %f \n", total_wt / (float)n);

    for(int i=0;i<n;i++)
        printf("Process number %d:\t Arrival time: %d\t Burst time: %d\t\tTurnaround time: %d\n", (i + 1), arrival[i], burst[i], turnaround_time[i]);

}
