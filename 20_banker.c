#include <stdio.h>

#define MAX 10

int main() {
    int n, m;
    int alloc[MAX][MAX], max[MAX][MAX], need[MAX][MAX];
    int avail[MAX];
    int finish[MAX], safeSeq[MAX];
    int i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Maximum Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    // Need = Max - Allocation
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // -------- SAFETY ALGORITHM --------
    int work[MAX];
    for(i = 0; i < m; i++)
        work[i] = avail[i];

    for(i = 0; i < n; i++)
        finish[i] = 0;

    int count = 0;

    while(count < n) {
        int found = 0;

        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {

                int possible = 1;
                for(j = 0; j < m; j++) {
                    if(need[i][j] > work[j]) {
                        possible = 0;
                        break;
                    }
                }

                if(possible) {
                    for(k = 0; k < m; k++)
                        work[k] += alloc[i][k];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0) {
            printf("\nSystem is NOT in safe state.\n");
            return 0;
        }
    }

    printf("\nSystem is in SAFE state.\nSafe Sequence: ");
    for(i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);

    // -------- RESOURCE REQUEST ALGORITHM --------
    int req[MAX], p;

    printf("\n\nEnter process number making request: ");
    scanf("%d", &p);

    printf("Enter request vector:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &req[i]);

    // Step 1: Request <= Need
    for(i = 0; i < m; i++) {
        if(req[i] > need[p][i]) {
            printf("Error: Request exceeds maximum need.\n");
            return 0;
        }
    }

    // Step 2: Request <= Available
    for(i = 0; i < m; i++) {
        if(req[i] > avail[i]) {
            printf("Resources not available. Process must wait.\n");
            return 0;
        }
    }

    // Step 3: Pretend allocation
    for(i = 0; i < m; i++) {
        avail[i] -= req[i];
        alloc[p][i] += req[i];
        need[p][i] -= req[i];
    }

    // -------- SAFETY CHECK AGAIN --------
    for(i = 0; i < m; i++)
        work[i] = avail[i];

    for(i = 0; i < n; i++)
        finish[i] = 0;

    count = 0;

    while(count < n) {
        int found = 0;

        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {

                int possible = 1;
                for(j = 0; j < m; j++) {
                    if(need[i][j] > work[j]) {
                        possible = 0;
                        break;
                    }
                }

                if(possible) {
                    for(k = 0; k < m; k++)
                        work[k] += alloc[i][k];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0) {
            printf("\nRequest cannot be granted (unsafe state).\n");
            return 0;
        }
    }

    printf("\nRequest can be granted.\nNew Safe Sequence: ");
    for(i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);

    printf("\n");

    return 0;
}