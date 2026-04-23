#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], at[n], pr[n], wt[n], tat[n], completed[n];

    // Input
    for(i = 0; i < n; i++) {
        printf("\nProcess P%d:\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority (lower = higher priority): ");
        scanf("%d", &pr[i]);
        completed[i] = 0;
    }

    int time = 0, count = 0;

    printf("\nGantt Chart:\n|");

    while(count < n) {
        int min_pr = 999, idx = -1;

        // Find highest priority process available
        for(i = 0; i < n; i++) {
            if(at[i] <= time && completed[i] == 0) {
                if(pr[i] < min_pr) {
                    min_pr = pr[i];
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            printf(" P%d |", idx+1);
            wt[idx] = time - at[idx]; // waiting time
            time += bt[idx];
            printf("%d", time);
            tat[idx] = wt[idx] + bt[idx];
            completed[idx] = 1;
            count++;
        } else {
            time++; // CPU idle
        }
    }

    // Averages
    float total_wt = 0, total_tat = 0;
    for(i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\n\nProcess\tAT\tBT\tPR\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], pr[i], wt[i], tat[i]);
    }

    printf("\nAvg WT = %.2f", total_wt/n);
    printf("\nAvg TAT = %.2f", total_tat/n);

    return 0;
}