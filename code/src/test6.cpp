#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int ROWS = 4;
const int COLS = 6;

/**
 * @brief Initializes a 2D array with random integers from 1 to 25.
 * @param arr 2D array to fill.
 * @param rows Number of rows.
 * @param cols Number of columns.
 */
void initMas(int arr[ROWS][COLS], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            arr[i][j] = rand() % 25 + 1;
}

/**
 * @brief Prints a 2D array as a table, elements separated by tabs.
 * @param arr 2D array to print.
 * @param rows Number of rows.
 * @param cols Number of columns.
 */
void printMas(const int arr[ROWS][COLS], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
            cout << arr[i][j] << "\t";
        cout << "\n";
    }
}

/**
 * @brief Performs a cyclic right shift by one position on a 1D array.
 * @param a Array to shift.
 * @param n Number of elements.
 */
void sdvig(int a[], int n)
{
    int last = a[n - 1];
    for (int i = n - 1; i > 0; --i)
        a[i] = a[i - 1];
    a[0] = last;
}

/**
 * @brief For each row in a 2D array, performs a cyclic right shift by k positions.
 * @param arr 2D array to transform.
 * @param rows Number of rows.
 * @param cols Number of columns.
 * @param k Number of shifts.
 */
void transform(int arr[ROWS][COLS], int rows, int cols, int k)
{
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < k; ++j)
            sdvig(arr[i], cols);
}

int main()
{
    int seed, k;
    cin >> seed >> k;
    srand(seed);
    int arr[ROWS][COLS];

    initMas(arr, ROWS, COLS);
    cout << "Исходный массив:\n";
    printMas(arr, ROWS, COLS);

    transform(arr, ROWS, COLS, k);
    cout << "Преобразованный массив:\n";
    printMas(arr, ROWS, COLS);

    return 0;
}