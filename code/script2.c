#include <iostream>
#include <cstdlib>
using namespace std;
#define N 4
#define M 5

/**
 * @brief Initializes a 2D array with random integers in [-3, 9].
 * @param mas 2D array to initialize
 * @param n Number of rows
 */
void initArray(int mas[][M], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < M; j++)
        {
            mas[i][j] = rand() % 13 - 3; // -3 to 9 inclusive
        }
    }
}

/**
 * @brief Prints a 2D array as a table, elements separated by tabs.
 * @param mas 2D array to print
 * @param n Number of rows
 */
void printArray(int mas[][M], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << mas[i][j] << '\t';
        }
        cout << endl;
    }
}

/**
 * @brief Returns the minimum element in a 1D array.
 * @param m Array
 * @param n Number of elements
 * @return Minimum value
 */
int minArray(int m[], int n)
{
    int min = m[0];
    for (int i = 1; i < n; i++)
    {
        if (m[i] < min)
            min = m[i];
    }
    return min;
}

int main()
{
    int n;
    cin >> n;
    srand(n);
    int a[N][M];
    initArray(a, N);
    printArray(a, N);

    // Print minimum in each row
    for (int i = 0; i < N; i++)
    {
        cout << minArray(a[i], M) << " ";
    }
    cout << endl;

    // Find minimum in the whole 2D array (as 1D)
    cout << minArray(&a[0][0], N * M) << endl;

    return 0;
}