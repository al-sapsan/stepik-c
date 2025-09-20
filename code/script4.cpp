/**********************************************************************
 * @file script4.cpp
 * @brief Класс Line, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-19
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс Line: отрезок
 */
class Line
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    Line();
    /**
     * @brief Конструктор с координатами
     * @param[in] x0
     * @param[in] y0
     * @param[in] x1
     * @param[in] y1
     */
    Line(short x0, short y0, short x1, short y1);
    /**
     * @brief Оператор присваивания (копирует только координаты)
     * @param[in] other
     * @return Line&
     */
    Line &operator=(const Line &other);
    /**
     * @brief Оператор += (координаты)
     * @param[in] other
     * @return Line&
     */
    Line &operator+=(const Line &other);
    /**
     * @brief Оператор -= (координаты)
     * @param[in] other
     * @return Line&
     */
    Line &operator-=(const Line &other);
    /**
     * @brief Оператор *= (координаты)
     * @param[in] other
     * @return Line&
     */
    Line &operator*=(const Line &other);
    /**
     * @brief Оператор + (координаты)
     * @param[in] other
     * @return Line
     */
    Line operator+(const Line &other) const;
    /**
     * @brief Получить цвет
     * @return int
     */
    int get_color() const;
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
     * @brief Установить цвет
     * @param[in] color
     */
    void set_color(int color);

private:
    short x0{0}, y0{0}, x1{0}, y1{0};
    int color{0};
};

/*** Methods Implementation ***/
Line::Line() : x0(0), y0(0), x1(0), y1(0), color(0) {}
Line::Line(short x0_, short y0_, short x1_, short y1_)
    : x0(x0_), y0(y0_), x1(x1_), y1(y1_), color(0) {}
Line &Line::operator=(const Line &other)
{
    if (this != &other)
    {
        x0 = other.x0;
        y0 = other.y0;
        x1 = other.x1;
        y1 = other.y1;
        // color не копируется
    }
    return *this;
}
Line &Line::operator+=(const Line &other)
{
    x0 += other.x0;
    y0 += other.y0;
    x1 += other.x1;
    y1 += other.y1;
    return *this;
}
Line &Line::operator-=(const Line &other)
{
    x0 -= other.x0;
    y0 -= other.y0;
    x1 -= other.x1;
    y1 -= other.y1;
    return *this;
}
Line &Line::operator*=(const Line &other)
{
    x0 *= other.x0;
    y0 *= other.y0;
    x1 *= other.x1;
    y1 *= other.y1;
    return *this;
}
Line Line::operator+(const Line &other) const
{
    Line res(*this);
    res += other;
    return res;
}
int Line::get_color() const
{
    return color;
}
void Line::get_coords(short &x0_, short &y0_, short &x1_, short &y1_) const
{
    x0_ = x0;
    y0_ = y0;
    x1_ = x1;
    y1_ = y1;
}
void Line::set_coords(short x0_, short y0_, short x1_, short y1_)
{
    x0 = x0_;
    y0 = y0_;
    x1 = x1_;
    y1 = y1_;
}
void Line::set_color(int color_)
{
    color = color_;
}
