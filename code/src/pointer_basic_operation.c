#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 12 
#define MIN -45 
#define MAX 45  
#define RANGE (MAX_VAL - MIN_VAL + 1)

int main() {
// Initialize variables and pointers
int *xptr, *yptr;
int x, y;
xptr = &x;
yptr = &y;

// Initialize with NULL
xptr = NULL;

// Initialise with another pointer
xptr = yptr;

// The pointer can be increased and decreased on an integer
// via the size of pointer
xptr++; // increase on 4 bytes
xptr += 5; // increase on 20 bytes (4 * 5)

// The pointer can be compared
if (xptr > yptr) {
    puts("Bigger");
}
if (xptr != NULL) {
    puts("Not equal");
}

// In oder to use void ptr we must do explicit type conversion

    void *ptr;  // Generic pointer (can point to any data type)
    
    // Case 1: Point to an integer
    int i = 3;
    ptr = &i;  // Store address of 'i'
    printf("Integer value: %d\n", *(int*)ptr);  // Dereference as int*
    
    // Case 2: Point to a double
    double x = 3.5;
    ptr = &x;  // Now ptr points to 'x'
    printf("Double value: %f\n", *(double*)ptr);  // Dereference as double*

    // Print the array using while loop (while-based loop)
    int i = 0;
    while (i < N) {
        printf("%d\t", *ptr);
        ptr++;
        i++;
    }
    printf("\n");

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
        *ptr = rand() % RANGE + MIN; // full formula (MAX - MIN + 1) + MIN;
    }
    
    // Print the array values (index-based loop)
    ptr = array; ///< Reset pointer to the beginning of the array
    for (int i = 0; i < N; i++, ptr++) {
        printf("%d\t", *ptr);
    }
    printf("\n");

    // Print the array using while loop (while-based loop)
    ptr = array;
    while (ptr < end_ptr) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");

    /* Print array using pointers (pointer-based loop)*/
    ptr = array; // Reset pointer to start
    for (; ptr < end_ptr; ptr++) {
        printf("%d ", *ptr);
    }
    printf("\n");
    
    return 0;
}