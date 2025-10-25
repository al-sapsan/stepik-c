#include <stdio.h>

/**
 * @brief Calculates the power of an integer (x^y)
 * @param base The integer base number
 * @param exponent The positive integer exponent (must be > 0)
 * @return The result of base raised to the exponent
 */
int power(int base, int exponent) {
    int result = 1;
    // Multiply base 'exponent' times
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int main() {
    // Print cubes of numbers from 2 to 10
    printf("Cubes from 2 to 10:\n");
    for (int num = 2; num <= 10; num++) {
        printf("%d ", power(num, 3));
    }
    printf("\n");
    
    return 0;
}