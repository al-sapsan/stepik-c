/**
 * @file magic_square_check.cpp
 * @brief Проверка, является ли квадрат магическим
 */

#include <iostream>
#include <cstdlib>
#include <stdint.h>

/*** Типы данных ***/
typedef int16_t i16_t;
typedef bool b_t;

/*** Прототипы функций ***/

/**
 * @brief Проверяет, является ли квадрат магическим
 * @param l_matrix_i16 Указатель на квадратную матрицу
 * @param l_n_i16 Размерность матрицы (n x n)
 * @return true, если магический, иначе false
 */
b_t is_magic_square(i16_t **l_matrix_i16, i16_t l_n_i16);

/*** Главная функция ***/

int main()
{
    i16_t l_n_i16 = 0;
    std::cin >> l_n_i16;

    i16_t **l_matrix_i16 = new i16_t *[l_n_i16];
    for (i16_t l_idx_i16 = 0; l_idx_i16 < l_n_i16; ++l_idx_i16)
    {
        l_matrix_i16[l_idx_i16] = new i16_t[l_n_i16];
    }

    for (i16_t l_i_i16 = 0; l_i_i16 < l_n_i16; ++l_i_i16)
    {
        for (i16_t l_j_i16 = 0; l_j_i16 < l_n_i16; ++l_j_i16)
        {
            std::cin >> l_matrix_i16[l_i_i16][l_j_i16];
        }
    }

    if (is_magic_square(l_matrix_i16, l_n_i16))
    {
        std::cout << "YES\n";
    }
    else
    {
        std::cout << "NO\n";
    }

    for (i16_t l_idx_i16 = 0; l_idx_i16 < l_n_i16; ++l_idx_i16)
    {
        delete[] l_matrix_i16[l_idx_i16];
    }
    delete[] l_matrix_i16;

    return 0;
}

/*** Реализация функции проверки ***/

b_t is_magic_square(i16_t **l_matrix_i16, i16_t l_n_i16)
{
    i16_t l_sum_ref_i16 = 0;

    for (i16_t l_j_i16 = 0; l_j_i16 < l_n_i16; ++l_j_i16)
    {
        l_sum_ref_i16 += l_matrix_i16[0][l_j_i16];
    }

    // Проверка строк
    for (i16_t l_i_i16 = 1; l_i_i16 < l_n_i16; ++l_i_i16)
    {
        i16_t l_sum_row_i16 = 0;
        for (i16_t l_j_i16 = 0; l_j_i16 < l_n_i16; ++l_j_i16)
        {
            l_sum_row_i16 += l_matrix_i16[l_i_i16][l_j_i16];
        }
        if (l_sum_row_i16 != l_sum_ref_i16)
        {
            return false;
        }
    }

    // Проверка столбцов
    for (i16_t l_j_i16 = 0; l_j_i16 < l_n_i16; ++l_j_i16)
    {
        i16_t l_sum_col_i16 = 0;
        for (i16_t l_i_i16 = 0; l_i_i16 < l_n_i16; ++l_i_i16)
        {
            l_sum_col_i16 += l_matrix_i16[l_i_i16][l_j_i16];
        }
        if (l_sum_col_i16 != l_sum_ref_i16)
        {
            return false;
        }
    }

    // Главная диагональ
    i16_t l_sum_diag_main_i16 = 0;
    for (i16_t l_i_i16 = 0; l_i_i16 < l_n_i16; ++l_i_i16)
    {
        l_sum_diag_main_i16 += l_matrix_i16[l_i_i16][l_i_i16];
    }
    if (l_sum_diag_main_i16 != l_sum_ref_i16)
    {
        return false;
    }

    // Побочная диагональ
    i16_t l_sum_diag_sec_i16 = 0;
    for (i16_t l_i_i16 = 0; l_i_i16 < l_n_i16; ++l_i_i16)
    {
        l_sum_diag_sec_i16 += l_matrix_i16[l_i_i16][l_n_i16 - 1 - l_i_i16];
    }
    if (l_sum_diag_sec_i16 != l_sum_ref_i16)
    {
        return false;
    }

    return true;
}
