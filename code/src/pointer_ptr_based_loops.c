/**
 * @brief Program to generate random array and calculate statistics
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 12 
#define MIN_VALUE -45 
#define MAX_VALUE 45  
#define RANGE (MAX_VALUE - MIN_VALUE + 1)

int main() {
    int array[SIZE];  
    int seed;       
    int positive = 0;         ///< Count of positive numbers
    int negative = 0;         ///< Count of negative numbers
    
    // Pointer to traverse array
    int *ptr = array;           ///< Pointer to array start
    int *end_ptr = array + SIZE; ///< Pointer to array end (one past last element)
    
    // Get random seed from user
    scanf("%d", &seed);
    srand(seed);
    
    /* Fill array with random numbers using pointers */
    for (; ptr < end_ptr; ptr++) {
        *ptr = rand() % RANGE + MIN_VALUE;
    }
    
    /* Print array using pointers */
    ptr = array; // Reset pointer to start
    for (; ptr < end_ptr; ptr++) {
        printf("%d ", *ptr);
    }
    printf("\n");
    
    /* Count positive/negative numbers using pointers */
    ptr = array; // Reset pointer to start
    for (; ptr < end_ptr; ptr++) {
        if (*ptr > 0) {
            positive++;
        } else if (*ptr < 0) {
            negative++;
        }
    }
    
    // Calculate percentages
    double pos_percent = (double)positive / SIZE * 100;  ///< Percentage of positive numbers
    double neg_percent = (double)negative / SIZE * 100;  ///< Percentage of negative numbers
    
    // Print statistics
    printf("%.1f%% %.1f%%\n", pos_percent, neg_percent);
    
    return 0;
}