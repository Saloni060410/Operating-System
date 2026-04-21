#include <stdio.h>

// Function to find which page to replace
int findOptimal(int pages[], int frame[], int n, int index, int frames) {
    int farthest = index, pos = -1;

    for(int i = 0; i < frames; i++) {
        int j;

        // Look ahead in future
        for(j = index; j < n; j++) {
            if(frame[i] == pages[j]) {
                if(j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }

        // If page not found in future
        if(j == n) {
            return i;
        }
    }

    return (pos == -1) ? 0 : pos;
}

// Function for Optimal Page Replacement
void optimal(int pages[], int n, int frames) {
    int frame[frames];
    int pageFaults = 0;

    // Initialize frames
    for(int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    for(int i = 0; i < n; i++) {
        int found = 0;

        // Check for hit
        for(int j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // Page fault
        if(found == 0) {
            int pos = findOptimal(pages, frame, n, i+1, frames);

            frame[pos] = pages[i];
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
    optimal(pages, n, frames);

    return 0;
}
