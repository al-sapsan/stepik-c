/**********************************************************************
 * @file    script4.cpp
 * @brief   Read up to max_size_ar integers and print (Stepik 9.3.5)
 * @version 1.0
 * @date
 *
 * @note    Embedded C++ style
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Constants ***/
enum
{
    max_size_ar = 20
};

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Считывает не более max_size_ar целых чисел, выводит их
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    int data_arr_i32[max_size_ar];
    int count_i32 = 0;
    while (count_i32 < max_size_ar && std::cin >> data_arr_i32[count_i32])
    {
        count_i32++;
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
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}
