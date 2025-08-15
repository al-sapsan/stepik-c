/**********************************************************************
 * @file script2.cpp
 * @brief Фильтрация массива целых чисел по критерию (namespace array_alg)
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-04
 **********************************************************************/

#include <iostream>
#include <sstream>

/*** Typedefs ***/
typedef int i32_t;

/*** Function Prototypes ***/
namespace array_alg
{
    /**
     * @brief Тип указателя на функцию фильтрации
     */
    typedef int (*PTR_FILTER_FUNC)(i32_t);

    /**
     * @brief Фильтрует массив целых чисел по критерию
     * @param[in,out] ptr_ar_i32 Массив для фильтрации
     * @param[in] len_ar_sz Начальная длина массива
     * @param[in] func Функция-критерий
     * @return Новая длина массива
     */
    size_t filter_int(i32_t *ptr_ar_i32, size_t len_ar_sz, PTR_FILTER_FUNC func);

    /*** Вложенное пространство имен для фильтрующих функций ***/
    namespace filter_func
    {
        /**
         * @brief Критерий: четное число
         * @param[in] val_i32 Значение
         * @return 1 — если четное, 0 — иначе
         */
        int even(i32_t val_i32);
    }
}

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    const size_t MAX_LEN_SZ = 20;
    i32_t arr_i32[MAX_LEN_SZ] = {0};
    size_t len_sz = 0;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    i32_t val_i32 = 0;
    while (iss >> val_i32 && len_sz < MAX_LEN_SZ)
    {
        arr_i32[len_sz++] = val_i32;
    }
    len_sz = array_alg::filter_int(arr_i32, len_sz, array_alg::filter_func::even);
    for (size_t i = 0; i < len_sz; ++i)
    {
        std::cout << arr_i32[i];
        if (i + 1 < len_sz)
            std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}

/*** Function Implementation ***/
size_t array_alg::filter_int(i32_t *ptr_ar_i32, size_t len_ar_sz, PTR_FILTER_FUNC func)
{
    size_t i = 0;
    while (i < len_ar_sz)
    {
        if (!func(ptr_ar_i32[i]))
        {
            for (size_t j = i; j + 1 < len_ar_sz; ++j)
            {
                ptr_ar_i32[j] = ptr_ar_i32[j + 1];
            }
            --len_ar_sz;
        }
        else
        {
            ++i;
        }
    }
    return len_ar_sz;
}

int array_alg::filter_func::even(i32_t val_i32)
{
    return (val_i32 % 2 == 0);
}
