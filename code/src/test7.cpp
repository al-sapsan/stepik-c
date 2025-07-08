/**
 * @file duplicate_negatives.cpp
 * @brief Дублирование отрицательных элементов массива
 *
 * Программа создает массив, заполняет его случайными числами от -5 до 5,
 * дублирует каждый отрицательный элемент и выводит результат.
 */

#include <iostream>
#include <cstdlib>
#include <stdint.h>

/*** Пользовательские типы ***/
typedef int16_t i16_t;
typedef uint8_t u8_t;

/*** Прототипы функций ***/

/**
 * @brief Создает динамический массив
 * @param l_size_i16 Размер массива
 * @return Указатель на созданный массив
 */
i16_t *create_array(i16_t l_size_i16);

/**
 * @brief Заполняет массив случайными числами от -5 до 5
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
 * @brief Подсчитывает количество отрицательных элементов в массиве
 * @param l_arr_i16 Указатель на массив
 * @param l_size_i16 Размер массива
 * @return Количество отрицательных элементов
 */
i16_t count_negatives(const i16_t *l_arr_i16, i16_t l_size_i16);

/**
 * @brief Создает новый массив с дублированием отрицательных элементов
 * @param l_arr_i16 Указатель на исходный массив
 * @param l_size_i16 Размер исходного массива
 * @param l_new_size_i16 Размер нового массива
 * @return Указатель на новый массив
 */
i16_t *duplicate_negatives(const i16_t *l_arr_i16, i16_t l_size_i16, i16_t l_new_size_i16);

/*** Главная функция ***/
int main()
{
    i16_t l_size_i16 = 0;
    i16_t l_seed_i16 = 0;

    std::cin >> l_size_i16 >> l_seed_i16;

    i16_t *l_arr_i16 = create_array(l_size_i16);
    fill_array(l_arr_i16, l_size_i16, l_seed_i16);

    print_array(l_arr_i16, l_size_i16);

    i16_t l_cnt_neg_i16 = count_negatives(l_arr_i16, l_size_i16);
    i16_t l_new_size_i16 = l_size_i16 + l_cnt_neg_i16;

    i16_t *l_new_arr_i16 = duplicate_negatives(l_arr_i16, l_size_i16, l_new_size_i16);
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
        l_arr_i16[l_idx_i16] = std::rand() % 11 - 5; // [-5, 5]
    }
}

void print_array(const i16_t *l_arr_i16, i16_t l_size_i16)
{
    for (i16_t l_idx_i16 = 0; l_idx_i16 < l_size_i16; ++l_idx_i16)
    {
        std::cout << l_arr_i16[l_idx_i16] << " ";
    }
    std::cout << std::endl;
}

i16_t count_negatives(const i16_t *l_arr_i16, i16_t l_size_i16)
{
    i16_t l_cnt_i16 = 0;
    for (i16_t l_idx_i16 = 0; l_idx_i16 < l_size_i16; ++l_idx_i16)
    {
        if (l_arr_i16[l_idx_i16] < 0)
        {
            ++l_cnt_i16;
        }
    }
    return l_cnt_i16;
}

i16_t *duplicate_negatives(const i16_t *l_arr_i16, i16_t l_size_i16, i16_t l_new_size_i16)
{
    i16_t *l_new_arr_i16 = new i16_t[l_new_size_i16];
    i16_t l_idx_new_i16 = 0;

    for (i16_t l_idx_old_i16 = 0; l_idx_old_i16 < l_size_i16; ++l_idx_old_i16)
    {
        l_new_arr_i16[l_idx_new_i16++] = l_arr_i16[l_idx_old_i16];
        if (l_arr_i16[l_idx_old_i16] < 0)
        {
            l_new_arr_i16[l_idx_new_i16++] = l_arr_i16[l_idx_old_i16];
        }
    }

    return l_new_arr_i16;
}