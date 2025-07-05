#include <iostream>
#include <time.h>
using namespace std;

/* C++ Style */
int main()
{
    int n, *ptrInt = NULL;
    cout << "Введите размер массива: ";
    cin >> n;

    ptrInt = new int[n];   // динамич.выделение памяти из кучи
    srand(time(0));        // задание начального значения генератора
    int *tempPtr = ptrInt; // вспомогательный указатель для движения по массиву
    for (int i = 0; i < n; i++, tempPtr++)
    {
        *tempPtr = rand() % 11; // случайные числа от 0 до 10
    }
    cout << "Получен массив:\n";

    tempPtr = ptrInt; // опять вспомогательный указатель в начало
    for (int i = 0; i < n; i++)
    {
        cout << tempPtr[i] << "\t";
    }
    cout << endl;
    delete[] ptrInt;
    ptrInt = NULL;
    return 0;
}

/* C Style
int main()
{
    int n, *ptrInt;
    cout << "Введите размер массива: ";
    cin >> n;

    ptrInt = (int *)malloc(n * sizeof(int)); // динамич.выделение памяти из кучи
    srand(time(0));                          // задание начального значения генератора
    int *tempPtr = ptrInt;                   // вспомогательный указатель для движения по массиву
    for (int i = 0; i < n; i++, tempPtr++)
    {
        *tempPtr = rand() % 11; // случайные числа от 0 до 10
    }
    cout << "Получен массив:\n";

    tempPtr = ptrInt; // опять вспомогательный указатель в начало
    for (int i = 0; i < n; i++, tempPtr++)
    {
        cout << *tempPtr << "\t";
    }
    cout << endl;
    free(ptrInt); // освобождение памяти
    return 0;
}
*/