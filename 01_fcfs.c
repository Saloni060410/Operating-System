

#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];

    // Input burst time
    for(i = 0; i < n; i++) {
        printf("Enter Burst Time for P%d: ", i+1);
        scanf("%d", &bt[i]);
    }

    // First process waiting time is always 0
    wt[0] = 0;

    // Calculate waiting time
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];  // sum of previous burst times
    }

    // Calculate turnaround time
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i]; // TAT = WT + BT
    }

    // Print Gantt Chart
    printf("\nGantt Chart:\n");
    printf("|");
    for(i = 0; i < n; i++) {
        printf(" P%d |", i+1);
    }

    printf("\n0");
    int time = 0;
    for(i = 0; i < n; i++) {
        time += bt[i];
        printf("   %d", time);
    }

    // Calculate averages
    float total_wt = 0, total_tat = 0;
    for(i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\n\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    printf("\nAvg WT = %.2f", total_wt/n);
    printf("\nAvg TAT = %.2f", total_tat/n);

    return 0;
}