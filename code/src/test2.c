#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 3

int main () {

    int array2D[ROWS][COLS];
    int seed;
    int *start_ptr = &array2D[0][0];
    int *end_ptr = &array2D[0][0] + (ROWS * COLS);

    scanf("%d", &seed);
    srand(seed);

    for (; start_ptr < end_ptr; start_ptr++) {
        *start_ptr = rand() % 11;
    }
    start_ptr = array2D[0];
    for (; start_ptr < end_ptr; start_ptr++) {
        printf("%d\t", *start_ptr);
    }
    printf("\n");

    int zero_counter = 0;
    for (; start_ptr < end_ptr; start_ptr++) { 
        if (*start_ptr == 0) {
            zero_counter++;
            break;
        }
    }
    printf("%d\n", zero_counter);
    return 0;

}