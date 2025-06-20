#include <iostream>
using namespace std;

/**
 * @brief Reads n elements into array a from standard input.
 * @param a Array to fill.
 * @param n Number of elements.
 */
void read(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

/**
 * @brief Finds the last minimal element in array a, its value and index.
 * @param a Array to search.
 * @param n Number of elements.
 * @param minim Reference to store minimal value.
 * @param imin Reference to store index of last minimal value.
 */
void myMin(const int a[], int n, int &minim, int &imin)
{
    minim = a[0];
    imin = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < minim)
        {
            minim = a[i];
            imin = i;
        }
        else if (a[i] == minim)
        {
            imin = i; // update to last occurrence
        }
    }
}

int main()
{
    const int N = 5;
    const int M = 10;
    int a[N], b[M];
    int minim, imin;
    read(a, N);
    myMin(a, N, minim, imin);
    cout << minim << " " << (imin + 1) << endl;
    read(b, M);
    myMin(b, M, minim, imin);
    cout << minim << " " << (imin + 1) << endl;
    return 0;
}
