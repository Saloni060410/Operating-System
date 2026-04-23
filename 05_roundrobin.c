#include <stdio.h>

// Round Robin with Gantt Chart
void roundRobin(int bt[], int rt[], int wt[], int tat[], int n, int tq) {
    int time = 0, done;

    printf("\nGantt Chart:\n|");

    do {
        done = 1;

        for(int i = 0; i < n; i++) {
            if(rt[i] > 0) {
                done = 0;

                printf(" P%d |", i+1);

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

    // Print time line
    printf("\n0");
    time = 0;

    // Re-simulate just for time printing
    int temp_rt[n];
    for(int i=0;i<n;i++) temp_rt[i] = bt[i];

    do {
        done = 1;

        for(int i = 0; i < n; i++) {
            if(temp_rt[i] > 0) {
                done = 0;

                if(temp_rt[i] > tq) {
                    time += tq;
                    temp_rt[i] -= tq;
                } else {
                    time += temp_rt[i];
                    temp_rt[i] = 0;
                }

                printf("   %d", time);
            }
        }

    } while(done == 0);
}

// Average
void calculateAvg(int wt[], int tat[], int n) {
    float sum_wt = 0, sum_tat = 0;

    for(int i = 0; i < n; i++) {
        sum_wt += wt[i];
        sum_tat += tat[i];
    }

    printf("\n\nAverage WT = %.2f", sum_wt/n);
    printf("\nAverage TAT = %.2f\n", sum_tat/n);
}

int main() {
    int n, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rt[n], wt[n], tat[n];

    for(int i = 0; i < n; i++) {
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    roundRobin(bt, rt, wt, tat, n, tq);

    printf("\n\nProcess\tBT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], tat[i], wt[i]);
    }

    calculateAvg(wt, tat, n);

    return 0;
}