#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main() {
    int array[SIZE];
    int generator_value;

    // Read the key for random number generation
    if (scanf("%d", &generator_value) != 1) {
        puts("Error reading input");
        return 0;
    }
    srand(generator_value);

    // Generate random numbers and fill the array
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 16; // 0 to 15 inclusive
        printf("%d ", array[i]);
    }
    printf("\n");

    // Find the last maximum element and its index
    int max_element = array[0];
    int max_element_index = 0;
    for (int i = 1; i < SIZE; i++) {
        if (array[i] >= max_element) {
            max_element = array[i];
            max_element_index = i;
        }
    }

    // If the last max is at index 0, print ERROR
    if (max_element_index == 0) {
        printf("ERROR\n");
        return 0;
    }

    // Find the average of the array from first element to the element before last max
    int sum = 0;
    for (int i = 0; i < max_element_index; i++) {
        sum += array[i];
    }
    double average = (double)sum / max_element_index;
    // Output the results
    printf("%.1f\n", average);
    return 0;
}