#include <stdio.h>

void optimal(int pages[], int n, int frames) {
    int frame[frames];
    int pageFaults = 0;

    // initialize frames
    for(int i = 0; i < frames; i++)
        frame[i] = -1;

    for(int i = 0; i < n; i++) {
        int found = 0;

        // check hit
        for(int j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // if page fault
        if(found == 0) {

            int pos = -1, farthest = i+1;

            // find optimal replacement here itself
            for(int j = 0; j < frames; j++) {
                
                int k;

                for(k = i+1; k < n; k++) {
                    if(frame[j] == pages[k]) {
                        if(k > farthest) {
                            farthest = k;
                            pos = j;
                        }
                        break;
                    }
                }

                // not used in future → replace immediately
                if(k == n) {
                    pos = j;
                    break;
                }
            }

            if(pos == -1) pos = 0;

            frame[pos] = pages[i];
            pageFaults++;
        }

        // print frame
        printf("\nAfter page %d: ", pages[i]);
        for(int j = 0; j < frames; j++) {
            if(frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d\n", pageFaults);
    printf("Total Page Hits = %d\n", n - pageFaults);
}

int main() {
    int n, frames;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];

    printf("Enter page reference string:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    optimal(pages, n, frames);

    return 0;
}