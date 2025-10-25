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

    // Bubble sort variant with flag of last exchange
    int last; // The last index where a swap was made
    int right_side = SIZE - 1; 
    while (right_side > 0) {
        last = -1; // non-existent value in array
        for (int i = 0; i < right_side; i++) { // i - the first element from sorted pair
            if (array[i] > array[i + 1]) {
                // Swap the elements using the three-glass rule
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                last = i; // Update the last index where a swap was made
            }
        }
        right_side = last; // Update the right side to the last swap index
    }

    // Print the final sorted array
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}