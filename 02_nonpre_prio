#include <stdio.h>

// Function to find next process based on priority
int findHighestPriority(int at[], int pr[], int completed[], int n, int time) {
    int index = -1;
    int highestPriority = 9999;

    for(int i = 0; i < n; i++) {
        if(at[i] <= time && completed[i] == 0) {
            if(pr[i] < highestPriority) {
                highestPriority = pr[i];
                index = i;
            }
        }
    }
    return index;
}

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], pr[n];
    int ct[n], wt[n], tat[n], completed[n];

    // Input
    printf("Enter Arrival Time, Burst Time and Priority:\n");
    for(int i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        completed[i] = 0;
    }

    int time = 0, done = 0;

    // Scheduling loop
    while(done < n) {
        int index = findHighestPriority(at, pr, completed, n, time);

        if(index == -1) {
            time++;  // CPU idle
        } else {
            ct[index] = time + bt[index];
            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];

            time = ct[index];
            completed[index] = 1;
            done++;
        }
    }

    // Display
    float total_wt = 0, total_tat = 0;

    printf("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);

        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}