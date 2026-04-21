#include <stdio.h>

#define MAX 10

int main() {
    int n, m; // n = processes, m = resources
    int alloc[MAX][MAX], max[MAX][MAX], need[MAX][MAX];
    int avail[MAX];
    int finish[MAX] = {0}, safeSeq[MAX];
    int i, j, k, count = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    // Allocation matrix
    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    // Max matrix
    printf("Enter Maximum Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    // Available resources
    printf("Enter Available Resources:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    // Calculate Need matrix = Max - Allocation
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Banker's Algorithm
    while(count < n) {
        int found = 0;

        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {

                int canExecute = 1;

                for(j = 0; j < m; j++) {
                    if(need[i][j] > avail[j]) {
                        canExecute = 0;
                        break;
                    }
                }

                if(canExecute) {
                    for(k = 0; k < m; k++) {
                        avail[k] += alloc[i][k];
                    }

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0) {
            printf("\nSystem is NOT in safe state (Deadlock possible)\n");
            return 0;
        }
    }

    // Safe sequence
    printf("\nSystem is in SAFE state.\nSafe Sequence: ");
    for(i = 0; i < n; i++) {
        printf("P%d ", safeSeq[i]);
    }

    printf("\n");
    return 0;
}