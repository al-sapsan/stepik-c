#include <stdio.h>
#define SIZE 10 ///< Constant for array size

/**
 * @brief Calculates the average of SIZE integers and counts how many elements are less than the average.
 *
 * The user enters SIZE integers. The program prints the average (with one decimal place)
 * and the count of elements less than the average.
 *
 * @return 0 on successful completion
 */
int main(void) {
    int array[SIZE];
    int count = 0;
    double sum = 0, avg;

    // Read SIZE integers from user input
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &array[i]);
        sum += array[i];
    }

    avg = sum / SIZE;

    // Count elements less than the average
    for (int i = 0; i < SIZE; i++) {
        if (array[i] < avg)
            count++;
    }

    printf("%.1f %d\n", avg, count);
    return 0;
}