/**********************************************************************
 * @file script7.cpp
 * @brief Класс Rectangle: оператор сложения, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-15
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс Rectangle: прямоугольник, оператор сложения
 */
class Rectangle
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    Rectangle();
    /**
     * @brief Конструктор с параметрами
     * @param[in] x0 x0
     * @param[in] y0 y0
     * @param[in] x1 x1
     * @param[in] y1 y1
     */
    Rectangle(int x0, int y0, int x1, int y1);
    /**
     * @brief Получить координаты
     * @param[out] x0 x0
     * @param[out] y0 y0
     * @param[out] x1 x1
     * @param[out] y1 y1
     */
    void get_coords(int &x0, int &y0, int &x1, int &y1) const;
    /**
     * @brief Установить координаты
     * @param[in] x0 x0
     * @param[in] y0 y0
     * @param[in] x1 x1
     * @param[in] y1 y1
     */
    void set_coords(int x0, int y0, int x1, int y1);
    /**
     * @brief Оператор сложения
     * @param[in] other другой прямоугольник
     * @return Rectangle
     */
    Rectangle operator+(const Rectangle &other) const;

private:
    int m_x0{0}, m_y0{0}, m_x1{0}, m_y1{0};
};

/*** Methods Implementation ***/
Rectangle::Rectangle() : m_x0(0), m_y0(0), m_x1(0), m_y1(0) {}
Rectangle::Rectangle(int x0, int y0, int x1, int y1)
    : m_x0(x0), m_y0(y0), m_x1(x1), m_y1(y1) {}
void Rectangle::get_coords(int &x0, int &y0, int &x1, int &y1) const
{
    x0 = m_x0;
    y0 = m_y0;
    x1 = m_x1;
    y1 = m_y1;
}
void Rectangle::set_coords(int x0, int y0, int x1, int y1)
{
    m_x0 = x0;
    m_y0 = y0;
    m_x1 = x1;
    m_y1 = y1;
}
Rectangle Rectangle::operator+(const Rectangle &other) const
{
    int nx0 = (m_x0 < other.m_x0) ? m_x0 : other.m_x0;
    int ny0 = (m_y0 < other.m_y0) ? m_y0 : other.m_y0;
    int nx1 = (m_x1 > other.m_x1) ? m_x1 : other.m_x1;
    int ny1 = (m_y1 > other.m_y1) ? m_y1 : other.m_y1;
    return Rectangle(nx0, ny0, nx1, ny1);
}

/*** Main Function ***/
int main(void)
{
    Rectangle rect_1(-5, 0, 10, 12);
    Rectangle rect_2(1, -2, 7, 14);
    Rectangle res = rect_1 + rect_2;

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

        return 0;
}
