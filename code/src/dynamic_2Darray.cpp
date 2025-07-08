/**
 * @file random_matrix.cpp
 * @brief Генерация и обработка матрицы случайных чисел
 *
 * @details Программа создает матрицу заданного размера, заполняет ее случайными
 * числами от -5 до 5, выводит матрицу и находит максимальные элементы в каждой строке.
 */

#include <iostream>
#include <cstdlib>
#include <stdint.h>

using namespace std;

/* --- Типы --- */
typedef int16_t i16_t;
typedef uint16_t u16_t;

/* --- Прототипы функций --- */
i16_t **create_matrix(i16_t rows, i16_t cols);
void fill_matrix(i16_t **matrix, i16_t rows, i16_t cols, i16_t seed);
void print_matrix(i16_t **matrix, i16_t rows, i16_t cols);
void find_row_maxima(i16_t **matrix, i16_t rows, i16_t cols, i16_t *max_vals);
void free_matrix(i16_t **matrix, i16_t rows);

/* --- main --- */
int main(void) //
{
    i16_t l_rows_i16, l_cols_i16, l_seed_i16;
    cin >> l_rows_i16 >> l_cols_i16 >> l_seed_i16;

    i16_t **l_matrix_ptr = create_matrix(l_rows_i16, l_cols_i16);

    fill_matrix(l_matrix_ptr, l_rows_i16, l_cols_i16, l_seed_i16);

    print_matrix(l_matrix_ptr, l_rows_i16, l_cols_i16);

    i16_t *l_max_vals_ptr = new i16_t[l_rows_i16];
    find_row_maxima(l_matrix_ptr, l_rows_i16, l_cols_i16, l_max_vals_ptr);

    for (i16_t l_i = 0; l_i < l_rows_i16; ++l_i)
    {
        cout << l_max_vals_ptr[l_i] << " ";
    }
    cout << "\n";

    delete[] l_max_vals_ptr;
    free_matrix(l_matrix_ptr, l_rows_i16);

    return 0;
}

/* --- Реализация функций --- */

/**
 * @brief Выделяет память под матрицу размером rows x cols
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @return Указатель на матрицу
 */
i16_t **create_matrix(i16_t rows, i16_t cols)
{
    i16_t **l_matrix = new i16_t *[rows];
    for (i16_t l_i = 0; l_i < rows; ++l_i)
    {
        l_matrix[l_i] = new i16_t[cols];
    }
    return l_matrix;
}

/**
 * @brief Заполняет матрицу случайными числами от -5 до 5
 * @param matrix Указатель на матрицу
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @param seed Значение для инициализации генератора
 */
void fill_matrix(i16_t **matrix, i16_t rows, i16_t cols, i16_t seed)
{
    srand(static_cast<u16_t>(seed));
    for (i16_t l_i = 0; l_i < rows; ++l_i)
    {
        for (i16_t l_j = 0; l_j < cols; ++l_j)
        {
            matrix[l_i][l_j] = rand() % 11 - 5;
        }
    }
}

/**
 * @brief Печатает матрицу на экран
 * @param matrix Указатель на матрицу
 * @param rows Количество строк
 * @param cols Количество столбцов
 */
void print_matrix(i16_t **matrix, i16_t rows, i16_t cols)
{
    for (i16_t l_i = 0; l_i < rows; ++l_i)
    {
        for (i16_t l_j = 0; l_j < cols; ++l_j)
        {
            cout << matrix[l_i][l_j] << "\t";
        }
        cout << "\n";
    }
}

/**
 * @brief Находит максимальные значения в каждой строке
 * @param matrix Указатель на матрицу
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @param max_vals Массив, в который записываются максимумы
 */
void find_row_maxima(i16_t **matrix, i16_t rows, i16_t cols, i16_t *max_vals)
{
    for (i16_t l_i = 0; l_i < rows; ++l_i)
    {
        max_vals[l_i] = matrix[l_i][0];
        for (i16_t l_j = 1; l_j < cols; ++l_j)
        {
            if (matrix[l_i][l_j] > max_vals[l_i])
            {
                max_vals[l_i] = matrix[l_i][l_j];
            }
        }
    }
}

/**
 * @brief Освобождает память, выделенную под матрицу
 * @param matrix Указатель на матрицу
 * @param rows Количество строк
 */
void free_matrix(i16_t **matrix, i16_t rows)
{
    for (i16_t l_i = 0; l_i < rows; ++l_i)
    {
        delete[] matrix[l_i];
    }
    delete[] matrix;
}
