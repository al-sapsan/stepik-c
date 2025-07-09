/**
 * @file matrix_row_delete.cpp
 * @brief Удаление строки с максимальным минимальным элементом из матрицы
 *
 * Программа создает матрицу, заполняет её случайными числами от 1 до 10,
 * находит строку с максимальным среди минимальных элементов и удаляет её.
 */

#include <iostream>
#include <cstdlib>
#include <climits>
#include <cstdint>

/*** Типы данных ***/
typedef int16_t i16_t;

/**
 * @brief Создает двумерную матрицу
 * 
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @return Указатель на созданную матрицу
 */
i16_t** create_matrix(i16_t rows, i16_t cols);

/**
 * @brief Заполняет матрицу случайными числами от 1 до 10
 * 
 * @param matrix Указатель на матрицу
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @param seed Начальное значение генератора случайных чисел
 */
void fill_matrix(i16_t** matrix, i16_t rows, i16_t cols, i16_t seed);

/**
 * @brief Печатает матрицу на стандартный вывод
 * 
 * @param matrix Указатель на матрицу
 * @param rows Количество строк
 * @param cols Количество столбцов
 */
void print_matrix(i16_t** matrix, i16_t rows, i16_t cols);

/**
 * @brief Находит индекс строки с максимальным из минимальных элементов
 * 
 * @param matrix Указатель на матрицу
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @return Индекс строки, которую нужно удалить
 */
i16_t find_row_with_max_min(i16_t** matrix, i16_t rows, i16_t cols);

/**
 * @brief Удаляет строку из матрицы
 * 
 * @param matrix Указатель на исходную матрицу
 * @param rows Ссылка на количество строк (уменьшается на 1)
 * @param cols Количество столбцов
 * @param row_to_delete Индекс удаляемой строки
 * @return Указатель на новую матрицу без удалённой строки
 */
i16_t** delete_row(i16_t** matrix, i16_t& rows, i16_t cols, i16_t row_to_delete);

/**
 * @brief Главная функция
 * 
 * @return int Код завершения
 */
int main()
{
    i16_t l_rows = 0;
    i16_t l_cols = 0;
    i16_t l_seed = 0;

    std::cin >> l_rows >> l_cols >> l_seed;

    i16_t** l_matrix = create_matrix(l_rows, l_cols);
    fill_matrix(l_matrix, l_rows, l_cols, l_seed);

    print_matrix(l_matrix, l_rows, l_cols);
    std::cout << std::endl;

    i16_t l_row_to_delete = find_row_with_max_min(l_matrix, l_rows, l_cols);
    l_matrix = delete_row(l_matrix, l_rows, l_cols, l_row_to_delete);

    print_matrix(l_matrix, l_rows, l_cols);

    for (i16_t i = 0; i < l_rows; ++i)
    {
        delete[] l_matrix[i];
    }
    delete[] l_matrix;

    return 0;
}

i16_t** create_matrix(i16_t rows, i16_t cols)
{
    i16_t** matrix = new i16_t*[rows];
    for (i16_t i = 0; i < rows; ++i)
    {
        matrix[i] = new i16_t[cols];
    }
    return matrix;
}

void fill_matrix(i16_t** matrix, i16_t rows, i16_t cols, i16_t seed)
{
    std::srand(seed);
    for (i16_t i = 0; i < rows; ++i)
    {
        for (i16_t j = 0; j < cols; ++j)
        {
            matrix[i][j] = 1 + std::rand() % 10;
        }
    }
}

void print_matrix(i16_t** matrix, i16_t rows, i16_t cols)
{
    for (i16_t i = 0; i < rows; ++i)
    {
        for (i16_t j = 0; j < cols; ++j)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

i16_t find_row_with_max_min(i16_t** matrix, i16_t rows, i16_t cols)
{
    i16_t l_max_min = INT16_MIN;
    i16_t l_result_row = 0;

    for (i16_t i = 0; i < rows; ++i)
    {
        i16_t l_current_min = matrix[i][0];
        for (i16_t j = 1; j < cols; ++j)
        {
            if (matrix[i][j] < l_current_min)
            {
                l_current_min = matrix[i][j];
            }
        }

        if (l_current_min > l_max_min)
        {
            l_max_min = l_current_min;
            l_result_row = i;
        }
    }

    return l_result_row;
}

i16_t** delete_row(i16_t** matrix, i16_t& rows, i16_t cols, i16_t row_to_delete)
{
    i16_t** new_matrix = new i16_t*[rows - 1];

    i16_t l_new_row = 0;
    for (i16_t i = 0; i < rows; ++i)
    {
        if (i != row_to_delete)
        {
            new_matrix[l_new_row] = new i16_t[cols];
            for (i16_t j = 0; j < cols; ++j)
            {
                new_matrix[l_new_row][j] = matrix[i][j];
            }
            ++l_new_row;
        }
    }

    for (i16_t i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    --rows;
    return new_matrix;
}
