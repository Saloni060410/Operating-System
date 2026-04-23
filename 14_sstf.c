#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n], done[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        done[i] = 0;
    }

    printf("Enter head position: ");
    scanf("%d", &head);

    int seek = 0;


    printf("Seek Sequence: %d", head);

    for(int i = 0; i < n; i++) {
        int min = 9999, idx = -1;

        for(int j = 0; j < n; j++) {
            if(!done[j] && abs(head - req[j]) < min) {
                min = abs(head - req[j]);
                idx = j;
            }
        }

        seek += min;
        head = req[idx];
        done[idx] = 1;
        printf(" -> %d", head);
    }

    printf("\n");
    printf("Total Seek Time = %d\n", seek);
    return 0;
}