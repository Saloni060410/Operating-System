#include <stdio.h>
#include <stdlib.h>

// Semaphore variables
int empty, full, mutex;
int buffer_size;
int in = 0, out = 0;

// wait operation
void wait(int *s) {
    (*s)--;
}

// signal operation
void signal(int *s) {
    (*s)++;
}

// Producer function
void producer() {
    if (empty == 0) {
        printf("Buffer FULL! Producer blocked.\n");
        return;
    }

    wait(&empty);
    wait(&mutex);

    printf("Produced item at position %d\n", in);
    in = (in + 1) % buffer_size;

    signal(&mutex);
    signal(&full);
}

// Consumer function
void consumer() {
    if (full == 0) {
        printf("Buffer EMPTY! Consumer blocked.\n");
        return;
    }

    wait(&full);
    wait(&mutex);

    printf("Consumed item from position %d\n", out);
    out = (out + 1) % buffer_size;

    signal(&mutex);
    signal(&empty);
}

// Main function
int main() {
    int choice;

    printf("Enter buffer size: ");
    scanf("%d", &buffer_size);

    empty = buffer_size;
    full = 0;
    mutex = 1;

    while (1) {
        printf("\n1. Producer\n2. Consumer\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}