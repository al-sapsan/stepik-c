#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

int main() {
    int array[SIZE];
    int *ptr = array;          // Pointer to array start
    int *end_ptr = array + SIZE; // Pointer to end of array

    // Input array elements
    for (; ptr < end_ptr; ptr++) {
        scanf("%d", ptr);  // Direct pointer input
    }

    // Reset pointer to start
    ptr = array;

    // Swap even and odd indices (stop before last element if SIZE is odd)
    int *swap_end = (SIZE % 2 == 0) ? end_ptr : end_ptr - 1;
    while (ptr < swap_end) {
        // Swap current and next element
        int temp = *ptr;
        *ptr = *(ptr + 1);
        *(ptr + 1) = temp;
        
        // Move pointer 2 positions ahead
        ptr += 2;
    }

    // Print the modified array
    ptr = array;
    while (ptr < end_ptr) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");

    return 0;
}