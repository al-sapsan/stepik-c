#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

/**
 * @brief Generates an array of SIZE random integers, sorts it using insertion sort, and prints the sorted array.
 *
 * The user enters the seed for the random number generator.
 * The program fills the array with random numbers from 0 to 50, sorts it using insertion sort,
 * and prints the sorted array (elements separated by tabs, including after the last element).
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

    // Fill the array with random numbers from 0 to 50
    for(int i = 0; i < SIZE; i++) {
        array[i] = rand() % 51;
    }

    // Insertion sort
    for (int i = 0; i < SIZE - 1; i++) { // Last sorted element index
        int inserted = array[i + 1];      // Element to be inserted
        int j = i;

        while (j >= 0 && array[j] > inserted) { // While place is not found
            array[j + 1] = array[j];           // Shift the elements to the right
            j--;
        }
        array[j + 1] = inserted; // Place the inserted element in its position
    }

    // Print the final sorted array
    for (int i = 0; i < SIZE; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");
    return 0;
}