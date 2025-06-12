#include <stdio.h>

#define SIZE 6

int main() {
    int array[SIZE];
    int user_input, sum = 0, count = 0;

    // Input array
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &array[i]);
    }

    // Input number
    scanf("%d", &user_input);

    // Calculate sum and count of elements less than user_input
    for (int i = 0; i < SIZE; i++) {
        if (array[i] < user_input) {
            sum += array[i];
            count++;
        }
    }
    printf("%d %d\n", sum, count);

    // Replace elements at even positions (1,3,5 for user, i=0,2,4) with user_input
    for (int i = 0; i < SIZE; i++) {
        if (i % 2 == 0) {
            array[i] = user_input;
        }
    }

    // Print modified array
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}