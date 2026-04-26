#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, head, size;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    sort(req, n);

    int start=head;

    int seek = 0;
    printf("Seek Sequence: %d", head);

    // Move right
    for(int i = 0; i < n; i++) {
        if(req[i] >= start) {
            seek += abs(head - req[i]);
            head = req[i];
            printf(" -> %d", head);
        }
    }

    // Go to end
    seek += abs(head - (size-1));
    head = size-1;
    printf(" -> %d", head);

    // Move left
    for(int i = n-1; i >= 0; i--) {
        if(req[i] < start) {
            seek += abs(head - req[i]);
            head = req[i];
            printf(" -> %d", head);
        }
    }

    printf("\n");
    printf("Total Seek Time = %d\n", seek);
    return 0;
}