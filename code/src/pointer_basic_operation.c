#include <stdio.h>

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
int main() {
    void *ptr;  // Generic pointer (can point to any data type)
    
    // Case 1: Point to an integer
    int i = 3;
    ptr = &i;  // Store address of 'i'
    printf("Integer value: %d\n", *(int*)ptr);  // Dereference as int*
    
    // Case 2: Point to a double
    double x = 3.5;
    ptr = &x;  // Now ptr points to 'x'
    printf("Double value: %f\n", *(double*)ptr);  // Dereference as double*
    
    return 0;
}