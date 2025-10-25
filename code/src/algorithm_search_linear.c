#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main() {

    int array[SIZE];
    int key;

    // Read the key for random number generation
    if(scanf("%d", &key) != 1) {
        puts("Error reading input\n");
        return 0;
    }
    srand(key);

    // Fill the array with random numbers from 1 to 20
    for(int i = 0; i < SIZE; i++) {
        array[i] = rand() % 21;
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Linear search
    int element;
    printf("Enter the element to search for: ");
    if(scanf("%d", &element) != 1) {
        puts("Error reading input\n");
        return 0;
    }
    int found = -1; // Initialize found to -1 (or any idex not belong to the array)
    // Perform linear search
    for(int i = 0; i < SIZE; i++) {
        if(array[i] == element) {
            found = i;
            break;
        }
    }
    // Output the result of the search
    if(found != -1) {
        printf("Element %d found at index %d\n", element, found);
    } else {
        printf("Element %d not found in the array\n", element);
    }
    return 0;
}