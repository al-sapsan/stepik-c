/**********************************************************************
 * @file script3.cpp
 * @brief Проверка выхода элементов массива за диапазон [-0.5; 0.5]
 * @version 1.0
 * @date 2025-08-15
 **********************************************************************/

/*** Libraries ***/
#include "emb_style_cpp_en.h"

/*** Typedefs ***/
using PTR_FUNC = b_t (*)(f64_t);

/*** Function Prototypes ***/
/**
 * @brief Проверяет, есть ли хотя бы один элемент, удовлетворяющий критерию
 * @param ptr_arr_f64 Указатель на массив
 * @param l_len_size_t Количество элементов
 * @param ptr_filter Функция-критерий
 * @return b_t true, если найден хотя бы один элемент, иначе false
 */
b_t any(const f64_t *ptr_arr_f64, size_t l_len_size_t, PTR_FUNC ptr_filter);

/**
 * @brief Проверяет, выходит ли значение за диапазон [-0.5; 0.5]
 * @param l_x_f64 Проверяемое значение
 * @return b_t true, если выходит, иначе false
 */
b_t range_out(f64_t l_x_f64);

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    f64_t arr_values_f64[] = {0.1, 0.2, 0.3, -0.4, 1.4};
    b_t res_b = any(arr_values_f64, 5, range_out);
    (void)res_b; // suppress unused warning
    return 0;
}

/*** Function Implementation ***/
b_t any(const f64_t *ptr_arr_f64, size_t l_len_size_t, PTR_FUNC ptr_filter)
{
    for (size_t i = 0; i < l_len_size_t; ++i)
    {
        if (ptr_filter(ptr_arr_f64[i]))
        {
            return true;
        }
    }
    return false;
}

b_t range_out(f64_t l_x_f64)
{
    return (l_x_f64 < -0.5) || (l_x_f64 > 0.5);
}
