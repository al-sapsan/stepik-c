/**
 * @file    struct_union_hex.cpp
 * @brief   Выводит внутреннее представление double по байтам (hex)
 * @version 1.0
 * @date    2025-07-17
 */

#include <iostream>
#include <iomanip>
#include <cstdint>

/*** Types ***/
union DoubleBytes
{
    double value;
    uint8_t bytes[sizeof(double)];
};

/*** Main Function ***/
int main()
{
    DoubleBytes db;
    std::cin >> db.value;
    for (size_t i = 0; i < sizeof(double); ++i)
    {
        if (i > 0)
            std::cout << " ";
        std::cout << std::hex << std::setfill('0') << std::setw(2) << (int)db.bytes[i];
    }
    std::cout << std::endl;
    return 0;
}
