/**********************************************************************
 * @file script1.cpp
 * @brief Класс Vector3D, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-18
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <cmath>

/*** Class Definition ***/
/**
 * @brief Класс Vector3D: трёхмерный вектор
 */
class Vector3D
{
public:
    /**
     * @brief Конструктор
     * @param[in] a x
     * @param[in] b y
     * @param[in] c z
     */
    Vector3D(int a = 0, int b = 0, int c = 0);
    /**
     * @brief Установить значения
     * @param[in] a x
     * @param[in] b y
     * @param[in] c z
     */
    void set_data(int a, int b, int c);
    /**
     * @brief Оператор доступа по индексу
     * @param[in] idx индекс (0-x, 1-y, 2-z)
     * @return int&
     */
    int &operator[](size_t idx);
    /**
     * @brief Оператор доступа по индексу (const)
     * @param[in] idx индекс (0-x, 1-y, 2-z)
     * @return int
     */
    int operator[](size_t idx) const;
    /**
     * @brief Оператор преобразования к double (евклидово расстояние)
     * @return double
     */
    operator double() const;

private:
    int x{0}, y{0}, z{0};
};

/*** Methods Implementation ***/
Vector3D::Vector3D(int a, int b, int c) : x(a), y(b), z(c) {}
void Vector3D::set_data(int a, int b, int c)
{
    x = a;
    y = b;
    z = c;
}
int &Vector3D::operator[](size_t idx)
{
    if (idx == 0)
        return x;
    if (idx == 1)
        return y;
    return z;
}
int Vector3D::operator[](size_t idx) const
{
    if (idx == 0)
        return x;
    if (idx == 1)
        return y;
    return z;
}
Vector3D::operator double() const
{
    return std::sqrt(static_cast<double>(x * x + y * y + z * z));
}
