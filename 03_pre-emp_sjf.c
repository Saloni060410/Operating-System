#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], wt[n], tat[n];

    for(int i = 0; i < n; i++) {
        printf("\nP%d Arrival Time: ", i+1);
        scanf("%d", &at[i]);

        printf("P%d Burst Time: ", i+1);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
    }

    int time = 0, completed = 0;

    int prev = -1;
    int start[100], process[100], k = 0;

    printf("\nGantt Chart:\n|");

    while(completed < n) {
        int min = 999, idx = -1;

        for(int i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && rt[i] < min) {
                min = rt[i];
                idx = i;
            }
        }

        if(idx != -1) {
            if(prev != idx) {
                printf(" P%d |", idx+1);
                process[k] = idx;
                start[k] = time;
                k++;
                prev = idx;
            }

            rt[idx]--;
            time++;

            if(rt[idx] == 0) {
                completed++;
                tat[idx] = time - at[idx];
                wt[idx] = tat[idx] - bt[idx];
            }

        } else {
            time++; // idle
        }
    }

    // Print time line
    printf("\n0");
    for(int i = 0; i < k; i++) {
        int end;
        if(i == k-1)
            end = time;
        else
            end = start[i+1];

        printf("   %d", end);
    }

    // Table
    float total_wt = 0, total_tat = 0;

    printf("\n\nProcess\tAT\tBT\tWT\tTAT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAvg WT = %.2f", total_wt/n);
    printf("\nAvg TAT = %.2f\n", total_tat/n);

    return 0;
}