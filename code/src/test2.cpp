/***
 * @file test2.cpp
 * @brief Динамический двумерный массив: заполнение, поиск строки с максимумом, дублирование строки
 * @version 1.4
 * @date 2025-07-07
 */

// === Core ===
#include <iostream>
#include <cstdlib>
#include <cstdint>

/*** Типы данных ***/
typedef int16_t i16_t;
typedef uint16_t u16_t;
typedef uint32_t u32_t;

/*** Макросы безопасности ***/
#define CHECK_NULL(ptr) \
    do { \
        if (!(ptr)) { \
            std::cerr << "Ошибка выделения памяти!" << std::endl; \
            std::exit(1); \
        } \
    } while (0)

/*** 🧩 Прототипы функций ***/

/**
 * @brief Создаёт динамический двумерный массив
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @return Указатель на массив указателей
 */
i16_t** create_2d_array(i16_t rows, i16_t cols);

/**
 * @brief Освобождает память, занятую двумерным массивом
 * @param arr Указатель на массив указателей
 * @param rows Количество строк
 */
void free_2d_array(i16_t** arr, i16_t rows);

/**
 * @brief Заполняет двумерный массив случайными числами от 1 до 10
 * @param arr Указатель на массив указателей
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @param seed Начальное значение генератора случайных чисел
 */
void fill_2d_array_random(i16_t** arr, i16_t rows, i16_t cols, i16_t seed);

/**
 * @brief Печатает двумерный массив в виде таблицы с табуляцией
 * @param arr Указатель на массив указателей
 * @param rows Количество строк
 * @param cols Количество столбцов
 */
void print_2d_array(i16_t** arr, i16_t rows, i16_t cols);

/**
 * @brief Находит индекс строки, содержащей первый максимальный элемент массива
 * @param arr Указатель на массив указателей
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @return Индекс строки с первым максимальным элементом
 */
i16_t find_row_of_first_max(i16_t** arr, i16_t rows, i16_t cols);

/**
 * @brief Дублирует строку массива (вставляет копию после неё)
 * @param arr Указатель на массив указателей (старый массив будет удалён)
 * @param rows [in,out] Количество строк (будет увеличено)
 * @param cols Количество столбцов
 * @param row_to_duplicate Индекс строки для дублирования
 * @return Новый указатель на массив указателей
 */
i16_t** duplicate_row(i16_t** arr, i16_t& rows, i16_t cols, i16_t row_to_duplicate);

/***
 * @brief Точка входа. Формирует, обрабатывает и выводит двумерный массив по заданию
 * @return 0 при успешном завершении
 */
int main(void)
{
    i16_t rows = 0, cols = 0, seed = 0;
    std::cin >> rows >> cols >> seed;
    i16_t** arr = create_2d_array(rows, cols);
    CHECK_NULL(arr);
    fill_2d_array_random(arr, rows, cols, seed);
    print_2d_array(arr, rows, cols);
    std::cout << std::endl;
    i16_t row_max = find_row_of_first_max(arr, rows, cols);
    i16_t** arr2 = duplicate_row(arr, rows, cols, row_max);
    CHECK_NULL(arr2);
    arr = arr2;
    print_2d_array(arr, rows, cols);
    free_2d_array(arr, rows);
    return 0;
}

/*** 🧩 Реализация функций ***/
i16_t** create_2d_array(i16_t rows, i16_t cols)
{
    i16_t** arr = new (std::nothrow) i16_t*[rows];
    CHECK_NULL(arr);
    for (i16_t i = 0; i < rows; ++i)
    {
        arr[i] = new (std::nothrow) i16_t[cols];
        CHECK_NULL(arr[i]);
    }
    return arr;
}

void free_2d_array(i16_t** arr, i16_t rows)
{
    if (!arr) return;
    for (i16_t i = 0; i < rows; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

void fill_2d_array_random(i16_t** arr, i16_t rows, i16_t cols, i16_t seed)
{
    std::srand(static_cast<u32_t>(seed));
    for (i16_t i = 0; i < rows; ++i)
    {
        for (i16_t j = 0; j < cols; ++j)
        {
            arr[i][j] = static_cast<i16_t>(std::rand() % 10 + 1);
        }
    }
}

void print_2d_array(i16_t** arr, i16_t rows, i16_t cols)
{
    for (i16_t i = 0; i < rows; ++i)
    {
        for (i16_t j = 0; j < cols; ++j)
        {
            std::cout << arr[i][j] << '\t';
        }
        std::cout << '\n';
    }
}

i16_t find_row_of_first_max(i16_t** arr, i16_t rows, i16_t cols)
{
    i16_t max_val = arr[0][0];
    i16_t max_row = 0;
    for (i16_t i = 0; i < rows; ++i)
    {
        for (i16_t j = 0; j < cols; ++j)
        {
            if (arr[i][j] > max_val)
            {
                max_val = arr[i][j];
                max_row = i;
            }
        }
    }
    return max_row;
}

i16_t** duplicate_row(i16_t** arr, i16_t& rows, i16_t cols, i16_t row_to_duplicate)
{
    i16_t** new_arr = new (std::nothrow) i16_t*[rows + 1];
    CHECK_NULL(new_arr);
    i16_t k = 0;
    for (i16_t i = 0; i < rows + 1; ++i)
    {
        if (i == row_to_duplicate + 1)
        {
            new_arr[i] = new (std::nothrow) i16_t[cols];
            CHECK_NULL(new_arr[i]);
            for (i16_t j = 0; j < cols; ++j)
            {
                new_arr[i][j] = arr[row_to_duplicate][j];
            }
        }
        else
        {
            new_arr[i] = arr[k++];
        }
    }
    delete[] arr;
    ++rows;
    return new_arr;
}
