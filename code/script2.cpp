/**********************************************************************
 * @file    script2.cpp
 * @brief   Read two integers and print in format (Stepik 9.3.3)
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
 *         Считывает два целых числа из stdin, выводит их через точку с запятой
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    int first_i32, second_i32;
    std::cin >> first_i32 >> second_i32;
    std::cout << first_i32 << "; " << second_i32 << std::endl;
    return 0;
}
