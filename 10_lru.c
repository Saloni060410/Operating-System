#include <stdio.h>

// Function for LRU Page Replacement
void lru(int pages[], int n, int frames) {
    int frame[frames], time[frames];
    int pageFaults = 0;

    // Initialize frames
    for(int i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        int found = 0;

        // Check for hit
        for(int j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                time[j] = i;  // update last used time
                break;
            }
        }

        // Page fault
        if(found == 0) {
            int lruIndex = 0;

            // Find least recently used
            for(int j = 1; j < frames; j++) {
                if(time[j] < time[lruIndex]) {
                    lruIndex = j;
                }
            }

            frame[lruIndex] = pages[i];
            time[lruIndex] = i;
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

    printf("Enter page reference string:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    // Function call
    lru(pages, n, frames);

    return 0;
}
