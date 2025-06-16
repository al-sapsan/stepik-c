#include <stdio.h>

#define SIZE 10

int main() {
    int array[SIZE];
    int target;
    int* ptr = array;

    // Input array elements
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", ptr + i);
    }

    // Input the number to search for
    scanf("%d", &target);

    // Binary search 
    int* left = array;
    int* right = array + SIZE - 1;
    int* result = NULL;

    while (left <= right) {
        int* mid = left + (right - left) / 2;

        if (*mid == target) {
            result = mid;
            break;
        } else if (*mid < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Output result
    if (result != NULL) {
        while (result < array + SIZE) {
            printf("%d ", *result);
            result++;
        }
        printf("\n");
    } else {
        printf("ERROR\n");
    }

    return 0;
}
