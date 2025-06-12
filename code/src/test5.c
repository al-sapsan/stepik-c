#include <stdio.h>
#define SIZE 10

int main() {
    int array[SIZE];
    // Input array
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &array[i]);
    }
    int sum = 0;
    // Find the first positive element and sum all positive elements
    int i = 0;
    while (i < SIZE && array[i] <= 0) {
        i++;
    }
    for (; i < SIZE; i++) {
        sum += array[i];
    }
    printf("%d\n", sum);
    return 0;
}
