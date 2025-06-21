#include <iostream>
using namespace std;

#define I_SIZE 10
#define F_SIZE 7
#define C_SIZE 5

// Read function template
template <typename T>
void read(T *arr, int n) {
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
}

// Print function template
template <typename T>
void print(const T *arr, int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Maximum function template
template <typename T>
T* maximum(T *arr, int n) {
    T *maxPtr = arr;
    for (int i = 1; i < n; ++i) {
        if (arr[i] > *maxPtr)
            maxPtr = arr + i;
    }
    return maxPtr;
}

int main()
{
    int intArray[I_SIZE];
    double floatArray[F_SIZE];
    char charArray[C_SIZE];

    read(intArray, I_SIZE);
    read(floatArray, F_SIZE);
    read(charArray, C_SIZE);

    *maximum(intArray, I_SIZE) = 0;
    *maximum(floatArray, F_SIZE) = 0;
    *maximum(charArray, C_SIZE) = ' ';

    print(intArray, I_SIZE);
    print(floatArray, F_SIZE);
    print(charArray, C_SIZE);

    return 0;
}