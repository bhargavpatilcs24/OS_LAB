#include <stdio.h>

int main()
{
int n, i;
float totalsys_wt=0,totalsys_tat=0,totaluser_wt=0,totaluser_tat=0;
int sys_bt[20], user_bt[20];
int sys_wt[20], user_wt[20];
int sys_tat[20], user_tat[20];
int sys_n, user_n;
printf("Enter number of system processes: ");
scanf("%d", &sys_n);
for(i = 0; i < sys_n; i++)
{
printf("Enter burst time of system process %d: ", i+1);
scanf("%d", &sys_bt[i]);
}
printf("\nEnter number of user processes: ");
scanf("%d", &user_n);
for(i = 0; i < user_n; i++)
{
printf("Enter burst time of user process %d: ", i+1);
scanf("%d", &user_bt[i]);
}

/* FCFS for system processes */

sys_wt[0] = 0;
for(i = 1; i < sys_n; i++){
sys_wt[i] = sys_wt[i-1] + sys_bt[i-1];
totalsys_wt+=sys_wt[i];}

for(i = 0; i < sys_n; i++){
sys_tat[i] = sys_wt[i] + sys_bt[i];
totalsys_tat+=sys_tat[i];}

/* FCFS for user processes */
user_wt[0] = sys_wt[sys_n-1] + sys_bt[sys_n-1];
totaluser_wt=user_wt[0];
for(i = 1; i < user_n; i++){
user_wt[i] = user_wt[i-1] + user_bt[i-1];
totaluser_wt+=user_wt[i];}

for(i = 0; i < user_n; i++){
user_tat[i] = user_wt[i] + user_bt[i];
totaluser_tat+=user_tat[i];}

printf("\nSystem Processes:\n");
printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

for(i = 0; i < sys_n; i++)
    printf("S%d\t%d\t\t%d\t\t%d\n", i+1, sys_bt[i], sys_wt[i], sys_tat[i]);

printf("\nUser Processes:\n");
printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

for(i = 0; i < user_n; i++)
printf("U%d\t%d\t\t%d\t\t%d\n", i+1, user_bt[i], user_wt[i], user_tat[i]);

printf("\nAverage System waiting time: %.2f",totalsys_wt/sys_n);
printf("\nAverage System turnaround time: %.2f\n",totalsys_tat/sys_n);

printf("\nAverage User waiting time: %.2f",totaluser_wt/user_n);
printf("\nAverage User turnaround time: %.2f\n",totaluser_tat/user_n);
return 0;
}
