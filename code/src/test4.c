#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

/**
 * @brief Fills an array with random numbers from -5 to 15, prints it, and prints the sum of min and max elements.
 *
 * The user enters the seed for the random number generator.
 * The program prints the array (with a space after each element, including the last),
 * then prints the sum of the minimum and maximum elements on the next line.
 *
 * @return 0 on successful completion
 */
int main() {
    int irand;
    int array[SIZE];
    int min, max;

    if (scanf("%d", &irand) != 1) {
        printf("Error reading input.\n");
        return 0;
    }

    srand(irand);

    // Fill and print array, find min and max
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 21 - 5; // from -5 to 15 inclusive
        printf("%d ", array[i]);
        if (i == 0) {
            min = max = array[i];
        } else {
            if (array[i] < min) min = array[i];
            if (array[i] > max) max = array[i];
        }
    }
    printf("\n");
    printf("%d\n", min + max);

    return 0;
}