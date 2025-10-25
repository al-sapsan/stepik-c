#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define MAX_VALUE 10
#define MIN_VALUE -5
#define RANGE (MAX_VALUE - MIN_VALUE + 1)

/**
 * @brief Initializes an array with random integers in the range [MIN_VALUE, MAX_VALUE].
 * 
 * @param arr Pointer to the array to initialize
 * @param n Number of elements in the array
 */
void init_array(int *arr, int n);

/**
 * @brief Prints the elements of the array separated by spaces, followed by a newline.
 * 
 * @param arr Pointer to the array to print
 * @param n Number of elements in the array
 */
void print_array(int *arr, int n);

/**
 * @brief Calculates the sum of the elements in the array.
 * 
 * @param arr Pointer to the array
 * @param n Number of elements in the array
 * @return int The sum of the array elements
 */
int sum_array(int *arr, int n);

int main()
{
    int arr[SIZE];
    int seed;
    scanf("%d", &seed);
    srand(seed);

    init_array(arr, SIZE);
    print_array(arr, SIZE);
    printf("%d\n", sum_array(arr, SIZE));
    return 0;
}

void init_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % RANGE + MIN_VALUE;
    }
}

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sum_array(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}