/**
 * @brief Транспонирование матрицы с инициализацией и выводом (emb_style_cpp.h)
 * @version 1.0
 * @date 2025-07-08
 */

#include "emb_style_cpp.h"
#include <iostream>
#include <cstdlib>
#include <cstdint>

typedef int32_t i32_t;
typedef int16_t i16_t;

/*** Прототипы функций ***/

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

/*** Главная функция ***/
int main(void)
{
    i16_t l_rows_i16 = 0;
    i16_t l_cols_i16 = 0;
    i16_t l_seed_i16 = 0;

    std::cin >> l_rows_i16 >> l_cols_i16 >> l_seed_i16;
    std::srand(l_seed_i16);

    i32_t **l_arr_ptr = new i32_t *[l_rows_i16];
    for (i16_t l_row_i16 = 0; l_row_i16 < l_rows_i16; ++l_row_i16)
    {
        l_arr_ptr[l_row_i16] = new i32_t[l_cols_i16];
    }

    matrix_init_i32(l_arr_ptr, l_rows_i16, l_cols_i16);

    matrix_print_i32(const_cast<const i32_t **>(l_arr_ptr), l_rows_i16, l_cols_i16);
    std::cout << "\n";

    i32_t **l_tr_ptr = matrix_transpose_i32(l_arr_ptr, l_rows_i16, l_cols_i16);

    matrix_print_i32(const_cast<const i32_t **>(l_tr_ptr), l_cols_i16, l_rows_i16);

    matrix_free_i32(l_arr_ptr, l_rows_i16);
    matrix_free_i32(l_tr_ptr, l_cols_i16);

    return 0;
}

/*** Реализация функций ***/

void matrix_init_i32(i32_t **arr_ptr, i16_t rows_i16, i16_t cols_i16)
{
    for (i16_t l_row_i16 = 0; l_row_i16 < rows_i16; ++l_row_i16)
    {
        for (i16_t l_col_i16 = 0; l_col_i16 < cols_i16; ++l_col_i16)
        {
            arr_ptr[l_row_i16][l_col_i16] = std::rand() % 26 - 10;
        }
    }
}

void matrix_print_i32(const i32_t **arr_ptr, i16_t rows_i16, i16_t cols_i16)
{
    for (i16_t l_row_i16 = 0; l_row_i16 < rows_i16; ++l_row_i16)
    {
        for (i16_t l_col_i16 = 0; l_col_i16 < cols_i16; ++l_col_i16)
        {
            std::cout << arr_ptr[l_row_i16][l_col_i16] << "\t";
        }
        std::cout << "\n";
    }
}

i32_t **matrix_transpose_i32(i32_t **arr_ptr, i16_t rows_i16, i16_t cols_i16)
{
    i32_t **l_tr_ptr = new i32_t *[cols_i16];

    for (i16_t l_col_i16 = 0; l_col_i16 < cols_i16; ++l_col_i16)
    {
        l_tr_ptr[l_col_i16] = new i32_t[rows_i16];
    }

    for (i16_t l_row_i16 = 0; l_row_i16 < rows_i16; ++l_row_i16)
    {
        for (i16_t l_col_i16 = 0; l_col_i16 < cols_i16; ++l_col_i16)
        {
            l_tr_ptr[l_col_i16][l_row_i16] = arr_ptr[l_row_i16][l_col_i16];
        }
    }

    return l_tr_ptr;
}

void matrix_free_i32(i32_t **arr_ptr, i16_t rows_i16)
{
    for (i16_t l_row_i16 = 0; l_row_i16 < rows_i16; ++l_row_i16)
    {
        delete[] arr_ptr[l_row_i16];
    }

    delete[] arr_ptr;
}
