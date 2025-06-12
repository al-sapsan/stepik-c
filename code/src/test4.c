#include <stdio.h>
#define SIZE 7

int main() {
    int array[SIZE];
    // Input array
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &array[i]);
    }

    // Find the first maximum among elements at odd positions (user: 1,3,5,7; code: i=0,2,4,6)
    int max_index = 0;
    for (int i = 2; i < SIZE; i += 2) {
        if (array[i] > array[max_index]) {
            max_index = i;
        }
    }

    // Replace this element with zero
    array[max_index] = 0;

    // Print the modified array
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
