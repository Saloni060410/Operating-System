#include <stdio.h>
#include <stdlib.h>

// Semaphores
int empty, full, buffer_access;
int buffer_size;
int in = 0, out = 0;

// wait
void wait(int *s) {
    (*s)--;
}

// signal
void signal(int *s) {
    (*s)++;
}

// print semaphore values
void printStatus() {
    printf("empty=%d full=%d buffer_access=%d\n", empty, full, buffer_access);
}

// Producer
void producer() {
    printf("\nProducer is scheduled\n");

    if (empty == 0) {
        printf("Producer BLOCKED (Buffer Full)\n");
        printStatus();
        return;
    }

    wait(&empty);
    wait(&buffer_access);

    printf("Producing at position %d\n", in);
    in = (in + 1) % buffer_size;

    signal(&buffer_access);
    signal(&full);

    printStatus();
}

// Consumer
void consumer() {
    printf("\nConsumer is scheduled\n");

    if (full == 0) {
        printf("Consumer BLOCKED (Buffer Empty)\n");
        printStatus();
        return;
    }

    wait(&full);
    wait(&buffer_access);

    printf("Consuming from position %d\n", out);
    out = (out + 1) % buffer_size;

    signal(&buffer_access);
    signal(&empty);

    printStatus();
}

// Main
int main() {
    int choice;

    printf("Enter buffer size: ");
    scanf("%d", &buffer_size);

    empty = buffer_size;
    full = 0;
    buffer_access = 1;

    while (1) {
        printf("\n1. Producer\n2. Consumer\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: producer(); break;
            case 2: consumer(); break;
            case 3: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}