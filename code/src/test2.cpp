#include "emb_style_cpp.h"
#include <iostream>

/**
 * @brief Инициализация двумерного массива случайными числами 1..10
 * @param[out] l_arr_ptr_i32 Указатель на массив
 * @param[in] l_cnt_rows_i32 Количество строк
 * @param[in] l_cnt_cols_i32 Количество столбцов
 * @param[in] l_seed_i32 Начальное значение генератора
 */
void arr2d_init_rand_i32(i32_t **l_arr_ptr_i32, i32_t l_cnt_rows_i32, i32_t l_cnt_cols_i32, i32_t l_seed_i32)
{
    u32_t l_rand_u32 = static_cast<u32_t>(l_seed_i32);
    for (i32_t l_idx_row_i32 = 0; l_idx_row_i32 < l_cnt_rows_i32; ++l_idx_row_i32)
    {
        for (i32_t l_idx_col_i32 = 0; l_idx_col_i32 < l_cnt_cols_i32; ++l_idx_col_i32)
        {
            // Линейный конгруэнтный генератор
            l_rand_u32 = 1664525U * l_rand_u32 + 1013904223U;
            l_arr_ptr_i32[l_idx_row_i32][l_idx_col_i32] = (l_rand_u32 % 10) + 1;
        }
    }
}

/**
 * @brief Печать двумерного массива
 * @param[in] l_arr_ptr_i32 Указатель на массив
 * @param[in] l_cnt_rows_i32 Количество строк
 * @param[in] l_cnt_cols_i32 Количество столбцов
 */
void arr2d_print_i32(i32_t **l_arr_ptr_i32, i32_t l_cnt_rows_i32, i32_t l_cnt_cols_i32)
{
    for (i32_t l_idx_row_i32 = 0; l_idx_row_i32 < l_cnt_rows_i32; ++l_idx_row_i32)
    {
        for (i32_t l_idx_col_i32 = 0; l_idx_col_i32 < l_cnt_cols_i32; ++l_idx_col_i32)
        {
            std::cout << l_arr_ptr_i32[l_idx_row_i32][l_idx_col_i32] << '\t';
        }
        std::cout << '\n';
    }
}

/**
 * @brief Поиск индекса строки с первым максимальным элементом
 * @param[in] l_arr_ptr_i32 Указатель на массив
 * @param[in] l_cnt_rows_i32 Количество строк
 * @param[in] l_cnt_cols_i32 Количество столбцов
 * @return Индекс строки
 */
i32_t arr2d_find_row_first_max_i32(i32_t **l_arr_ptr_i32, i32_t l_cnt_rows_i32, i32_t l_cnt_cols_i32)
{
    i32_t l_max_i32 = l_arr_ptr_i32[0][0];
    i32_t l_idx_row_max_i32 = 0;
    for (i32_t l_idx_row_i32 = 0; l_idx_row_i32 < l_cnt_rows_i32; ++l_idx_row_i32)
    {
        for (i32_t l_idx_col_i32 = 0; l_idx_col_i32 < l_cnt_cols_i32; ++l_idx_col_i32)
        {
            if (l_arr_ptr_i32[l_idx_row_i32][l_idx_col_i32] > l_max_i32)
            {
                l_max_i32 = l_arr_ptr_i32[l_idx_row_i32][l_idx_col_i32];
                l_idx_row_max_i32 = l_idx_row_i32;
            }
        }
    }
    return l_idx_row_max_i32;
}

/**
 * @brief Дублирует строку массива (вставляет копию после неё)
 * @param[in,out] l_arr_ptr_i32 Указатель на массив (массив указателей)
 * @param[in] l_cnt_rows_i32 Количество строк ДО вставки
 * @param[in] l_cnt_cols_i32 Количество столбцов
 * @param[in] l_idx_row_dup_i32 Индекс строки для дублирования
 */
void arr2d_duplicate_row_i32(i32_t **&l_arr_ptr_i32, i32_t &l_cnt_rows_i32, i32_t l_cnt_cols_i32, i32_t l_idx_row_dup_i32)
{
    // Новый массив указателей
    i32_t **l_new_arr_ptr_i32 = new i32_t *[l_cnt_rows_i32 + 1];
    for (i32_t l_idx_row_i32 = 0, l_idx_new_i32 = 0; l_idx_row_i32 < l_cnt_rows_i32 + 1; ++l_idx_row_i32)
    {
        if (l_idx_row_i32 == l_idx_row_dup_i32 + 1)
        {
            // Вставляем копию
            l_new_arr_ptr_i32[l_idx_row_i32] = new i32_t[l_cnt_cols_i32];
            for (i32_t l_idx_col_i32 = 0; l_idx_col_i32 < l_cnt_cols_i32; ++l_idx_col_i32)
            {
                l_new_arr_ptr_i32[l_idx_row_i32][l_idx_col_i32] = l_arr_ptr_i32[l_idx_row_dup_i32][l_idx_col_i32];
            }
        }
        else
        {
            l_new_arr_ptr_i32[l_idx_row_i32] = l_arr_ptr_i32[l_idx_new_i32++];
        }
    }
    ++l_cnt_rows_i32;
    delete[] l_arr_ptr_i32;
    l_arr_ptr_i32 = l_new_arr_ptr_i32;
}

int main()
{
    i32_t l_cnt_rows_i32 = 0, l_cnt_cols_i32 = 0, l_seed_i32 = 0;
    std::cin >> l_cnt_rows_i32 >> l_cnt_cols_i32 >> l_seed_i32;
    i32_t **l_arr_ptr_i32 = new i32_t *[l_cnt_rows_i32];
    for (i32_t l_idx_row_i32 = 0; l_idx_row_i32 < l_cnt_rows_i32; ++l_idx_row_i32)
    {
        l_arr_ptr_i32[l_idx_row_i32] = new i32_t[l_cnt_cols_i32];
    }
    arr2d_init_rand_i32(l_arr_ptr_i32, l_cnt_rows_i32, l_cnt_cols_i32, l_seed_i32);
    arr2d_print_i32(l_arr_ptr_i32, l_cnt_rows_i32, l_cnt_cols_i32);
    std::cout << '\n';
    i32_t l_idx_row_max_i32 = arr2d_find_row_first_max_i32(l_arr_ptr_i32, l_cnt_rows_i32, l_cnt_cols_i32);
    arr2d_duplicate_row_i32(l_arr_ptr_i32, l_cnt_rows_i32, l_cnt_cols_i32, l_idx_row_max_i32);
    arr2d_print_i32(l_arr_ptr_i32, l_cnt_rows_i32, l_cnt_cols_i32);
    // Очистка памяти
    for (i32_t l_idx_row_i32 = 0; l_idx_row_i32 < l_cnt_rows_i32; ++l_idx_row_i32)
    {
        delete[] l_arr_ptr_i32[l_idx_row_i32];
    }
    delete[] l_arr_ptr_i32;
    return 0;
}
