#include <stdio.h>
#include <stdlib.h>

#define SIZE 6
#define MAX_VALUE 9
#define MIN_VALUE -9
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

void find_neg(arr, SIZE);

void find_pos(arr, SIZE);

void swap(int *a, int *b);

int main()
{
    int seed;
    scanf("%d", &seed);
    srand(seed);
    int arr[SIZE];
    
    init_array(arr, SIZE);
    print_array(arr, SIZE);
    int *first_negative = find_neg(arr, SIZE);
    int *last_positive = find_pos(arr, SIZE);
    if (first_negative == NULL || last_positive == NULL)
    {
        puts("Error");
        return 0;
    }
    swap (first_negative, last_positive);
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

int find_neg (int *arr, int n)
{
    int *neg_ptr = NULL;
    for (int i = 0; i < n; i++)
    {
        if (i < 0)
        {
            neg_ptr = &arr[i];
            break;
        }
    }
    return neg_ptr;
}