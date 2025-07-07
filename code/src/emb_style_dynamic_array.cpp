#include <iostream>
#include <cstdlib>
#include <stdint.h>

using namespace std;

// Типы данных согласно style.h
typedef uint32_t u32_t;
typedef int32_t i32_t;
typedef int8_t i8_t;

// Прототипы функций
void initArray(i8_t *&arr, size_t size);
void printArray(const i8_t *arr, size_t size);
void removeZeros(i8_t *&arr, size_t &size);

int main()
{
    size_t n;   // для размера массива
    u32_t seed; // для генератора случайных чисел

    cin >> n >> seed;
    srand(seed);

    i8_t *arr = nullptr;
    initArray(arr, n);
    printArray(arr, n);
    removeZeros(arr, n);
    printArray(arr, n);

    delete[] arr;
    return 0;
}

/**
 * @brief Инициализирует массив случайными числами от -5 до 5
 */
void initArray(i8_t *&arr, size_t size)
{
    arr = new i8_t[size];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = static_cast<i8_t>(rand() % 11 - 5);
    }
}

/**
 * @brief Выводит элементы массива через пробел
 */
void printArray(const i8_t *arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << static_cast<i32_t>(arr[i]) << " ";
    }
    cout << endl;
}

/**
 * @brief Удаляет нулевые элементы из массива
 */
void removeZeros(i8_t *&arr, size_t &size)
{
    size_t new_size = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] != 0)
            new_size++;
    }

    i8_t *new_arr = new i8_t[new_size];
    for (size_t i = 0, j = 0; i < size; i++)
    {
        if (arr[i] != 0)
            new_arr[j++] = arr[i];
    }

    delete[] arr;
    arr = new_arr;
    size = new_size;
}