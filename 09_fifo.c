#include <stdio.h>

// Function for FIFO Page Replacement
void fifo(int pages[], int n, int frames) {
    int frame[frames];
    int front = 0;
    int pageFaults = 0;

    // Initialize frames as empty (-1)
    for(int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    for(int i = 0; i < n; i++) {
        int found = 0;

        // Check if page already in frame (hit)
        for(int j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // If not found → page fault
        if(found == 0) {
            frame[front] = pages[i];
            front = (front + 1) % frames;
            pageFaults++;
        }

        // Display frame status
        printf("\nAfter page %d: ", pages[i]);
        for(int j = 0; j < frames; j++) {
            if(frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
    }

    printf("\n\nTotal Page Faults = %d\n", pageFaults);
    printf("\n Total page hits = %d\n",n-pageFaults);
}

int main() {
    int n, frames;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];
