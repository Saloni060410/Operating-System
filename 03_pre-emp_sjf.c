#include <stdio.h>

// Function to find process with minimum remaining time
int findShortest(int at[], int rt[], int n, int time) {
    int idx = -1;
    int min = 9999;

    for(int i = 0; i < n; i++) {
        if(at[i] <= time && rt[i] > 0) {
            if(rt[i] < min) {
                min = rt[i];
                idx = i;
            }
        }
    }
    return idx;
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n];
    int ct[n], wt[n], tat[n];

    // Input
    printf("Enter Arrival Time and Burst Time:\n");
    for(int i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];  // remaining time
    }

    int time = 0, done = 0;

    // Scheduling
    while(done < n) {
        int idx = findShortest(at, rt, n, time);

        if(idx == -1) {
            time++;  // CPU idle
        } else {
            rt[idx]--;  // execute for 1 unit
            time++;

            // If process completes
            if(rt[idx] == 0) {
                ct[idx] = time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
                done++;
            }
        }
    }

    // Output
    float total_wt = 0, total_tat = 0;

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);

        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAvg WT = %.2f", total_wt/n);
    printf("\nAvg TAT = %.2f\n", total_tat/n);

    return 0;
}