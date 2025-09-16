/**********************************************************************
 * @file script1.cpp
 * @brief Класс ColorRGB: оператор сложения, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-15
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс ColorRGB: цвет в формате RGB, оператор сложения
 */
class ColorRGB
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    ColorRGB();
    /**
     * @brief Конструктор с параметрами
     * @param[in] r красный
     * @param[in] g зелёный
     * @param[in] b синий
     */
    ColorRGB(unsigned char r, unsigned char g, unsigned char b);
    /**
     * @brief Получить цвет в виде числа
     * @return unsigned
     */
    unsigned get_color() const;
    /**
     * @brief Оператор сложения (дружественный)
     * @param[in] c1 первый цвет
     * @param[in] c2 второй цвет
     * @return ColorRGB
     */
    friend ColorRGB operator+(const ColorRGB &c1, const ColorRGB &c2);

private:
    unsigned char m_r{0}, m_g{0}, m_b{0};
};

/*** Methods Implementation ***/
ColorRGB::ColorRGB() : m_r(0), m_g(0), m_b(0) {}
ColorRGB::ColorRGB(unsigned char r, unsigned char g, unsigned char b)
    : m_r(r), m_g(g), m_b(b) {}
unsigned ColorRGB::get_color() const
{
    return static_cast<unsigned>(m_r) + static_cast<unsigned>(m_g) * 256 + static_cast<unsigned>(m_b) * 65536;
}
ColorRGB operator+(const ColorRGB &c1, const ColorRGB &c2)
{
    unsigned r = static_cast<unsigned>(c1.m_r) + static_cast<unsigned>(c2.m_r);
    unsigned g = static_cast<unsigned>(c1.m_g) + static_cast<unsigned>(c2.m_g);
    unsigned b = static_cast<unsigned>(c1.m_b) + static_cast<unsigned>(c2.m_b);
    if (r > 255)
        r = 255;
    if (g > 255)
        g = 255;
    if (b > 255)
        b = 255;
    return ColorRGB(static_cast<unsigned char>(r), static_cast<unsigned char>(g), static_cast<unsigned char>(b));
}
