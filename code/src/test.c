#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

/**
 * @brief Fills an array with random numbers from -3 to 3, prints it, counts zeros, and sums elements between first and last zero.
 *
 * The user enters the seed for the random number generator.
 * The program prints the array (elements separated by spaces, including after the last element),
 * prints the number of zeros,
 * and prints the sum of elements between the first and last zero (exclusive).
 * If there are no zeros, prints ERROR. If only one zero, prints 0.
 *
 * @return 0 on successful completion
 */
int main() {
    int array[SIZE];
    int key_random;

    // Read the key for random number generation
    if (scanf("%d", &key_random) != 1) {
        puts("Error reading input");
        return 0;
    }
    srand(key_random);

    // Fill the array with random numbers from -3 to 3 and print it
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 7 - 3;
        printf("%d ", array[i]);
    }
    printf("\n");

    // Count the number of zeros in the array
    int zero_count = 0;
    int first_zero_index = -1, last_zero_index = -1;
    for (int i = 0; i < SIZE; i++) {
        if (array[i] == 0) {
            zero_count++;
            if (first_zero_index == -1)
                first_zero_index = i;
            last_zero_index = i;
        }
    }
    printf("%d\n", zero_count);

    if (zero_count == 0) {
        printf("ERROR\n");
        return 0;
    }

    // If only one zero or zeros are adjacent, sum is 0
    if (first_zero_index == last_zero_index || last_zero_index - first_zero_index == 1) {
        printf("0\n");
        return 0;
    }

    // Calculate the sum of elements between the first and last zero
    int sum = 0;
    for (int i = first_zero_index + 1; i < last_zero_index; i++) {
        sum += array[i];
    }
    printf("%d\n", sum);

    return 0;
}