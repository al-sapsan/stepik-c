#include <iostream>
#include <cstdarg>
using namespace std;

/**
 * @brief Calculates the arithmetic mean of a variable number of int arguments.
 * @param count Number of following int arguments.
 * @param ... The int arguments.
 * @return The arithmetic mean as double.
 */
double findAverage(int count, ...)
{
    va_list args;
    va_start(args, count);
    int sum = 0;
    for (int i = 0; i < count; ++i)
    {
        sum += va_arg(args, int);
    }
    va_end(args);
    return (double)sum / count;
}

int main()
{
    cout << findAverage(3, 5, 7, 12) << " " << findAverage(5, 1, 8, 3, 2, -5);
    return 0;
}