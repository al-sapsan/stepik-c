#include <iostream>
using namespace std;
#define SIZE 5

/**
 * @brief Reads n elements into array a from standard input.
 * @param a Array to fill.
 * @param n Number of elements.
 */
void readArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

/**
 * @brief Calculates the sum of digits of an integer.
 * @param n Integer number.
 * @return Sum of digits.
 */
int digitSum(int n)
{
    n = abs(n);
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

/**
 * @brief Finds the index of the element with the maximum sum of digits.
 * @param a Array to search.
 * @param n Number of elements.
 * @return Index of the element with the maximum digit sum.
 */
int findMaxSumOfDigits(const int a[], int n)
{
    int maxSum = digitSum(a[0]);
    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        int currSum = digitSum(a[i]);
        if (currSum > maxSum)
        {
            maxSum = currSum;
            idx = i;
        }
    }
    return idx;
}

int main()
{
    int array[SIZE];
    readArray(array, SIZE);
    int idx = findMaxSumOfDigits(array, SIZE);
    cout << idx << "\n";
    return 0;
}
