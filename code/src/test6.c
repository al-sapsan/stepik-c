#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main() {
    int array[SIZE];
    int user_input;

    // Input number
    scanf("%d", &user_input);

    srand(user_input);
    // Fill array with random numbers and print
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 6; // 0 to 5
        printf("%d ", array[i]);
    }
    printf("\n");

    // Compact the array: move non-zeros to the front, zeros to the end
    int pos = 0;
    for (int i = 0; i < SIZE; i++) {
        if (array[i] != 0) {
            array[pos++] = array[i];
        }
    }
    // Fill the rest with zeros
    for (int i = pos; i < SIZE; i++) {
        array[i] = 0;
    }

    // Print the compacted array
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}