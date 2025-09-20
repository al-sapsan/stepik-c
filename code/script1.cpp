/**********************************************************************
 * @file script1.cpp
 * @brief Класс Distance, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-19
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс Distance: расстояние
 */
class Distance
{
public:
    /**
     * @brief Конструктор
     * @param[in] d расстояние
     */
    Distance(int d);
    /**
     * @brief Оператор +=
     * @param[in] val
     * @return Distance&
     */
    Distance &operator+=(int val);
    /**
     * @brief Оператор -=
     * @param[in] val
     * @return Distance&
     */
    Distance &operator-=(int val);
    /**
     * @brief Оператор *=
     * @param[in] val
     * @return Distance&
     */
    Distance &operator*=(int val);
    /**
     * @brief Оператор /=
     * @param[in] val
     * @return Distance&
     */
    Distance &operator/=(int val);
    /**
     * @brief Оператор преобразования к int
     * @return int
     */
    operator int() const;

private:
    int dist{0};
};

/*** Methods Implementation ***/
Distance::Distance(int d) : dist(d) {}
Distance &Distance::operator+=(int val)
{
    dist += val;
    return *this;
}
Distance &Distance::operator-=(int val)
{
    dist -= val;
    return *this;
}
Distance &Distance::operator*=(int val)
{
    dist *= val;
    return *this;
}
Distance &Distance::operator/=(int val)
{
    if (val != 0)
        dist /= val;
    return *this;
}
Distance::operator int() const
{
    return dist;
}
