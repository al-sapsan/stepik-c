/**
 * @file test1.cpp
 * @brief Транспонирование матрицы с инициализацией и выводом (emb_style_cpp.h)
 * @version 1.0
 * @date 2025-07-08
 */

#include "emb_style_cpp.h"
#include <iostream>
#include <cstdlib>
#include <cstdint>

using std::cin;
using std::cout;

typedef int32_t i32_t;
typedef int16_t i16_t;

/*** 🧩 Прототипы функций ***/

/**
 * @brief Инициализирует двумерный массив случайными числами от -10 до 15
 * @param arr_ptr Указатель на массив указателей
 * @param rows_i16 Количество строк
 * @param cols_i16 Количество столбцов
 */
void matrix_init_i32(i32_t **arr_ptr, i16_t rows_i16, i16_t cols_i16);

/**
 * @brief Печатает двумерный массив в виде таблицы с табуляцией
 * @param arr_ptr Указатель на массив указателей
 * @param rows_i16 Количество строк
 * @param cols_i16 Количество столбцов
 */
void matrix_print_i32(const i32_t **arr_ptr, i16_t rows_i16, i16_t cols_i16);

/**
 * @brief Транспонирует двумерный массив (создаёт новый массив и копирует элементы)
 * @param arr_ptr Указатель на исходный массив
 * @param rows_i16 Количество строк исходного массива
 * @param cols_i16 Количество столбцов исходного массива
 * @return Новый транспонированный массив
 */
i32_t **matrix_transpose_i32(i32_t **arr_ptr, i16_t rows_i16, i16_t cols_i16);

/**
 * @brief Освобождает память, занятую двумерным массивом
 * @param arr_ptr Указатель на массив указателей
 * @param rows_i16 Количество строк
 */
void matrix_free_i32(i32_t **arr_ptr, i16_t rows_i16);

/*** 🧩 Реализация функций ***/

void matrix_init_i32(i32_t **arr_ptr, i16_t rows_i16, i16_t cols_i16)
{
    for (i16_t row = 0; row < rows_i16; ++row)
    {
        for (i16_t col = 0; col < cols_i16; ++col)
        {
            arr_ptr[row][col] = std::rand() % 26 - 10;
        }
    }
}

void matrix_print_i32(const i32_t **arr_ptr, i16_t rows_i16, i16_t cols_i16)
{
    for (i16_t row = 0; row < rows_i16; ++row)
    {
        for (i16_t col = 0; col < cols_i16; ++col)
        {
            cout << arr_ptr[row][col] << "\t";
        }
        cout << "\n";
    }
}

i32_t **matrix_transpose_i32(i32_t **arr_ptr, i16_t rows_i16, i16_t cols_i16)
{
    i32_t **tr_ptr = new i32_t *[cols_i16];
    for (i16_t col = 0; col < cols_i16; ++col)
    {
        tr_ptr[col] = new i32_t[rows_i16];
    }
    for (i16_t row = 0; row < rows_i16; ++row)
    {
        for (i16_t col = 0; col < cols_i16; ++col)
        {
            tr_ptr[col][row] = arr_ptr[row][col];
        }
    }
    return tr_ptr;
}

void matrix_free_i32(i32_t **arr_ptr, i16_t rows_i16)
{
    for (i16_t row = 0; row < rows_i16; ++row)
    {
        delete[] arr_ptr[row];
    }
    delete[] arr_ptr;
}

/*** 🏁 Главная функция ***/
int main(void)
{
    i16_t rows_i16, cols_i16, seed_i16;
    cin >> rows_i16 >> cols_i16 >> seed_i16;
    std::srand(seed_i16);

    i32_t **arr_ptr = new i32_t *[rows_i16];
    for (i16_t row = 0; row < rows_i16; ++row)
    {
        arr_ptr[row] = new i32_t[cols_i16];
    }
    matrix_init_i32(arr_ptr, rows_i16, cols_i16);

    matrix_print_i32(const_cast<const i32_t **>(arr_ptr), rows_i16, cols_i16);
    cout << "\n";

    i32_t **tr_ptr = matrix_transpose_i32(arr_ptr, rows_i16, cols_i16);
    matrix_print_i32(const_cast<const i32_t **>(tr_ptr), cols_i16, rows_i16);

    matrix_free_i32(arr_ptr, rows_i16);
    matrix_free_i32(tr_ptr, cols_i16);

    return 0;
}