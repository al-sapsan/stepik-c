#include <iostream>
using namespace std;

// Read function template
template <typename T>
void read(T *arr, int n)
{
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
}

// Print function template
template <typename T>
void print(const T *arr, int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Remove function template for int and double
template <typename T>
void remove(T *arr, int n, int ind)
{
    if (ind < 0 || ind >= n)
        return;
    for (int i = ind; i < n - 1; ++i)
        arr[i] = arr[i + 1];
    arr[n - 1] = 0;
}

// Remove function overload for char
void remove(char *arr, int n, int ind)
{
    if (ind < 0 || ind >= n)
        return;
    for (int i = ind; i < n - 1; ++i)
        arr[i] = arr[i + 1];
    arr[n - 1] = '#';
}

int main()
{
    const int N = 10;
    int a[N];
    double b[N];
    char c[N];
    read(a, N);
    int ind;
    cin >> ind;
    remove(a, N, ind);
    print(a, N);
    read(b, N);
    cin >> ind;
    remove(b, N, ind);
    print(b, N);
    read(c, N);
    cin >> ind;
    remove(c, N, ind);
    print(c, N);
    return 0;
}