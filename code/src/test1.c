#include <stdio.h>
#include <stdlib.h>  // Fixed missing .h

#define SIZE 10
#define MAX_VALUE 20
#define MIN_VALUE -20
#define RANGE (MAX_VALUE - MIN_VALUE + 1)

int main() {
    int array[SIZE];
    int *ptr = array;
    int *end_ptr = array + SIZE;
    int seed;

    // Get seed from user
    scanf("%d", &seed);
    srand(seed);

    // Fill array with random numbers
    for (; ptr < end_ptr; ptr++) {
        *ptr = rand() % RANGE + MIN_VALUE;
    }

    // Print original array
    ptr = array;
    for (; ptr < end_ptr; ptr++) {
        printf("%d ", *ptr);
    }
    printf("\n");

    // Reverse array using two pointers
    int *left = array;            // Pointer to first element
    int *right = array + SIZE - 1; // Pointer to last element

    while (left < right) {
        // Swap values at left and right pointers
        int temp = *left;
        *left = *right;
        *right = temp;

        // Move pointers towards center
        left++;
        right--;
    }

    // Print reversed array
    ptr = array;
    for (; ptr < end_ptr; ptr++) {
        printf("%d ", *ptr);
    }
    printf("\n");

    return 0;
}