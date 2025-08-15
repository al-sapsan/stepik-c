/**********************************************************************
 * @file script3.cpp
 * @brief Добавление отфильтрованных значений в массив (namespace array_alg)
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
     * @brief Добавляет отфильтрованные значения из dest в src
     * @param[in,out] ptr_src_i32 Массив, в который добавляются значения
     * @param[in] start_sz Начальный индекс для добавления
     * @param[in] max_len_src_sz Максимальная длина массива src
     * @param[in] ptr_dest_i32 Массив, из которого берутся значения
     * @param[in] len_dest_sz Количество элементов в dest
     * @param[in] func Функция-критерий
     * @return Новая длина массива src
     */
    size_t add_int(i32_t *ptr_src_i32, size_t start_sz, size_t max_len_src_sz, const i32_t *ptr_dest_i32, size_t len_dest_sz, PTR_FILTER_FUNC func);

    /*** Вложенное пространство имен для фильтрующих функций ***/
    namespace filter_func
    {
        /**
         * @brief Критерий: оценка от 4 и выше
         * @param[in] val_i32 Значение
         * @return 1 — если >= 4, 0 — иначе
         */
        int mark_positive(i32_t val_i32);
    }
}

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    i32_t marks_i32[100] = {3, 2, 5, 4, 3};
    i32_t ar_i32[20] = {0};
    size_t count_sz = 0, count_marks_sz = 5;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    i32_t val_i32 = 0;
    while (iss >> val_i32 && count_sz < 20)
    {
        ar_i32[count_sz++] = val_i32;
    }
    count_marks_sz = array_alg::add_int(marks_i32, count_marks_sz, 100, ar_i32, count_sz, array_alg::filter_func::mark_positive);
    for (size_t i = 0; i < count_marks_sz; ++i)
    {
        std::cout << marks_i32[i];
        if (i + 1 < count_marks_sz)
            std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}

/*** Function Implementation ***/
size_t array_alg::add_int(i32_t *ptr_src_i32, size_t start_sz, size_t max_len_src_sz, const i32_t *ptr_dest_i32, size_t len_dest_sz, PTR_FILTER_FUNC func)
{
    size_t write_idx_sz = start_sz;
    for (size_t i = 0; i < len_dest_sz && write_idx_sz < max_len_src_sz; ++i)
    {
        if (func(ptr_dest_i32[i]))
        {
            ptr_src_i32[write_idx_sz++] = ptr_dest_i32[i];
        }
    }
    return write_idx_sz;
}

int array_alg::filter_func::mark_positive(i32_t val_i32)
{
    return (val_i32 >= 4);
}
