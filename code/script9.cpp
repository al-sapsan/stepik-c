/**********************************************************************
 * @file script9.cpp
 * @brief Класс LineDouble, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-20
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс LineDouble: линия с координатами double
 */
class LineDouble
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    LineDouble();
    /**
     * @brief Конструктор с координатами
     * @param[in] a x0
     * @param[in] b y0
     * @param[in] c x1
     * @param[in] d y1
     */
    LineDouble(double a, double b, double c, double d);
    /**
     * @brief Установить координаты
     * @param[in] a x0
     * @param[in] b y0
     * @param[in] c x1
     * @param[in] d y1
     */
    void set_coords(double a, double b, double c, double d);
    /**
     * @brief Получить координаты
     * @param[out] a x0
     * @param[out] b y0
     * @param[out] c x1
     * @param[out] d y1
     */
    void get_coords(double &a, double &b, double &c, double &d) const;
    /**
     * @brief Оператор + (сложение координат)
     * @param[in] other
     * @return LineDouble
     */
    LineDouble operator+(const LineDouble &other) const;
    /**
     * @brief Оператор += (double)
     * @param[in] val
     * @return LineDouble&
     */
    LineDouble &operator+=(double val);
    /**
     * @brief Оператор -= (double)
     * @param[in] val
     * @return LineDouble&
     */
    LineDouble &operator-=(double val);
    /**
     * @brief Оператор += (LineDouble)
     * @param[in] other
     * @return LineDouble&
     */
    LineDouble &operator+=(const LineDouble &other);
    /**
     * @brief Оператор -= (LineDouble)
     * @param[in] other
     * @return LineDouble&
     */
    LineDouble &operator-=(const LineDouble &other);
    /**
     * @brief Оператор постфиксного инкремента
     * @return LineDouble (старое значение)
     */
    LineDouble operator++(int);
    /**
     * @brief Оператор префиксного инкремента
     * @return LineDouble&
     */
    LineDouble &operator++();
    /**
     * @brief Оператор постфиксного декремента
     * @return LineDouble (старое значение)
     */
    LineDouble operator--(int);
    /**
     * @brief Оператор префиксного декремента
     * @return LineDouble&
     */
    LineDouble &operator--();

private:
    double x0{0}, y0{0}, x1{0}, y1{0};
};

/*** Methods Implementation ***/
LineDouble::LineDouble() : x0(0), y0(0), x1(0), y1(0) {}
LineDouble::LineDouble(double a, double b, double c, double d) : x0(a), y0(b), x1(c), y1(d) {}
void LineDouble::set_coords(double a, double b, double c, double d)
{
    x0 = a;
    y0 = b;
    x1 = c;
    y1 = d;
}
void LineDouble::get_coords(double &a, double &b, double &c, double &d) const
{
    a = x0;
    b = y0;
    c = x1;
    d = y1;
}
LineDouble LineDouble::operator+(const LineDouble &other) const
{
    return LineDouble(x0 + other.x0, y0 + other.y0, x1 + other.x1, y1 + other.y1);
}
LineDouble &LineDouble::operator+=(double val)
{
    x0 += val;
    y0 += val;
    x1 += val;
    y1 += val;
    return *this;
}
LineDouble &LineDouble::operator-=(double val)
{
    x0 -= val;
    y0 -= val;
    x1 -= val;
    y1 -= val;
    return *this;
}
LineDouble &LineDouble::operator+=(const LineDouble &other)
{
    x0 += other.x0;
    y0 += other.y0;
    x1 += other.x1;
    y1 += other.y1;
    return *this;
}
LineDouble &LineDouble::operator-=(const LineDouble &other)
{
    x0 -= other.x0;
    y0 -= other.y0;
    x1 -= other.x1;
    y1 -= other.y1;
    return *this;
}
LineDouble LineDouble::operator++(int)
{
    LineDouble temp(*this);
    ++(*this);
    return temp;
}
LineDouble &LineDouble::operator++()
{
    x0 += 0.1;
    y0 += 0.1;
    x1 += 0.1;
    y1 += 0.1;
    return *this;
}
LineDouble LineDouble::operator--(int)
{
    LineDouble temp(*this);
    --(*this);
    return temp;
}
LineDouble &LineDouble::operator--()
{
    x0 -= 0.1;
    y0 -= 0.1;
    x1 -= 0.1;
    y1 -= 0.1;
    return *this;
}
