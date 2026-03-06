#include <stdio.h>
#include <limits.h>
void main()
{
    int i,time=0,smallest;
    int at[5],bt[5],rt[5];
    int ct[5],wt[5],tat[5];
    int completed=0;
    float avgwt=0,avgtat=0;
    for(i=0;i<5;i++){
        printf("\nProcess P%d\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&at[i]);
        printf("Burst Time: ");
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }
    while(completed!=5){
        smallest=-1;
        int min=INT_MAX;
        for(i=0;i<5;i++){
            if(at[i]<=time && rt[i]>0 && rt[i]<min){
                min=rt[i];
                smallest=i;
            }
        }
        if(smallest==-1){
            time++;
            continue;
        }
        rt[smallest]--;
        time++;
        if(rt[smallest]==0){
            completed++;
            ct[smallest]=time;
            tat[smallest]=ct[smallest]-at[smallest];
            wt[smallest]=tat[smallest]-bt[smallest];
            avgwt+=wt[smallest];
            avgtat+=tat[smallest];
        }
    }
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<5;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAverage Waiting Time = %.2f",avgwt/5);
    printf("\nAverage Turnaround Time = %.2f\n",avgtat/5);
}
