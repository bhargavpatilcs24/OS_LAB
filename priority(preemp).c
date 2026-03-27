#include <stdio.h>
#include <limits.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};
int main() {
    int n, i, time = 0, completed = 0;
    struct process p[20];
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i+1);
        p[i].pid = i+1;
        printf("Enter Arrival Time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Enter Burst Time: ");
        scanf("%d", &p[i].burst_time);
        printf("Enter Priority (lower value = higher priority): ");
        scanf("%d", &p[i].priority);
        p[i].remaining_time = p[i].burst_time;
    }
    while(completed != n) {
        int highest = -1;
        int min_priority = INT_MAX;
        for(i = 0; i < n; i++) {
            if(p[i].arrival_time <= time && p[i].remaining_time > 0) {
                if(p[i].priority < min_priority) {
                    min_priority = p[i].priority;
                    highest = i;
                }
            }
        }
        if(highest == -1) {
            time++; // CPU idle
        } else {
            p[highest].remaining_time--;
            time++;
            if(p[highest].remaining_time == 0) {
                completed++;
                p[highest].completion_time = time;
                p[highest].turnaround_time = p[highest].completion_time - p[highest].arrival_time;
                p[highest].waiting_time = p[highest].turnaround_time - p[highest].burst_time;
            }
        }
    }
    float total_wt = 0, total_tat = 0;
    printf("\nPID\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival_time,
               p[i].burst_time,
               p[i].priority,
               p[i].completion_time,
               p[i].turnaround_time,
               p[i].waiting_time);
        total_wt += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
    }
    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
    return 0;
}
