#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 4;
const int COLS = 5;

/**
 * @brief Reads a 2D array of doubles from standard input.
 * @param arr 2D array to fill.
 * @param rows Number of rows.
 * @param cols Number of columns.
 */
void readArray(double arr[ROWS][COLS], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> arr[i][j];
}

/**
 * @brief Prints a 2D array of doubles as a table with two decimal places.
 * @param arr 2D array to print.
 * @param rows Number of rows.
 * @param cols Number of columns.
 */
void printArray(const double arr[ROWS][COLS], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
            cout << fixed << setprecision(2) << arr[i][j] << "\t";
        cout << "\n";
    }
}

/**
 * @brief Changes the sign of all elements in the specified column (user index, 1-based).
 * @param arr 2D array to modify.
 * @param rows Number of rows.
 * @param cols Number of columns.
 * @param user_col User column number (1-based).
 */
void changeColumnSign(double arr[ROWS][COLS], int rows, int cols, int user_col)
{
    int col = user_col - 1;
    if (col < 0 || col >= cols)
        return;
    for (int i = 0; i < rows; ++i)
        arr[i][col] = -arr[i][col];
}

int main()
{
    double arr[ROWS][COLS];
    readArray(arr, ROWS, COLS);
    int user_col;
    cin >> user_col;
    changeColumnSign(arr, ROWS, COLS, user_col);
    printArray(arr, ROWS, COLS);
}