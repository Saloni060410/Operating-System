#include <stdio.h>

// Function to sort by burst time (SJF)
void sortByBurst(int bt[], int p[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(bt[j] > bt[j+1]) {
                // swap burst time
                int temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                // swap process id
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

// Function to calculate waiting time
void calculateWT(int bt[], int wt[], int n) {
    wt[0] = 0;
    for(int i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }
}

// Function to calculate turnaround time
void calculateTAT(int bt[], int wt[], int tat[], int n) {
    for(int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }
}

// Function to calculate averages
void calculateAvg(int wt[], int tat[], int n) {
    float sum_wt = 0, sum_tat = 0;

    for(int i = 0; i < n; i++) {
        sum_wt += wt[i];
        sum_tat += tat[i];
    }

    printf("\nAverage WT = %.2f", sum_wt/n);
    printf("\nAverage TAT = %.2f\n", sum_tat/n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n], p[n];

    // Input
    printf("Enter burst time:\n");
    for(int i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i+1;  // process id
    }

    // Sort by burst time
    sortByBurst(bt, p, n);

    // Calculate times
    calculateWT(bt, wt, n);
    calculateTAT(bt, wt, tat, n);

    // Output
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    calculateAvg(wt, tat, n);

    return 0;
}