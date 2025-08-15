/**********************************************************************
 * @file script1.cpp
 * @brief Сортировка массива целых чисел с выбором направления (namespace array_alg)
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
     * @brief Тип сортировки массива
     */
    enum TYPE_SORT
    {
        sort_asc, ///< По возрастанию
        sort_desc ///< По убыванию
    };

    /**
     * @brief Сортирует массив целых чисел
     * @param[in,out] ptr_ar_i32 Массив для сортировки
     * @param[in] len_ar_sz Количество сортируемых элементов
     * @param[in] type Тип сортировки
     */
    void sorted_int(i32_t *ptr_ar_i32, size_t len_ar_sz, TYPE_SORT type);
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
    std::istringstream iss(line); ///< преобразует строку в поток для извлечения чисел.
    i32_t val_i32 = 0;            ///< Временная переменная для каждого числа
    while (iss >> val_i32 && len_sz < MAX_LEN_SZ)
    {
        arr_i32[len_sz++] = val_i32;
    }
    array_alg::sorted_int(arr_i32, len_sz, array_alg::sort_desc);
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
void array_alg::sorted_int(i32_t *ptr_ar_i32, size_t len_ar_sz, TYPE_SORT type)
{
    // обработка пустых или одноэлементных массивов
    if (len_ar_sz <= 1)
    {
        return;
    }

    bool swapped;
    for (size_t i = 0; i < len_ar_sz - 1; ++i)
    {
        swapped = false;
        for (size_t j = 0; j < len_ar_sz - i - 1; ++j)
        {
            bool should_swap = false;

            if (type == sort_asc)
            {
                should_swap = ptr_ar_i32[j] > ptr_ar_i32[j + 1];
            }
            else
            { // sort_desc
                should_swap = ptr_ar_i32[j] < ptr_ar_i32[j + 1];
            }

            if (should_swap)
            {
                // Swap elements
                i32_t tmp_i32 = ptr_ar_i32[j];
                ptr_ar_i32[j] = ptr_ar_i32[j + 1];
                ptr_ar_i32[j + 1] = tmp_i32;
                swapped = true;
            }
        }

        // If no swaps, array is sorted
        if (!swapped)
        {
            break;
        }
    }
}
