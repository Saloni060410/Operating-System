#include <stdio.h>

// Function to perform Round Robin scheduling
void roundRobin(int bt[], int rt[], int wt[], int tat[], int n, int tq) {
    int time = 0, done;

    do {
        done = 1;

        for(int i = 0; i < n; i++) {
            if(rt[i] > 0) {
                done = 0;

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];

                    tat[i] = time;          // AT = 0
                    wt[i] = tat[i] - bt[i];

                    rt[i] = 0;
                }
            }
        }

    } while(done == 0);
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
    int n, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rt[n], wt[n], tat[n];

    // Input
    printf("Enter burst time:\n");
    for(int i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];  // initialize remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    // Function call
    roundRobin(bt, rt, wt, tat, n, tq);

    // Output
    printf("\nProcess\tBT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], tat[i], wt[i]);
    }

    calculateAvg(wt, tat, n);

    return 0;
}