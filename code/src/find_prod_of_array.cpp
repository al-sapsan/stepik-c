#include <stdio.h>
#include <stdlib.h>

#define SIZE 7
#define MAX_VALUE 10
#define MIN_VALUE -10
#define RANGE (MAX_VALUE - MIN_VALUE + 1)

/**
 * @brief Initializes an array with random values in specified range
 * @param arr Pointer to the array to be initialized
 * @param n Size of the array
 */
void init(int *arr, int n);

/**
 * @brief Prints the elements of an array
 * @param arr Pointer to the array to be printed
 * @param n Size of the array
 */
void print(const int *arr, int n);

/**
 * @brief Calculates the product of positive elements in the array
 * @param arr Pointer to the array
 * @param n Size of the array
 * @return Product of positive elements (1 if none, 0 if all are non-positive)
 */
int prodPositive(const int *arr, int n);

int main()
{
    int seed;
    scanf("%d", &seed);
    srand(seed);
    int arr[SIZE];

    init(arr, SIZE);
    print(arr, SIZE);
    printf("%d\n", prodPositive(arr, SIZE));

    return 0;
}

void init(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % RANGE + MIN_VALUE;
    }
}

void print(const int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int prodPositive(const int *arr, int n)
{
    int prod = 1;
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            prod *= arr[i];
            found = 1;
        }
    }
    return found ? prod : 0;
}
