#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 4

int main() {

    int array2D[ROWS][COLS];
    int k;
    srand(k);

    // Initialize and print the 2D array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            array2D[i][j] = rand() % 100; // Random values between 0 and 99
            printf("%d ", array2D[i][j]);
        }
        printf("\n");
    }
    
    // Calculate the sum of all elements in the 2D array
    int sum = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum += array2D[i][j];
        }
    }
    printf("Sum of all elements: %d\n", sum); // Print only out of the loop

    // Find maximum and minimum values in every column
    for (int j = 0; j < COLS; j++) {
        int max = array2D[0][j];
        int min = array2D[0][j];
        for (int i = 1; i < ROWS; i++) { // the row loop (starts from 1)
            if (array2D[i][j] > max) {
                max = array2D[i][j];
            }
            if (array2D[i][j] < min) {
                min = array2D[i][j];
            }
        }
        printf("Column %d: Max = %d, Min = %d\n", j, max, min);
    }
    
    // Find the maximum value in the entire 2D array
    int maxValue = array2D[0][0];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (array2D[i][j] > maxValue) {
                maxValue = array2D[i][j];
            }
        }
    }
    printf("Maximum value in the array: %d\n", maxValue);

    // Find sum of the elements under the main diagonal (row number = column number i = j)
    // Note: It works only with a square matrix. 
    int diagonalSum = 0;
    for (int i = 1; i < ROWS; i++) { // Start from row 1 to avoid the first row
        for (int j = 0; j <= i; j++) { // Ensure we don't go out of bounds
            diagonalSum += array2D[i][j];
        }
    }
    printf("Sum of elements under the main diagonal: %d\n", diagonalSum);

    // Find the sum of the elements above the main diagonal (row number < column number i < j)
    int aboveDiagonalSum = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = i + 1; j < COLS; j++) { // Start from the next column
            aboveDiagonalSum += array2D[i][j];
        }
    }
    printf("Sum of elements above the main diagonal: %d\n", aboveDiagonalSum);

    // Find the sum of the elements below the reverse diagonal (row number + column number = ROWS - 1)
    int belowReverseDiagonalSum = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i + j > ROWS - 1) { // Check if the sum of indices is greater than ROWS - 1
                belowReverseDiagonalSum += array2D[i][j];
            }
        }
    }
    printf("Sum of elements below the reverse diagonal: %d\n", belowReverseDiagonalSum);
    return 0;   

}