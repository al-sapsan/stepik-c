#include <stdio.h>
#define SIZE 6

int main(void) {

    int array[SIZE];
    // Read array elements from user input
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &array[i]);
    }
    // Print the array elements
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    // The sum of the array elements
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += array[i];
    }
    printf("\nSum: %d\n", sum);
    // The average of the array elements
    double average = (double)sum / SIZE;
    printf("Average: %.2f\n", average);
    // Iterating over elements with even (odd) indexes
    printf("Elements at even indexes: ");
    for (int i = 0; i < SIZE; i += 2) {
        printf("%d ", array[i]);
    }
    printf("\nElements at odd indexes: ");
    for (int i = 1; i < SIZE; i += 2) {
        printf("%d ", array[i]);
    }
    printf("\n");
    // Finding the maximum and minimum elements values
    printf("Finding max and min values:\n");
    int max = array[0];
    int min = array[0];
    for (int i = 1; i < SIZE; i++) {
        if (array[i] > max) {
            max = array[i];
        }
        if (array[i] < min) {
            min = array[i];
        }
    }
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    // Finding the index of the maximum and minimum elements
    int max_index = 0;
    int min_index = 0;
    for (int i = 1; i < SIZE; i++) {
        if (array[i] > max) {
            max = array[i];
            max_index = i;
        }
        if (array[i] < min) {
            min = array[i];
            min_index = i;
        }
    }
    printf("Index of max: %d\n", max_index);
    printf("Index of min: %d\n", min_index);
}
