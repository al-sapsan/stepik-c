#include <iostream>
#include <cstdarg>
using namespace std;

/**
 * @brief Returns the maximum value among a variable number of arguments.
 * @param count Number of values to compare.
 * @param type 'd' for int, 'f' for double.
 * @param ... The values to compare.
 * @return The maximum value as double.
 */
double mymax(int count, char type, ...)
{
    va_list args;
    va_start(args, type);
    double maxVal;
    if (type == 'd')
    {
        int val = va_arg(args, int);
        maxVal = val;
        for (int i = 1; i < count; ++i)
        {
            val = va_arg(args, int);
            if (val > maxVal)
                maxVal = val;
        }
    }
    else if (type == 'f')
    {
        double val = va_arg(args, double);
        maxVal = val;
        for (int i = 1; i < count; ++i)
        {
            val = va_arg(args, double);
            if (val > maxVal)
                maxVal = val;
        }
    }
    va_end(args);
    return maxVal;
}

int main()
{
    cout << mymax(5, 'd', 3, 6, 7, -2, 1) << endl;
    cout << mymax(3, 'f', -2.3, 3.14, 0.72) << endl;
    cout << mymax(6, 'f', -13., 0.23, 6.6, 4.56, 0.0, -1.1) << endl;
    cout << mymax(4, 'd', 3, 7, 2, 15);
    return 0;
}