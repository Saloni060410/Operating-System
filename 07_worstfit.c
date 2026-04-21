#include <stdio.h>

int main() {
    // Predefined memory blocks
    int size[]   = {100, 300, 40, 50, 150, 240, 200, 400};
    int status[] = {0,   1,   0,  1,   0,   1,   0,   1};

    char process[8][10] = {"P1","-","P2","-","P3","-","P4","-"};

    int n = 8;

    // New processes to allocate
    int req[] = {60, 70, 120};
    int m = 3;

    for(int i = 0; i < m; i++) {
        int worstIdx = -1;

        for(int j = 0; j < n; j++) {
            if(status[j] == 0 && size[j] >= req[i]) {

                if(worstIdx == -1 || size[j] > size[worstIdx]) {
                    worstIdx = j;
                }
            }
        }

        if(worstIdx != -1) {
            printf("Process %d (%d KB) allocated to block %d (%d KB)\n",i+1, req[i], worstIdx+1, size[worstIdx]);

            status[worstIdx] = 1;   // mark as occupied
        } else {
            printf("Process %d (%d KB) not allocated\n", i+1, req[i]);
        }
    }

    return 0;
}