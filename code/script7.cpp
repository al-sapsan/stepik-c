/**********************************************************************
 * @file script7.cpp
 * @brief box struct with constructors and dynamic array allocation
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-29
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Typedefs ***/
typedef unsigned short u16_t;

/*** Struct Definition ***/
struct box
{
    u16_t a, b, c;

    /*** Struct Constructors ***/
    /**
     * @brief Конструктор по умолчанию
     * @details Инициализирует поля нулями, выводит "Empty box"
     */
    box() : a(0), b(0), c(0)
    {
        std::cout << "Empty box" << std::endl;
    }
    /**
     * @brief Конструктор с параметрами
     * @param[in] a, b, c Значения сторон
     * @details Инициализирует поля и выводит "Box: a, b, c"
     */
    box(u16_t a, u16_t b, u16_t c) : a(a), b(b), c(c)
    {
        std::cout << "Box: " << a << ", " << b << ", " << c << std::endl;
    }
};

/*** Main Function ***/
int main(void)
{
    box *ar_box = new box[5]{
        box(1, 2, 3),
        box(6, 2, 1),
        box(0, 0, 0),
        box(11, 13, 19),
        box(23, 5, 7)};
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        delete[] ar_box;
    return 0;
}
