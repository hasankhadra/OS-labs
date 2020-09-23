#include <stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int arrival[1009], bt[1009], n, ct[n], tarrival[n], wt[n];
float arrivaltt, awt;
float total_tarrival = 0, total_wt = 0;

int main() {

    printf("Enter number of processes:");
    scanf("%d", &n);


    for(int i = 0;i<n;i++) {
        printf("Enter (arrival time, Burst time) of process as a paiy (x, y)");
        scanf("%d %d", &arrival[i], &bt[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrival[j] > arrival[j + 1]) {
                swap (&arrival[j], &arrival[j + 1]);
                swap (&bt[j], &bt[j + 1]);
            }

            if (arrival[j] == arrival[j + 1]) {
                if (bt[j] > bt[j + 1]) {
                    swap (&arrival[j], &arrival[j + 1]);
                    swap (&bt[j], &bt[j + 1]);
                }
            }
        }
    }



    ct[0] = arrival[0] + bt[0];
    for (int i = 1; i < n; i++) {
        ct[i] = ct[i - 1] + bt[i];
    }


    for (int i = 0; i < n; i++) {
        tarrival[i] = ct[i] - arrival[i];
        total_tarrival += tarrival[i];
    }


    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = tarrival[i] - bt[i];
        total_wt += wt[i];
    }

    printf("Average Turnaround time = %f \n", total_tarrival / (float)n);
    printf("Average Waiting time = %f \n", total_wt / (float)n);

    printf("#P\tarrival\tBT\tCT\tTarrival\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("Process number: %d\t", (i + 1));
        printf("Arrival time:%d\t", arrival[i]);
        printf("Burst time:%d\t", bt[i]);
        printf("%d\t", ct[i]);
        printf("%d\t", tarrival[i]);
        printf("%d\n", wt[i]);
    }

}