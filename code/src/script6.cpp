/**
 * @file truncate_after_last_max.cpp
 * @brief Обрезание массива после последнего максимального элемента
 *
 * Программа создаёт массив, заполняет его случайными числами от -10 до 10,
 * находит индекс последнего максимального элемента и выводит массив,
 * усечённый после него.
 */

#include <iostream>
#include <cstdlib>
#include <climits>
#include <stdint.h>

/*** Пользовательские типы ***/
typedef int16_t i16_t;
typedef uint8_t u8_t;

/*** Прототипы функций ***/

/**
 * @brief Создаёт динамический массив
 * @param l_size_i16 Размер массива
 * @return Указатель на массив
 */
i16_t *create_array(i16_t l_size_i16);

/**
 * @brief Заполняет массив случайными числами от -10 до 10
 * @param l_arr_i16 Указатель на массив
 * @param l_size_i16 Размер массива
 * @param l_seed_i16 Значение инициализации генератора случайных чисел
 */
void fill_array(i16_t *l_arr_i16, i16_t l_size_i16, i16_t l_seed_i16);

/**
 * @brief Печатает массив
 * @param l_arr_i16 Указатель на массив
 * @param l_size_i16 Размер массива
 */
void print_array(const i16_t *l_arr_i16, i16_t l_size_i16);

/**
 * @brief Возвращает индекс последнего максимального элемента массива
 * @param l_arr_i16 Указатель на массив
 * @param l_size_i16 Размер массива
 * @return Индекс последнего максимума
 */
i16_t find_last_max_index(const i16_t *l_arr_i16, i16_t l_size_i16);

/**
 * @brief Создаёт усечённый массив до указанного размера
 * @param l_arr_i16 Указатель на исходный массив
 * @param l_new_size_i16 Новый размер массива
 * @return Новый массив
 */
i16_t *truncate_array(const i16_t *l_arr_i16, i16_t l_new_size_i16);

/*** Главная функция ***/

int main()
{
    i16_t l_size_i16 = 0;
    i16_t l_seed_i16 = 0;

    std::cin >> l_size_i16 >> l_seed_i16;

    i16_t *l_arr_i16 = create_array(l_size_i16);
    fill_array(l_arr_i16, l_size_i16, l_seed_i16);

    print_array(l_arr_i16, l_size_i16);

    i16_t l_idx_last_max_i16 = find_last_max_index(l_arr_i16, l_size_i16);
    i16_t l_new_size_i16 = l_idx_last_max_i16 + 1;

    i16_t *l_new_arr_i16 = truncate_array(l_arr_i16, l_new_size_i16);
    print_array(l_new_arr_i16, l_new_size_i16);

    delete[] l_arr_i16;
    delete[] l_new_arr_i16;

    return 0;
}

/*** Реализация функций ***/

i16_t *create_array(i16_t l_size_i16)
{
    return new i16_t[l_size_i16];
}

void fill_array(i16_t *l_arr_i16, i16_t l_size_i16, i16_t l_seed_i16)
{
    std::srand(static_cast<unsigned>(l_seed_i16));
    for (i16_t l_idx_i16 = 0; l_idx_i16 < l_size_i16; ++l_idx_i16)
    {
        l_arr_i16[l_idx_i16] = -10 + std::rand() % 21; // [-10, 10]
    }
}

void print_array(const i16_t *l_arr_i16, i16_t l_size_i16)
{
    for (i16_t l_idx_i16 = 0; l_idx_i16 < l_size_i16; ++l_idx_i16)
    {
        std::cout << l_arr_i16[l_idx_i16] << " ";
    }
    std::cout << "\n";
}

i16_t find_last_max_index(const i16_t *l_arr_i16, i16_t l_size_i16)
{
    i16_t l_max_i16 = INT16_MIN;
    i16_t l_idx_last_i16 = 0;

    for (i16_t l_idx_i16 = 0; l_idx_i16 < l_size_i16; ++l_idx_i16)
    {
        if (l_arr_i16[l_idx_i16] >= l_max_i16)
        {
            l_max_i16 = l_arr_i16[l_idx_i16];
            l_idx_last_i16 = l_idx_i16;
        }
    }

    return l_idx_last_i16;
}

i16_t *truncate_array(const i16_t *l_arr_i16, i16_t l_new_size_i16)
{
    i16_t *l_new_arr_i16 = new i16_t[l_new_size_i16];
    for (i16_t l_idx_i16 = 0; l_idx_i16 < l_new_size_i16; ++l_idx_i16)
    {
        l_new_arr_i16[l_idx_i16] = l_arr_i16[l_idx_i16];
    }
    return l_new_arr_i16;
}
