/**********************************************************************
 * @file    script5.cpp
 * @brief   Read up to max_size_ar integers with any non-digit separator and print (Stepik 9.3.6)
 * @version 1.0
 * @date    2025-08-04
 *
 * @note    Embedded C++ style
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <cctype>

/*** Constants ***/
enum
{
    max_size_ar = 20
};

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Считывает не более max_size_ar целых чисел с любым нечисловым разделителем, выводит их
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    int data_arr_i32[max_size_ar];
    int count_i32 = 0;
    char ch;
    int num_i32;
    while (count_i32 < max_size_ar && std::cin >> num_i32)
    {
        data_arr_i32[count_i32++] = num_i32;
        ch = std::cin.peek();
        if (!std::isdigit(ch) && !std::isspace(ch) && ch != EOF)
        {
            std::cin.get(); // consume separator
        }
    }
    for (int i = 0; i < count_i32; ++i)
    {
        if (i > 0)
        {
            std::cout << " ";
        }
        std::cout << data_arr_i32[i];
    }
    std::cout << std::endl;
    return 0;
}
