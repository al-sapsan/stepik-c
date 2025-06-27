#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

/**
 * @brief Initializes an array with random values in specified range
 * @param arr Pointer to the array to be initialized
 * @param n Size of the array
 */
void initArray(int *arr, int n);

/**
 * @brief Prints the elements of an array
 * @param arr Pointer to the array to be printed
 * @param n Size of the array
 */
void printArray(int *arr, int n);

void sortArray(int *arr, int n);

int main()
{
    int seed;
    scanf("%d", &seed);
    srand(seed);
    int arr[SIZE];

    initArray(arr, SIZE);
    printArray(arr, SIZE);
    sortArray(arr, SIZE);
    printArray(arr, SIZE);

    return 0;
}

void initArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 21;
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void sortArray(int *arr, int n)
{
    int min_index;
    for (int i = 0; i < SIZE - 1; ++i)
    {
        min_index = i;
        for (int j = i + 1; j < SIZE; ++j)
        {
            if (*(a + j) < *(a + min_index))
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            int temp = *(a + i);
            *(a + i) = *(a + min_index);
            *(a + min_index) = temp;
        }
    }
}