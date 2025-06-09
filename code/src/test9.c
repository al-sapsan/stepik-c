#include <stdio.h>
#define SIZE 6

/**
 * @brief Counts zeros and sums elements at odd indices in an array.
 *
 * The user enters SIZE integers. The program counts how many zeros are in the array
 * and calculates the sum of elements at odd indices (1, 3, 5...).
 *
 * @return 0 on successful completion
 */
int main(void) {
    int array[SIZE];
    int zero_counter = 0;
    int sum = 0;

    // Read array elements from user input
    for(int i = 0; i < SIZE; i++) {
        scanf("%d", &array[i]);
    }

    // Count zeros in the array
    for(int i = 0; i < SIZE; i++) {
        if (array[i] == 0) {
            zero_counter++;
        }
    }

    // Sum elements at odd indices
    for(int i = 1; i < SIZE; i += 2) {
        sum += array[i];
    }

    printf("%d %d\n", zero_counter, sum);
    return 0;
}