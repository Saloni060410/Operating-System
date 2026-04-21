#include <stdio.h>

// Function for First Fit allocation
void firstFit(int blockSize[], int m, int processSize[], int n, int allocation[]) {

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < m; j++) {
            if(blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;  // move to next process
            }
        }
    }
}

int main() {
    int m, n;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    int blockSize[m];
    printf("Enter block sizes:\n");
    for(int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int processSize[n], allocation[n];

    printf("Enter process sizes:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
        allocation[i] = -1;  // initially not allocated
    }

    // Function call
    firstFit(blockSize, m, processSize, n, allocation);

    // Display in main
    printf("\nProcess\tSize\tBlock\n");
    for(int i = 0; i < n; i++) {
        if(allocation[i] != -1)
            printf("P%d\t%d\t%d\n", i+1, processSize[i], allocation[i]+1);
        else
            printf("P%d\t%d\tNot Allocated\n", i+1, processSize[i]);
    }

    return 0;
}