#include <stdio.h>

int main() {
    int i, j;
    int bt[5], wt[5], tat[5], p[5];
    float avg_wt = 0, avg_tat = 0;


    printf("Enter Burst Time:\n");

    for(i = 0; i < 5; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

    for(i = 0; i < 5; i++) {
        for(j = i+1; j < 5; j++) {
            if(bt[i] > bt[j]) {
                int temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for(i = 1; i < 5; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < 5; i++) {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];

        printf("P%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/5);
    printf("\nAverage Turnaround Time = %.2f", avg_tat/5);

    return 0;
}
