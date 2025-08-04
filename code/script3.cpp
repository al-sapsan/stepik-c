/**********************************************************************
 * @file    script3.cpp
 * @brief   Print numbers divisible by 3 in range [a; b] (Stepik 9.3.4)
 * @version 1.0
 * @date
 *
 * @note    Embedded C++ style
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Считывает два числа, выводит все числа диапазона [a; b], кратные 3
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    int a_i32, b_i32;
    std::cin >> a_i32 >> b_i32;
    bool first_b = true;
    for (int i = a_i32; i <= b_i32; ++i)
    {
        if (i % 3 == 0)
        {
            if (!first_b)
            {
                std::cout << " ";
            }
            else
            {
                first_b = false;
            }
            std::cout << i;
        }
    }
    std::cout << std::endl;
    return 0;
}
