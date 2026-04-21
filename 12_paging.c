#include <stdio.h>
#include <string.h>

#define MAX 100

// Function to calculate log2
int log2_int(int n) {
    int count = 0;
    while(n > 1) {
        n = n / 2;
        count++;
    }
    return count;
}

int main() {
    int process_kb, page_size_bytes, memory_mb;
    int process_bytes, memory_bytes;
    int total_pages, total_frames;
    int logical_bits, physical_bits;
    int page_bits, offset_bits, frame_bits;

    // Input
    printf("Enter size of process (in KB): ");
    scanf("%d", &process_kb);

    printf("Enter Page Size (in bytes): ");
    scanf("%d", &page_size_bytes);

    printf("Enter size of main memory (in MB): ");
    scanf("%d", &memory_mb);

    // Convert to bytes
    process_bytes = process_kb * 1024;
    memory_bytes = memory_mb * 1024 * 1024;

    // Calculations
    total_pages = process_bytes / page_size_bytes;
    total_frames = memory_bytes / page_size_bytes;

    logical_bits = log2_int(process_bytes);
    physical_bits = log2_int(memory_bytes);
    offset_bits = log2_int(page_size_bytes);

    page_bits = logical_bits - offset_bits;
    frame_bits = physical_bits - offset_bits;

    // Output
    printf("\n1. Total number of frames = %d\n", total_frames);
    printf("2. Number of entries in page table = %d\n", total_pages);

    printf("3. Physical Address Bits = %d bits\n", physical_bits);
    printf("   Distribution: %d bits (Frame) + %d bits (Offset)\n", frame_bits, offset_bits);

    printf("4. Logical Address Bits = %d bits\n", logical_bits);
    printf("   Distribution: %d bits (Page) + %d bits (Offset)\n", page_bits, offset_bits);

    // Page Table
    int page_table[MAX][2];  // [frame_no, valid_bit]

    // Initialize
    for(int i = 0; i < total_pages; i++) {
        page_table[i][0] = -1;
        page_table[i][1] = 0;
    }

    // Input page table
    char choice;
    int page_no, frame_no;

    printf("\nEnter Valid Page Table Entries\n");

    while(1) {
        printf("Enter Page Number: ");
        scanf("%d", &page_no);

        if(page_no >= total_pages) {
            printf("Invalid Page Number!\n");
            continue;
        }

        printf("Enter Frame Number: ");
        scanf("%d", &frame_no);

        page_table[page_no][0] = frame_no;
        page_table[page_no][1] = 1;

        printf("Do you want to enter more? (Y/N): ");
        scanf(" %c", &choice);

        if(choice == 'N' || choice == 'n')
            break;
    }

    // Logical Address
    char logical_address[50];
    printf("\nEnter Logical Address in Binary (%d bits): ", logical_bits);
    scanf("%s", logical_address);

    int page_number = 0, offset = 0;

    // Extract page number
    for(int i = 0; i < page_bits; i++) {
        page_number = page_number * 2 + (logical_address[i] - '0');
    }

    // Extract offset
    for(int i = page_bits; i < logical_bits; i++) {
        offset = offset * 2 + (logical_address[i] - '0');
    }

    printf("\nPage Number = %d\n", page_number);
    printf("Offset = %d\n", offset);

    // Check page table
    if(page_number >= total_pages) {
        printf("Invalid Logical Address\n");
    }
    else if(page_table[page_number][1] == 1) {
        printf("Page Hit\n");

        int physical_address = page_table[page_number][0] * page_size_bytes + offset;

        printf("Physical Address (Decimal) = %d\n", physical_address);

        printf("Physical Address (Binary) = ");
        for(int i = physical_bits - 1; i >= 0; i--) {
            printf("%d", (physical_address >> i) & 1);
        }
        printf("\n");
    }
    else {
        printf("Page Fault\n");
    }

    return 0;
}