/**********************************************************************
 * @file script1.cpp
 * @brief Класс ValueDouble, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-23
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс ValueDouble
 */
class ValueDouble
{
private:
    double m_value; ///< Значение
public:
    /**
     * @brief Конструктор по умолчанию
     */
    ValueDouble() : m_value(0.0) {}
    /**
     * @brief Конструктор с параметром
     * @param[in] value Значение
     */
    ValueDouble(double value) : m_value(value) {}
    /**
     * @brief Получить значение
     * @return Значение
     */
    double get_value() const { return m_value; }
    /**
     * @brief Дружественная функция для сложения
     */
    friend ValueDouble operator+(const ValueDouble &lhs, const ValueDouble &rhs);
    friend ValueDouble operator+(const ValueDouble &lhs, double rhs);
    friend ValueDouble operator+(double lhs, const ValueDouble &rhs);
};

/*** Methods Implementation ***/
ValueDouble operator+(const ValueDouble &lhs, const ValueDouble &rhs)
{
    return ValueDouble(lhs.m_value + rhs.m_value);
}
ValueDouble operator+(const ValueDouble &lhs, double rhs)
{
    return ValueDouble(lhs.m_value + rhs);
}
ValueDouble operator+(double lhs, const ValueDouble &rhs)
{
    return ValueDouble(lhs + rhs.m_value);
}

int main()
{
    // Создание объекта и ссылок
    ValueDouble vd(8.7);
    ValueDouble &lnk_vd = vd;
    ValueDouble &&lnk_r_vd = ValueDouble(8.7);

    __ASSERT_TESTS__ // макроопределение для тестирования
        return 0;
}
