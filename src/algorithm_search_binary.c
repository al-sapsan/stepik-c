#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main() {

    int array[SIZE];
    int key_random, key_element;

    // Read the key for random number generation
    if(scanf("%d", &key_random) != 1) {
        puts("Error reading input\n");
        return 0;
    }
    srand(key_random); // Seed the random number generator

    // Fill the array with random numbers from 1 to 20
    for(int i = 0; i < SIZE; i++) {
        array[i] = rand() % 21;
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Sort the array using bubble sort
    for(int i = 0; i < SIZE - 1; i++) {
        for(int j = 0; j < SIZE - i - 1; j++) {
            if(array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    // Print the sorted array
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    // Read the key to search for
    printf("Enter the key to search for: ");
    if(scanf("%d", &key_element) != 1) {
        puts("Error reading input\n");
        return 0;
    }
    // Perform binary search
    int left = 0, right = SIZE - 1;
    int found = -1; // The index that is not in the array
    do {
        int middle = (left + right) / 2;
        if(array[middle] == key_element) {
            found = middle; // Key found
            printf("Key %d found at index %d\n", key_element, middle);
            break;
        } else if(array[middle] < key_element) {
            left = middle + 1; // Search in the right half
        } else {
            right = middle - 1; // Search in the left half
        } 
    } while(left <= right);
    /*
    / Perform binary search
    int left = 0, right = SIZE - 1;
    int found = -1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (array[middle] == key_element) {
            found = middle;
            break;
        } else if (array[middle] < key_element) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    */
    if(found == -1) {
        printf("Key %d not found in the array\n", key_element);
    } else {
        printf("Key %d found at index %d\n", key_element, found);
    } 
    
    return 0;
}