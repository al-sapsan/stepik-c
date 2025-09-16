/**********************************************************************
 * @file script7.cpp
 * @brief Класс Rectangle, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-16
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс Rectangle: прямоугольник
 */
class Rectangle
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    Rectangle();
    /**
     * @brief Конструктор с координатами
     * @param[in] x0 левый верхний x
     * @param[in] y0 левый верхний y
     * @param[in] x1 правый нижний x
     * @param[in] y1 правый нижний y
     */
    Rectangle(short x0, short y0, short x1, short y1);
    /**
     * @brief Оператор присваивания (копирует только координаты)
     * @param[in] other другой объект Rectangle
     * @return Rectangle&
     */
    Rectangle &operator=(const Rectangle &other);
    /**
     * @brief Получить цвет границы
     * @return int
     */
    int get_border_color() const;
    /**
     * @brief Получить цвет заливки
     * @return int
     */
    int get_fill_color() const;
    /**
     * @brief Получить координаты
     * @param[out] x0
     * @param[out] y0
     * @param[out] x1
     * @param[out] y1
     */
    void get_coords(short &x0, short &y0, short &x1, short &y1) const;
    /**
     * @brief Установить координаты
     * @param[in] x0
     * @param[in] y0
     * @param[in] x1
     * @param[in] y1
     */
    void set_coords(short x0, short y0, short x1, short y1);
    /**
     * @brief Установить цвет границы
     * @param[in] color
     */
    void set_border_color(int color);
    /**
     * @brief Установить цвет заливки
     * @param[in] color
     */
    void set_fill_color(int color);

private:
    short m_x0{0}, m_y0{0}, m_x1{0}, m_y1{0};
    int m_border_color{0};
    int m_fill_color{255};
};

/*** Methods Implementation ***/
Rectangle::Rectangle() : m_x0(0), m_y0(0), m_x1(0), m_y1(0), m_border_color(0), m_fill_color(255) {}
Rectangle::Rectangle(short x0, short y0, short x1, short y1)
    : m_x0(x0), m_y0(y0), m_x1(x1), m_y1(y1), m_border_color(0), m_fill_color(255) {}
Rectangle &Rectangle::operator=(const Rectangle &other)
{
    if (this != &other)
    {
        m_x0 = other.m_x0;
        m_y0 = other.m_y0;
        m_x1 = other.m_x1;
        m_y1 = other.m_y1;
        // Цвета не копируются
    }
    return *this;
}
int Rectangle::get_border_color() const
{
    return m_border_color;
}
int Rectangle::get_fill_color() const
{
    return m_fill_color;
}
void Rectangle::get_coords(short &x0, short &y0, short &x1, short &y1) const
{
    x0 = m_x0;
    y0 = m_y0;
    x1 = m_x1;
    y1 = m_y1;
}
void Rectangle::set_coords(short x0, short y0, short x1, short y1)
{
    m_x0 = x0;
    m_y0 = y0;
    m_x1 = x1;
    m_y1 = y1;
}
void Rectangle::set_border_color(int color)
{
    m_border_color = color;
}
void Rectangle::set_fill_color(int color)
{
    m_fill_color = color;
}
