#include <stdio.h>

int main() {
    int array[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Calculate the size of the array
    int all_bytes = sizeof(array);
    int row_bytes = sizeof(array[0]);
    int element_bytes = sizeof(array[0][0]);
    int total_elements = all_bytes / element_bytes;
    int rows = sizeof(array) / sizeof(array[0]);
    int cols = sizeof(array[0]) / sizeof(array[0][0]);

    printf("Total bytes: %d\n", all_bytes);
    printf("Bytes per row: %d\n", row_bytes);
    printf("Bytes per element: %d\n", element_bytes);
    printf("Total elements: %d\n", total_elements);
    printf("Number of rows: %d\n", rows);
    printf("Number of columns: %d\n", cols);

    return 0;
}