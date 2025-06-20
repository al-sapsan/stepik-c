#include <iostream>
using namespace std;

/**
 * @brief Calculates the sum of the digits of an integer.
 * 
 * @param n An integer (can be negative).
 * @return int The sum of the digits.
 */
int sumOfNumbers(int n)
{
    int sum = 0;
    n = abs(n); // Handle negative numbers
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

/**
 * @brief Entry point of the program.
 * Reads 5 integers and prints the sum of their digits.
 */
int main()
{
    int value;
    for (int i = 0; i < 5; i++)
    {
        cin >> value;
        cout << sumOfNumbers(value) << " ";
    }
    return 0;
}