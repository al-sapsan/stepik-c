/**
 * @file array_filter.cpp
 * @brief Фильтрация массива: элементы, превышающие порог
 *
 * Программа создает массив, заполняет его пользовательскими значениями,
 * подсчитывает количество элементов, превышающих заданный порог, и
 * создает новый массив с этими элементами.
 */

#include <iostream>
#include <stdint.h>

/*** Прототипы функций ***/

/**
 * @brief Создаёт массив заданного размера
 *
 * @param size Размер массива
 * @return Указатель на выделенный массив
 */
int16_t *create_array(int16_t size);

/**
 * @brief Заполняет массив значениями с клавиатуры
 *
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void fill_array(int16_t *arr, int16_t size);

/**
 * @brief Подсчитывает количество элементов, превышающих или равных порогу
 *
 * @param arr Указатель на массив
 * @param size Размер массива
 * @param threshold Пороговое значение
 * @return Количество подходящих элементов
 */
int16_t count_elements_above_threshold(int16_t *arr, int16_t size, int16_t threshold);

/**
 * @brief Фильтрует массив по порогу
 *
 * @param arr Указатель на исходный массив
 * @param size Размер исходного массива
 * @param threshold Порог
 * @param new_size Размер нового массива (должен быть рассчитан заранее)
 * @return Указатель на новый массив, содержащий только подходящие элементы
 */
int16_t *filter_array(int16_t *arr, int16_t size, int16_t threshold, int16_t new_size);

/**
 * @brief Печатает массив в консоль
 *
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void print_array(const int16_t *arr, int16_t size);

/*** Главная функция ***/

int main()
{
    int16_t l_size = 0;
    std::cin >> l_size;

    int16_t *l_arr = create_array(l_size);
    fill_array(l_arr, l_size);

    int16_t l_threshold = 0;
    std::cin >> l_threshold;

    int16_t l_new_size = count_elements_above_threshold(l_arr, l_size, l_threshold);
    int16_t *l_filtered = filter_array(l_arr, l_size, l_threshold, l_new_size);

    print_array(l_filtered, l_new_size);

    delete[] l_arr;
    delete[] l_filtered;

    return 0;
}

/*** Реализация функций ***/

int16_t *create_array(int16_t size)
{
    return new int16_t[size];
}

void fill_array(int16_t *arr, int16_t size)
{
    for (int16_t i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
}

int16_t count_elements_above_threshold(int16_t *arr, int16_t size, int16_t threshold)
{
    int16_t l_count = 0;
    for (int16_t i = 0; i < size; ++i)
    {
        if (arr[i] >= threshold)
        {
            ++l_count;
        }
    }
    return l_count;
}

int16_t *filter_array(int16_t *arr, int16_t size, int16_t threshold, int16_t new_size)
{
    int16_t *l_new_arr = new int16_t[new_size];
    int16_t l_index = 0;

    for (int16_t i = 0; i < size; ++i)
    {
        if (arr[i] >= threshold)
        {
            l_new_arr[l_index++] = arr[i];
        }
    }

    return l_new_arr;
}

void print_array(const int16_t *arr, int16_t size)
{
    for (int16_t i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
