/**********************************************************************
 * @file script9.cpp
 * @brief Сравнение двух массивов типа short (namespace math)
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-04
 **********************************************************************/

#include <iostream>

/*** Typedefs ***/
typedef short i16_t;

/*** Function Prototypes ***/
namespace math
{
    /**
     * @brief Сравнивает два массива типа short
     * @param[in] ptr_a1_i16 Указатель на первый массив
     * @param[in] len_a1_sz Длина первого массива
     * @param[in] ptr_a2_i16 Указатель на второй массив
     * @param[in] len_a2_sz Длина второго массива
     * @return 1 — массивы равны, 0 — не равны
     */
    i16_t ar_compare(const i16_t *ptr_a1_i16, size_t len_a1_sz, const i16_t *ptr_a2_i16, size_t len_a2_sz);
}

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    i16_t ar1_i16[] = {1, 2, 3, 4, 5};
    i16_t ar2_i16[] = {1, 2, 5, 3, 4};
    int res_i32 = math::ar_compare(ar1_i16, sizeof(ar1_i16) / sizeof(i16_t), ar2_i16, sizeof(ar2_i16) / sizeof(i16_t));
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}

/*** Function Implementation ***/
i16_t math::ar_compare(const i16_t *ptr_a1_i16, size_t len_a1_sz, const i16_t *ptr_a2_i16, size_t len_a2_sz)
{
    if (len_a1_sz != len_a2_sz)
    {
        return 0;
    }
    for (size_t i = 0; i < len_a1_sz; ++i)
    {
        if (ptr_a1_i16[i] != ptr_a2_i16[i])
        {
            return 0;
        }
    }
    return 1;
}
