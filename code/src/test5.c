#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5 
#define COLS 6

int main() {
  
    int array2D[ROWS][COLS];       ///< 2D array to store values
    int seed;                      ///< Seed for random number generator
    int *start_ptr = &array2D[0][0]; ///< Pointer to start of array
    int *end_ptr = &array2D[0][0] + (ROWS * COLS); ///< Pointer to end of array

    // Get random seed from user
    scanf("%d", &seed);
    srand(seed);
    
    /* Fill array with random values 0-10 */
    for (; start_ptr < end_ptr; start_ptr++) {
        *start_ptr = rand() % MAX_VAL;
    }

    /* Print array in tabular format */
    start_ptr = &array2D[0][0]; // Reset pointer to start
    for (int i = 0; start_ptr < end_ptr; start_ptr++, i++) {
        printf("%d\t", *start_ptr);
        // Move to new line after each row
        if ((i + 1) % COLS == 0) {
            printf("\n");
        }
    }
    
  return 0;
}