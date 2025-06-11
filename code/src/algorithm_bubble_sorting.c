#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main() {

    int array[SIZE];
    int key;

    // Read the key for random number generation
    if(scanf("%d", &key) != 1) {
        puts("Error reading input\n");
        return 0;
    }
    srand(key);

    // Fill the array with random numbers from 1 to 20
    for(int i = 0; i < SIZE; i++) {
        array[i] = rand() % 51;
    }

    // Bubble sort
    int right_side;// The right side of the array that is already sorted
    for(right_side = SIZE - 1; right_side > 0; right_side--) {
        for(int i = 0; i < right_side; i++) {
            if(array[i] > array[i + 1]) {
                // Swap the elements
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }

    return 0;
}