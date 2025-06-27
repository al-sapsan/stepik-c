#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

/**
 * @brief Инициализирует массив случайными значениями
 * @param arr Указатель на массив
 * @param n Размер массива
 * @details Заполняет массив случайными числами от 0 до 20
 */
void initArray(int *arr, int n);

/**
 * @brief Выводит элементы массива на экран
 * @param arr Указатель на массив
 * @param n Размер массива
 * @details Элементы выводятся через символ табуляции
 */
void printArray(int *arr, int n);

/**
 * @brief Находит индекс минимального элемента в подмассиве (рекурсивно)
 * @param arr Указатель на массив
 * @param start Начальный индекс поиска
 * @param end Конечный индекс поиска
 * @return Индекс минимального элемента
 * @details Рекурсивно сравнивает элементы для поиска минимума
 */
int findMinIndex(int *arr, int start, int end);

/**
 * @brief Сортирует массив по возрастанию (рекурсивная сортировка выбором)
 * @param arr Указатель на массив
 * @param n Размер массива
 * @param current Текущий индекс для обработки
 * @details Рекурсивно находит минимальный элемент и помещает его в текущую позицию
 */
void recursiveSort(int *arr, int n, int current);

int main()
{
    int seed;
    scanf("%d", &seed);
    srand(seed);
    int arr[SIZE];

    initArray(arr, SIZE);
    printf("Исходный массив:\n");
    printArray(arr, SIZE);

    recursiveSort(arr, SIZE, 0);
    printf("Отсортированный массив:\n");
    printArray(arr, SIZE);

    return 0;
}

void initArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 21;
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int findMinIndex(int *arr, int start, int end)
{
    if (start == end)
    {
        return start;
    }

    int minIndex = findMinIndex(arr, start + 1, end);
    return (arr[start] < arr[minIndex]) ? start : minIndex;
}

void recursiveSort(int *arr, int n, int current)
{
    if (current >= n - 1)
    {
        return; // Базовый случай: массив отсортирован
    }

    // Находим минимальный элемент в неотсортированной части
    int minIndex = findMinIndex(arr, current, n - 1);

    // Меняем местами с текущим элементом
    if (minIndex != current)
    {
        int temp = arr[current];
        arr[current] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // Рекурсивно сортируем оставшуюся часть
    recursiveSort(arr, n, current + 1);
}