#include <stdio.h>
#include <stdlib.h>

#define SIZE 6
#define MAX_VALUE 9
#define MIN_VALUE -9
#define RANGE (MAX_VALUE - MIN_VALUE + 1)

/**
 * @brief Initializes an array with random values in specified range
 * @param arr Pointer to the array to be initialized
 * @param n Size of the array
 */
void init_array(int *arr, int n);

/**
 * @brief Prints the elements of an array
 * @param arr Pointer to the array to be printed
 * @param n Size of the array
 */
void print_array(int *arr, int n);

/**
 * @brief Finds the first negative element in an array
 * @param arr Pointer to the array to search
 * @param n Size of the array
 * @return Pointer to the first negative element, or NULL if none found
 */
int *find_neg(int *arr, int n);

/**
 * @brief Finds the last positive element in an array
 * @param arr Pointer to the array to search
 * @param n Size of the array
 * @return Pointer to the last positive element, or NULL if none found
 */
int *find_pos(int *arr, int n);

/**
 * @brief Swaps the values of two integers
 * @param a Pointer to the first integer
 * @param b Pointer to the second integer
 */
void swap(int *a, int *b);

int main()
{
    int seed;
    scanf("%d", &seed);
    srand(seed);
    int arr[SIZE];

    init_array(arr, SIZE);
    print_array(arr, SIZE);

    int *first_neg = find_neg(arr, SIZE);
    int *last_pos = find_pos(arr, SIZE);

    if (first_neg == NULL || last_pos == NULL)
    {
        puts("ERROR");
        return 0;
    }

    swap(first_neg, last_pos);
    print_array(arr, SIZE);

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

int *find_neg(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            return &arr[i];
        }
    }
    return NULL;
}

int *find_pos(int *arr, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > 0)
        {
            return &arr[i];
        }
    }
    return NULL;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}