#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

int main() {

    int array[SIZE];
    int key;

    // Read the key for random number generation
    if(scanf("%d", &key) != 1) {
        puts("Error reading input\n");
        return 0;
    }
    srand(key);

    // Fill the array with random numbers from 1 to 20
    for(int i = 0; i < SIZE; i++) {
        array[i] = rand() % 21;
        printf("%d ", array[i]);
    }
    printf("\n");

    // Shaker sort algorithm implementation
    int low = 0, up = SIZE - 1; // Initialize the left and right boundaries
    int last, temp;
    while (low < up) {
        last = -1; // non-existent value in array
        for (int i = low; i < up; i++) { // i - the first element from sorted pair
            if (array[i] > array[i + 1]) {
                // Swap the elements using the three-glass rule
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                last = i; // Update the last index where a swap was made
            }
        }
        up = last; // Update the right side to the last swap index
        if (last == -1) {
            break; // If no swaps were made, the array is sorted
        }
        last = SIZE; // Reset last for the next pass
        for (int i = up - 1; i >= low; i--) { // i - the last element from sorted pair
            if (array[i] > array[i + 1]) {
                // Swap the elements using the three-glass rule
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                last = i; // Update the last index where a swap was made
            }
        }
        low = last + 1; // Update the left side to the last swap index
    }

    // Print the final sorted array
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}