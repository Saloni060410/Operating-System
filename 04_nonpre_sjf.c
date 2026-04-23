#include <stdio.h>

// Sort by burst time
void sortByBurst(int bt[], int p[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(bt[j] > bt[j+1]) {
                int temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n], p[n];

    // Input
    for(int i = 0; i < n; i++) {
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }

    // Sort (SJF)
    sortByBurst(bt, p, n);

    // Waiting Time
    wt[0] = 0;
    for(int i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    // Turnaround Time
    for(int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    // ✅ Gantt Chart
    printf("\nGantt Chart:\n|");
    for(int i = 0; i < n; i++) {
        printf(" P%d |", p[i]);
    }

    printf("\n0");
    int time = 0;
    for(int i = 0; i < n; i++) {
        time += bt[i];
        printf("   %d", time);
    }

    // Table
    float total_wt = 0, total_tat = 0;

    printf("\n\nProcess\tBT\tWT\tTAT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAvg WT = %.2f", total_wt/n);
    printf("\nAvg TAT = %.2f\n", total_tat/n);

    return 0;
}