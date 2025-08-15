/**********************************************************************
 * @file script9.cpp
 * @brief Проверка четности всех введённых чисел до 0
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-15
 **********************************************************************/

#include <iostream>

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    bool fl_even_b = true;
    int val_i32 = 0;
    do
    {
        std::cin >> val_i32;
        if (val_i32 != 0)
        {
            fl_even_b &= (val_i32 % 2 == 0);
        }
    } while (val_i32 != 0);
    std::cout << (fl_even_b ? "even" : "no") << std::endl;
    return 0;
}
