/**
 * @file dynamic_array.cpp
 * @brief Программа для работы с динамическим массивом целых чисел
 */

#include <iostream>
#include <cstdlib>
#include <stdint.h>

using namespace std;

/**
 * @brief Создает и заполняет массив случайными числами в диапазоне [-7, 15]
 *
 * @param[in] n Количество элементов массива
 * @param[in] seed Начальное значение генератора случайных чисел
 * @return Указатель на созданный массив
 *
 * @note Выделяет память, которую нужно освободить с помощью delete[]
 */
int32_t *create_array(size_t n, uint32_t seed)
{
    int32_t *arr = new int32_t[n];
    srand(seed);

    for (size_t i = 0; i < n; i++)
    {
        arr[i] = rand() % 23 - 7; // Диапазон [-7, 15] (23 = 15 - (-7) + 1)
    }

    return arr;
}

/**
 * @brief Находит минимальный и максимальный элементы массива
 *
 * @param[in] arr Указатель на массив
 * @param[in] n Количество элементов массива
 * @param[out] min Ссылка для сохранения минимального значения
 * @param[out] max Ссылка для сохранения максимального значения
 */
void find_min_max(const int32_t *arr, size_t n, int32_t &min, int32_t &max)
{
    min = arr[0];
    max = arr[0];

    for (size_t i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
}

/**
 * @brief Главная функция программы
 *
 * @return Код завершения программы
 */
int main()
{
    size_t n;
    uint32_t seed;

    // Ввод параметров
    cin >> n >> seed;

    // Создание и заполнение массива
    int32_t *arr = create_array(n, seed);

    // Вывод элементов массива
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // Поиск минимального и максимального элементов
    int32_t min, max;
    find_min_max(arr, n, min, max);

    // Вывод суммы минимального и максимального элементов
    cout << (min + max) << "\n";

    // Освобождение памяти
    delete[] arr;

    return 0;
}