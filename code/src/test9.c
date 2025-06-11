#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

/**
 * @brief Generates an array of SIZE random integers, sorts it in ascending order, and prints the result.
 *
 * The user enters the seed for the random number generator.
 * The program fills the array with random numbers from 1 to 20, sorts it using selection sort,
 * and prints the sorted array (elements separated by spaces, including after the last element).
 *
 * @return 0 on successful completion
 */
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
        array[i] = rand() % 20 + 1;
    }

    // Selection sort
    int max_index;
    for (int i = 0; i < SIZE - 1; i++) {
        max_index = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (array[j] > array[max_index]) {
                max_index = j;
            }
        }
        if (max_index != i) {
            int temp = array[i];
            array[i] = array[max_index];
            array[max_index] = temp;
        }
    }

    // Print the sorted array
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}

