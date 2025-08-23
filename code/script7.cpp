/**********************************************************************
 * @file script7.cpp
 * @brief Replace get_line with lambda (embedded C++ style)
 * @version 1.0 (Stepik exercise)
 * @date 2025-08-23
 **********************************************************************/

#include <iostream>
#include <string>

/**
 * @brief  Точка входа в программу
 * @return Код завершения (0 — успешно, 1 — ошибка памяти)
 */
/*** Main Function ***/
int main(void)
{
    char arr_str_u8[100];
    /**
     * @brief Лямбда-выражение для чтения строки из консоли
     * @param Нет параметров (захват массива arr_str_u8)
     * @return Нет возвращаемого значения (модифицирует arr_str_u8)
     */
    auto gl = [&arr_str_u8]()
    {
        std::string line;
        std::getline(std::cin, line);
        size_t i = 0;
        for (; i < line.length() && i < sizeof(arr_str_u8) - 1; ++i)
            arr_str_u8[i] = line[i];
        arr_str_u8[i] = '\0';
    };
    gl();
    std::cout << arr_str_u8 << std::endl;
    return 0;
}