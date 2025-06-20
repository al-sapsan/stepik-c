#include <iostream>
using namespace std;

/**
 * @brief Orders two integers so that the first is less than or equal to the second.
 *
 * @param a Reference to the first integer.
 * @param b Reference to the second integer.
 */
void order(int &a, int &b)
{
    if (a > b) // swap (a, b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    order(a, b);
    cout << "a=" << a << " b=" << b << endl;
    return 0;
}
