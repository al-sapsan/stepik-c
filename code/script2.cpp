/**********************************************************************
 * @file script2.cpp
 * @brief Проверка всех элементов массива по критерию (all, positive)
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-15
 **********************************************************************/

#include <cstddef>

/*** Typedefs ***/
using PTR_FUNC = bool (*)(int);

/*** Function Prototypes ***/
/**
 * @brief Проверяет, что все элементы массива удовлетворяют критерию
 * @param[in] ptr_ar_i32 Массив
 * @param[in] len_sz Количество элементов
 * @param[in] filter Функция-критерий
 * @return true — если все удовлетворяют, false — иначе
 */
bool all(const int *ptr_ar_i32, size_t len_sz, PTR_FUNC filter);

/**
 * @brief Проверяет, что число положительное
 * @param[in] x_i32 Число
 * @return true — если > 0, false — иначе
 */
bool positive(int x_i32);

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    int arr_i32[] = {2, 3, 1, -10, 15};
    bool res_b = all(arr_i32, sizeof(arr_i32) / sizeof(arr_i32[0]), positive);
    // ...existing code...
    return 0;
}

/*** Function Implementation ***/
bool all(const int *ptr_ar_i32, size_t len_sz, PTR_FUNC filter)
{
    for (size_t i = 0; i < len_sz; ++i)
    {
        if (!filter(ptr_ar_i32[i]))
            return false;
    }
    return true;
}

bool positive(int x_i32)
{
    return x_i32 > 0;
}