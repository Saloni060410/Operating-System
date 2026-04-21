#include <stdio.h>

// Function to calculate waiting time
void calculateWaitingTime(int bt[], int wt[], int n) {
    wt[0] = 0;

    for(int i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }
}

// Function to calculate turnaround time
void calculateTurnaroundTime(int bt[], int wt[], int tat[], int n) {
    for(int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }
}

// Single function to calculate both averages
void calculateAverages(int wt[], int tat[], int n) {
    float sum_wt = 0, sum_tat = 0;

    for(int i = 0; i < n; i++) {
        sum_wt += wt[i];
        sum_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", sum_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", sum_tat / n);
}

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];

    // Input burst times
    printf("Enter burst time for each process:\n");
    for(int i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
    }

    // Function calls
    calculateWaitingTime(bt, wt, n);
    calculateTurnaroundTime(bt, wt, tat, n);

    // Display results directly in main
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    // Call combined average function
    calculateAverages(wt, tat, n);

    return 0;
}