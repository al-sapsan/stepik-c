/**
 * @file triangular_array.cpp
 * @brief Работа с треугольным массивом
 *
 * @details Программа создает треугольный массив, заполняет его случайными числами
 * от 10 до 50 и выводит на экран с табуляцией между элементами.
 */

#include <stdint.h>
#include <iostream>

/* --- Типы --- */
typedef int16_t i16_t;
typedef uint16_t u16_t;

/* --- Прототипы функций --- */
/**
 * @brief Создает треугольный массив
 * @param rows Количество строк
 * @return Указатель на созданный массив
 */
i16_t **create_triangular_array(i16_t rows);

/**
 * @brief Заполняет массив случайными числами от 10 до 50
 * @param array Указатель на массив
 * @param rows Количество строк
 * @param seed Значение для инициализации генератора случайных чисел
 */
void fill_triangular_array(i16_t **array, i16_t rows, i16_t seed);

/**
 * @brief Печатает массив построчно
 * @param array Указатель на массив
 * @param rows Количество строк
 */
void print_triangular_array(i16_t **array, i16_t rows);

/**
 * @brief Освобождает память, занятую массивом
 * @param array Указатель на массив
 * @param rows Количество строк
 */
void free_triangular_array(i16_t **array, i16_t rows);

/* --- main --- */
int main(void)
{
    i16_t l_rows_i16;
    i16_t l_seed_i16;

    std::cin >> l_rows_i16 >> l_seed_i16;

    i16_t **l_array_ptr = create_triangular_array(l_rows_i16);

    fill_triangular_array(l_array_ptr, l_rows_i16, l_seed_i16);

    print_triangular_array(l_array_ptr, l_rows_i16);

    free_triangular_array(l_array_ptr, l_rows_i16);

    return 0;
}

/* --- Реализация функций --- */

i16_t **create_triangular_array(i16_t rows)
{
    i16_t **l_array = new i16_t *[rows];
    for (i16_t l_i = 0; l_i < rows; ++l_i)
    {
        l_array[l_i] = new i16_t[l_i + 1];
    }
    return l_array;
}

void fill_triangular_array(i16_t **array, i16_t rows, i16_t seed)
{
    std::srand(static_cast<u16_t>(seed));
    for (i16_t l_i = 0; l_i < rows; ++l_i)
    {
        for (i16_t l_j = 0; l_j <= l_i; ++l_j)
        {
            array[l_i][l_j] = 10 + std::rand() % 41;
        }
    }
}

void print_triangular_array(i16_t **array, i16_t rows)
{
    for (i16_t l_i = 0; l_i < rows; ++l_i)
    {
        for (i16_t l_j = 0; l_j <= l_i; ++l_j)
        {
            std::cout << array[l_i][l_j] << "\t";
        }
        std::cout << "\n";
    }
}

void free_triangular_array(i16_t **array, i16_t rows)
{
    for (i16_t l_i = 0; l_i < rows; ++l_i)
    {
        delete[] array[l_i];
    }
    delete[] array;
}
