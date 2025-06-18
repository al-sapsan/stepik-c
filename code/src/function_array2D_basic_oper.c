#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

/**
 * @brief Initializes a 2D array with random integers in [0, 10].
 * @param arr Pointer to the first element of the array
 * @param r Number of rows
 * @param c Number of columns (must be 4)
 */
void init_array(int *arr, int r, int c);

/**
 * @brief Prints a 2D array as a table, elements separated by tabs.
 * @param arr Pointer to the first element of the array
 * @param r Number of rows
 * @param c Number of columns (must be 4)
 */
void print_array(int *arr, int r, int c);

/**
 * @brief Returns the sum of the maximum elements in each column.
 * @param arr Pointer to the first element of the array
 * @param r Number of rows
 * @param c Number of columns (must be 4)
 * @return int Sum of column maximums
 */
int sum_of_max(int *arr, int r, int c);

int main()
{
    int seed;
    scanf("%d", &seed);
    srand(seed);

    int array2D[ROWS][COLS];
    init_array(&array2D[0][0], ROWS, COLS);
    print_array(&array2D[0][0], ROWS, COLS);
    printf("%d\n", sum_of_max(&array2D[0][0], ROWS, COLS));
    return 0;
}

void init_array(int *arr, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            arr[i * c + j] = rand() % 11; // 0 to 10 inclusive
        }
    }
}

void print_array(int *arr, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d\t", arr[i * c + j]);
        }
        printf("\n");
    }
}

int sum_of_max(int *arr, int r, int c)
{
    int sum = 0;
    for (int j = 0; j < c; j++)
    {
        int max = arr[j];
        for (int i = 1; i < r; i++)
        {
            if (arr[i * c + j] > max)
                max = arr[i * c + j];
        }
        sum += max;
    }
    return sum;
}