/**********************************************************************
 * @file script3.cpp
 * @brief Класс Distance и дружественные функции, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-15
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <iomanip>

/*** Class Definition ***/
/**
 * @brief Класс Distance: дистанция в миллиметрах
 */
class Distance
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    Distance();
    /**
     * @brief Конструктор с параметром
     * @param[in] value дистанция в мм
     */
    Distance(long value);
    /**
     * @brief Дружественная функция: установить дистанцию
     * @param[in,out] dst объект Distance
     * @param[in] value значение
     */
    friend void set_distance(Distance &dst, long value);
    /**
     * @brief Дружественная функция: получить дистанцию
     * @param[in] dst объект Distance
     * @return long
     */
    friend long get_distance(const Distance &dst);
    /**
     * @brief Дружественная функция: получить дистанцию в метрах
     * @param[in] dst объект Distance
     * @return double
     */
    friend double distance_to_meters(const Distance &dst);
    /**
     * @brief Оператор сложения Distance + Distance
     * @param[in] d1 первый объект
     * @param[in] d2 второй объект
     * @return Distance
     */
    friend Distance operator+(const Distance &d1, const Distance &d2);
    /**
     * @brief Оператор сложения Distance + long
     * @param[in] d объект Distance
     * @param[in] value миллиметры
     * @return Distance
     */
    friend Distance operator+(const Distance &d, long value);
    /**
     * @brief Оператор сложения long + Distance
     * @param[in] value миллиметры
     * @param[in] d объект Distance
     * @return Distance
     */
    friend Distance operator+(long value, const Distance &d);

private:
    long m_dist{0};
};

/*** Methods Implementation ***/
Distance::Distance() : m_dist(0) {}
Distance::Distance(long value) : m_dist(value) {}
void set_distance(Distance &dst, long value)
{
    dst.m_dist = value;
}
long get_distance(const Distance &dst)
{
    return dst.m_dist;
}
double distance_to_meters(const Distance &dst)
{
    return static_cast<double>(dst.m_dist) / 1000.0;
}
Distance operator+(const Distance &d1, const Distance &d2)
{
    return Distance(d1.m_dist + d2.m_dist);
}
Distance operator+(const Distance &d, long value)
{
    return Distance(d.m_dist + value);
}
Distance operator+(long value, const Distance &d)
{
    return Distance(value + d.m_dist);
}

/*** Main ***/
int main(void)
{
    Distance d(783);
    std::cout << get_distance(d) << ' ' << std::fixed << std::setprecision(2) << distance_to_meters(d) << std::endl;
    __ASSERT_TESTS__
    return 0;
}
