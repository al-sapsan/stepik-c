#include <iostream>
using namespace std;

#define SIZE 10

/**
 * @brief Рекурсивная функция быстрой сортировки по убыванию
 * @param arr Сортируемый массив
 * @param left Левая граница сортировки
 * @param right Правая граница сортировки
 */
void mySort(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j)
    {
        while (arr[i] > pivot)
            i++; // Ищем элементы меньше опорного слева
        while (arr[j] < pivot)
            j--; // Ищем элементы больше опорного справа

        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    mySort(arr, left, j);
    mySort(arr, i, right);
}

int main()
{
    int arr[SIZE];

    // Ввод массива с консоли
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }

    // Сортировка массива
    mySort(arr, 0, SIZE - 1);

    // Вывод отсортированного массива
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}