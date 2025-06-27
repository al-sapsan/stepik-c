#include <iostream>
using namespace std;

int printNumber(int k)
{
    if (k == 0)
        return 0;
    printNumber(k / 10);
    cout << k % 10 << " ";
}

int main()
{
    int k;
    cin >> k;
    printNumber(k);
    return 0;
}