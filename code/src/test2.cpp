#include "emb_style_cpp.h"
#include <iostream>
#include <cstdlib>

/**
 * @brief Инициализация двумерного массива случайными числами 1..10
 * @param[out] l_arr_ptr_ptr Указатель на массив указателей
 * @param[in] l_cnt_rows_i16 Количество строк
 * @param[in] l_cnt_cols_i16 Количество столбцов
 * @param[in] l_seed_i16 Начальное значение генератора
 */
void arr2d_init_rand_i16(i16_t **l_arr_ptr_ptr, i16_t l_cnt_rows_i16, i16_t l_cnt_cols_i16, i16_t l_seed_i16)
{
    std::srand(static_cast<unsigned int>(l_seed_i16));
    for (i16_t i = 0; i < l_cnt_rows_i16; ++i)
    {
        for (i16_t j = 0; j < l_cnt_cols_i16; ++j)
        {
            l_arr_ptr_ptr[i][j] = static_cast<i16_t>(std::rand() % 10 + 1);
        }
    }
}

/**
 * @brief Печать двумерного массива
 * @param[in] l_arr_ptr_ptr Указатель на массив указателей
 * @param[in] l_cnt_rows_i16 Количество строк
 * @param[in] l_cnt_cols_i16 Количество столбцов
 */
void arr2d_print_i16(i16_t **l_arr_ptr_ptr, i16_t l_cnt_rows_i16, i16_t l_cnt_cols_i16)
{
    for (i16_t i = 0; i < l_cnt_rows_i16; ++i)
    {
        for (i16_t j = 0; j < l_cnt_cols_i16; ++j)
        {
            std::cout << l_arr_ptr_ptr[i][j] << '\t';
        }
        std::cout << '\n';
    }
}

/**
 * @brief Поиск индекса строки с первым максимальным элементом
 * @param[in] l_arr_ptr_ptr Указатель на массив указателей
 * @param[in] l_cnt_rows_i16 Количество строк
 * @param[in] l_cnt_cols_i16 Количество столбцов
 * @return Индекс строки
 */
i16_t arr2d_find_row_first_max_i16(i16_t **l_arr_ptr_ptr, i16_t l_cnt_rows_i16, i16_t l_cnt_cols_i16)
{
    i16_t l_max_i16 = l_arr_ptr_ptr[0][0];
    i16_t l_idx_row_max_i16 = 0;
    for (i16_t i = 0; i < l_cnt_rows_i16; ++i)
    {
        for (i16_t j = 0; j < l_cnt_cols_i16; ++j)
        {
            if (l_arr_ptr_ptr[i][j] > l_max_i16)
            {
                l_max_i16 = l_arr_ptr_ptr[i][j];
                l_idx_row_max_i16 = i;
            }
        }
    }
    return l_idx_row_max_i16;
}

/**
 * @brief Дублирует строку массива (вставляет копию после неё)
 * @param[in,out] l_arr_ptr_ptr Указатель на массив указателей (будет изменён)
 * @param[in,out] l_cnt_rows_ptr_i16 Указатель на количество строк (будет увеличено)
 * @param[in] l_cnt_cols_i16 Количество столбцов
 * @param[in] l_idx_row_dup_i16 Индекс строки для дублирования
 */
void arr2d_duplicate_row_i16(i16_t ***l_arr_ptr_ptr_ptr, i16_t *l_cnt_rows_ptr_i16, i16_t l_cnt_cols_i16, i16_t l_idx_row_dup_i16)
{
    i16_t l_cnt_rows_i16 = *l_cnt_rows_ptr_i16;
    i16_t **l_old_arr_ptr_ptr = *l_arr_ptr_ptr_ptr;
    i16_t **l_new_arr_ptr_ptr = (i16_t **)malloc((l_cnt_rows_i16 + 1) * sizeof(i16_t *));
    CHECK_NULL(l_new_arr_ptr_ptr);
    for (i16_t i = 0, k = 0; i < l_cnt_rows_i16 + 1; ++i)
    {
        if (i == l_idx_row_dup_i16 + 1)
        {
            l_new_arr_ptr_ptr[i] = (i16_t *)malloc(l_cnt_cols_i16 * sizeof(i16_t));
            CHECK_NULL(l_new_arr_ptr_ptr[i]);
            for (i16_t j = 0; j < l_cnt_cols_i16; ++j)
            {
                l_new_arr_ptr_ptr[i][j] = l_old_arr_ptr_ptr[l_idx_row_dup_i16][j];
            }
        }
        else
        {
            l_new_arr_ptr_ptr[i] = l_old_arr_ptr_ptr[k++];
        }
    }
    free(l_old_arr_ptr_ptr);
    *l_arr_ptr_ptr_ptr = l_new_arr_ptr_ptr;
    *l_cnt_rows_ptr_i16 = l_cnt_rows_i16 + 1;
}

int main(void)
{
    i16_t l_cnt_rows_i16 = 0, l_cnt_cols_i16 = 0, l_seed_i16 = 0;
    std::cin >> l_cnt_rows_i16 >> l_cnt_cols_i16 >> l_seed_i16;
    i16_t **l_arr_ptr_ptr = (i16_t **)malloc(l_cnt_rows_i16 * sizeof(i16_t *));
    CHECK_NULL(l_arr_ptr_ptr);
    for (i16_t i = 0; i < l_cnt_rows_i16; ++i)
    {
        l_arr_ptr_ptr[i] = (i16_t *)malloc(l_cnt_cols_i16 * sizeof(i16_t));
        CHECK_NULL(l_arr_ptr_ptr[i]);
    }
    arr2d_init_rand_i16(l_arr_ptr_ptr, l_cnt_rows_i16, l_cnt_cols_i16, l_seed_i16);
    arr2d_print_i16(l_arr_ptr_ptr, l_cnt_rows_i16, l_cnt_cols_i16);
    std::cout << '\n';
    i16_t l_idx_row_max_i16 = arr2d_find_row_first_max_i16(l_arr_ptr_ptr, l_cnt_rows_i16, l_cnt_cols_i16);
    arr2d_duplicate_row_i16(&l_arr_ptr_ptr, &l_cnt_rows_i16, l_cnt_cols_i16, l_idx_row_max_i16);
    arr2d_print_i16(l_arr_ptr_ptr, l_cnt_rows_i16, l_cnt_cols_i16);
    // Очистка памяти
    for (i16_t i = 0; i < l_cnt_rows_i16; ++i)
    {
        free(l_arr_ptr_ptr[i]);
    }
    free(l_arr_ptr_ptr);
    return 0;
}
