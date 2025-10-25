/**
 * @file dynamic_array.c
 * @brief Программа для работы с динамическим массивом целых чисел
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <time.h>

/**
 * @brief Создает и заполняет массив случайными числами
 *
 * @param[in] n Количество элементов массива
 * @param[in] seed Начальное значение генератора случайных чисел
 * @return Указатель на созданный массив
 *
 * @note Выделяет память, которую нужно освободить с помощью free()
 */
int32_t *create_array(size_t n, uint32_t seed)
{
    int32_t *arr = (int32_t *)malloc(n * sizeof(int32_t));
    if (arr == NULL)
    {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }

    srand(seed);
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = rand() % 21; // Диапазон 0-20
    }

    return arr;
}

/**
 * @brief Выводит элементы массива
 *
 * @param[in] arr Указатель на массив
 * @param[in] n Количество элементов массива
 */
void print_array(const int32_t *arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%" PRId32 " ", arr[i]);
    }
    putchar('\n');
}

/**
 * @brief Вычисляет сумму элементов массива
 *
 * @param[in] arr Указатель на массив
 * @param[in] n Количество элементов массива
 * @return Сумма элементов массива
 */
int32_t sum_array(const int32_t *arr, size_t n)
{
    int32_t sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

/**
 * @brief Главная функция программы
 *
 * @return Код завершения программы
 */
int main(void)
{
    size_t n;
    uint32_t seed;

    // Ввод параметров
    if (scanf("%zu %" SCNu32, &n, &seed) != 2)
    {
        fprintf(stderr, "Ошибка ввода данных\n");
        return EXIT_FAILURE;
    }

    // Создание и обработка массива
    int32_t *arr = create_array(n, seed);
    print_array(arr, n);
    printf("%" PRId32 "\n", sum_array(arr, n));

    // Освобождение памяти
    free(arr);

    return EXIT_SUCCESS;
}