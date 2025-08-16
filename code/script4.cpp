/**********************************************************************
 * @file script4.cpp
 * @brief Заполнение и вывод матрицы из входного потока
 * @version 1.0
 * @date 2025-08-15
 **********************************************************************/

/*** Libraries ***/
#include "emb_style_cpp_en.h"
#include <iostream>

/*** Typedefs ***/
using i16_t = short;

/*** Constants ***/
constexpr size_t MATRIX_SIZE = 4;

/*** Function Prototypes ***/
/**
 * @brief Считывает числа из входного потока и заполняет матрицу
 * @param arr_matrix_i16 Матрица для заполнения
 * @param matrix_size Размер матрицы
 */
void fill_matrix(i16_t arr_matrix_i16[MATRIX_SIZE][MATRIX_SIZE], size_t matrix_size);

/**
 * @brief Выводит матрицу в консоль в виде таблицы
 * @param arr_matrix_i16 Матрица для вывода
 * @param matrix_size Размер матрицы
 */
void print_matrix(const i16_t arr_matrix_i16[MATRIX_SIZE][MATRIX_SIZE], size_t matrix_size);

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    i16_t arr_matrix_i16[MATRIX_SIZE][MATRIX_SIZE] = {0};
    fill_matrix(arr_matrix_i16, MATRIX_SIZE);
    print_matrix(arr_matrix_i16, MATRIX_SIZE);
    return 0;
}

/*** Function Implementation ***/

void fill_matrix(i16_t arr_matrix_i16[MATRIX_SIZE][MATRIX_SIZE], size_t matrix_size)
{
    size_t row = 0, col = 0;
    i16_t val_i16;
    while (std::cin >> val_i16)
    {
        arr_matrix_i16[row][col] = val_i16;
        ++col;
        if (col == matrix_size)
        {
            col = 0;
            ++row;
        }
        if (row == matrix_size)
        {
            break;
        }
    }
}

void print_matrix(const i16_t arr_matrix_i16[MATRIX_SIZE][MATRIX_SIZE], size_t matrix_size)
{
    for (size_t row = 0; row < matrix_size; ++row)
    {
        for (size_t col = 0; col < matrix_size; ++col)
        {
            std::cout << arr_matrix_i16[row][col];
            if (col + 1 < matrix_size)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}
