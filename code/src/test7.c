#include <stdio.h>
#define TEN 10
#define SEVEN 7

int main() {

    int first_array[TEN];
    int second_array[SEVEN];
    int result_array[SEVEN] = {0};
    int res_count = 0;

    // Initialise first array from input
    for (int i = 0; i < TEN; i++) {
        scanf("%d", &first_array[i]);
    }
    // Initialise second array from input
    for (int i = 0; i < SEVEN; i++) {
        scanf("%d", &second_array[i]);
    }

    // Find unique common elements
    for (int i = 0; i < SEVEN; i++) {
        int second_value = second_array[i];
        int found_in_first = 0;
        int already_in_result = 0;
        // Check if in first_array
        for (int j = 0; j < TEN; j++) {
            if (first_array[j] == second_value) {
                found_in_first = 1;
                break;
            }
        }
        // Check if already in result_array
        for (int k = 0; k < res_count; k++) {
            if (result_array[k] == second_value) {
                already_in_result = 1;
                break;
            }
        }
        // Add to result_array if is in first_array and not already in result_array
        if (found_in_first && !already_in_result) {
            result_array[res_count++] = second_value;
        }
    }

    // Sort result_array (simple bubble sort)
    for (int i = 0; i < SEVEN - 1; i++) {
        for (int j = 0; j < SEVEN - 1 - i; j++) {
            if (result_array[j] > result_array[j + 1]) {
                int tmp = result_array[j];
                result_array[j] = result_array[j + 1];
                result_array[j + 1] = tmp;
            }
        }
    }

    // Print result_array
    for (int i = 0; i < SEVEN; i++) {
        printf("%d ", result_array[i]);
    }
    printf("\n");

    return 0;
}