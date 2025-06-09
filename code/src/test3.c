#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

/**
 * @brief Fills an array with random numbers from 0 to 50, prints it, prints the average (2 decimals), and prints elements less than the average.
 *
 * The user enters the seed for the random number generator.
 * The program prints the array (with a space after each element, including the last),
 * then prints the average (rounded to two decimals),
 * then prints all elements less than the average (separated by spaces, with a space after the last).
 *
 * @return 0 on successful completion
 */
int main() {
    int irand;
    int array[SIZE];
    double sum = 0, avg;

    if (scanf("%d", &irand) != 1) {
        printf("Error reading input.\n");
        return 0;
    }

    srand(irand);

    // Fill and print array, calculate sum
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 51; // from 0 to 50 inclusive
        printf("%d ", array[i]);
        sum += array[i];
    }
    printf("\n");

    avg = sum / SIZE;
    printf("%.2f\n", avg);

    // Print elements less than average
    for (int i = 0; i < SIZE; i++) {
        if (array[i] < avg)
            printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}