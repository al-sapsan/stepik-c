#include <iostream>
#include <time.h>
#define SIZE 10

using namespace std;

void quickSort(int array[], int left, int right)
{
    if (left > right)
        return; // завершение рекурсии
    int i = left;
    int j = right;
    int p = array[(left + right) / 2]; // опорный элемент
    // процедура разделения
    while (i <= j)
    {
        while (array[i] < p)
            i++; // левый индекс двигаем до эл-та, >= опорного
        while (array[j] > p)
            j--; // правый индекс двигаем до эл-та, <= опорного
        if (i <= j)
        { // если индексы еще не разошлись
            // меняем элементы местами
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            // продвигаем индексы на один шаг
            i++;
            j--;
        }
    }
    quickSort(array, left, j);  // отсортировать левый подмассив
    quickSort(array, i, right); // отсортировать правый подмассив

    int main()
    {
        srand(time(0));
        int array[SIZE] = {0};
        puts("The original array:");
        for (int i = 0; i < SIZE; i++)
        {
            array[i] = rand() % 16; // заполняем массив случайными числами
            printf("%d\t", array[i]);
        }
        printf("\n");
        quickSort(array, 0, SIZE - 1); // вызов функции быстрой сортировки
        puts("The sorted array: ");
        for (int i = 0; i < SIZE; i++)
        {
            printf("%d\t", array[i]); // вывод отсортированного массива
        }
        printf("\n");
        return 0;
    }