#include <iostream>
#define SIZE 10

using namespace std;

int binarySearch(int array[], int elem, int low, int up)
{
    // low - нижняя граница сортируемой области
    // up - верхняя граница сортируемой области
    if (low > up)
        return -1;
    int middle = (low + up) / 2; // середина области
    if (elem == array[middle])
        return middle; // элемент найден
    if (elem < array[middle])
        return binarySearch(a, elem, low, middle - 1);
    else
        return binarySearch(a, elem, middle + 1, up);
}

int main()
{
    int array[SIZE] = {-3, 0, 1, 2, 3, 4, 5, 6, 7, 8};
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << '\t';
    }
    cout << '\n';
    int elem;
    cout << "Enter element to search: ";
    cin >> elem;
    int index = binarySearch(array, elem, 0, SIZE - 1);
    if (index == -1)
    {
        cout << "Element not found.\n";
    }
    else
    {
        cout << "Element found at index: " << index << '\n';
    }

    return 0;
}