#include <iostream>
using namespace std;

void printRange(int a, int b)
{
    cout << a; // The base case (when a == b)
    if (a < b)
    {
        cout << " ";
        printRange(a + 1, b);
    }
    else if (a > b)
    {
        cout << " ";
        printRange(a - 1, b);
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    printRange(a, b);
    return 0;
}