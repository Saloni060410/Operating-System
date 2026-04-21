#include <stdio.h>

int main() {
    int size[] = {100,300,40,50,150,240,200,400};
    int status[] = {0,1,0,1,0,1,0,1};

    char process[8][10] = {"P1","-","P2","-","P3","-","P4","-"};

    int n = 8;

    int req[] = {60, 70, 120};   // new processes
    int m = 3;

    for(int i = 0; i < m; i++) {
        int bestIdx = -1;

        for(int j = 0; j < n; j++) {
            if(status[j] == 0 && size[j] >= req[i]) {
                if(bestIdx == -1 || size[j] < size[bestIdx]) {
                    bestIdx = j;
                }
            }
        }

        if(bestIdx != -1) {
            printf("Process %d allocated to block %d\n", i+1, bestIdx+1);
            status[bestIdx] = 1;
        } else {
            printf("Process %d not allocated\n", i+1);
        }
    }

    return 0;
}