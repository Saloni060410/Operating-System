#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter requests:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    int seek = 0;


    printf("Seek Sequence: %d", head);

    for(int i = 0; i < n; i++) {
        seek += abs(head - req[i]);
        head = req[i];
        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time = %d\n", seek);
    return 0;
}