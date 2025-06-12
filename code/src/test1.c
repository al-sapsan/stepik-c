#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

/**
 * @brief Fills an array with random numbers from -10 to 10, prints it, finds the index of a user-input value,
 * swaps it with the first element if found, and prints the modified array.
 *
 * @return 0 on successful completion
 */
int main() {
    int array[SIZE];
    int generator_value;

    // Read the key for random number generation
    if (scanf("%d", &generator_value) != 1) {
        puts("Error reading input");
        return 0;
    }
    srand(generator_value);

    // Generate random numbers in the range [-10, 10] and print the array
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 21 - 10;
        printf("%d ", array[i]);
    }
    printf("\n");

    int user_input;
    // Read the user input
    if (scanf("%d", &user_input) != 1) {
        puts("Error reading input");
        return 0;
    }

    // Find the index of the first occurrence
    int found = -1;
    for (int i = 0; i < SIZE; i++) {
        if (array[i] == user_input) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("NO\n");
    } else {
        printf("%d\n", found);
        // Swap with the first element
        int temp = array[0];
        array[0] = array[found];
        array[found] = temp;
    }

    // Print the (possibly modified) array
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}