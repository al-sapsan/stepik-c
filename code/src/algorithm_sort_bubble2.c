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

    // Bubble sort variant with flag
    int right_side;// The right side of the array that is already sorted
    bool exchange; // Flag to check if a swap was made
    for(right_side = SIZE - 1; right_side > 0; right_side--) {
        exchange = false; // Reset the flag for each pass
        for(int i = 0; i < right_side; i++) { //i - the first element from sorted pair 
            if(array[i] > array[i + 1]) {
                // Swap the elements
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                exchange = true; // Set the flag to true if a swap was made
            }
        }
        if (!exchange) { // If no swaps were made, the array is sorted
            break;
        }
    }
    /*
    bool exchange = true; // Flag to check if a swap was made
    int right_side = SIZE - 1; // The right side of the array that is already sorted
    while (right_side > 0 && exchange) {
        exchange = false; // Reset the flag for each pass
        for (int i = 0; i < right_side; i++) { // i - the first element from sorted pair
            if (array[i] > array[i + 1]) {
                // Swap the elements
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                exchange = true; // Set the flag to true if a swap was made
            }
        }
        right_side--; // Reduce the right side of the array that is already sorted
    }
    */
    // Print the final sorted array
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}