/**********************************************************************
 * @file script6.cpp
 * @brief Класс AbsoluteValue, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-16
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <cstdlib>

/*** Class Definition ***/
/**
 * @brief Класс AbsoluteValue: абсолютное значение
 */
class AbsoluteValue
{
public:
    /**
     * @brief Абсолютное значение
     */
    unsigned long m_value{0};
    /**
     * @brief Конструктор по умолчанию
     */
    AbsoluteValue();
    /**
     * @brief Конструктор с параметром
     * @param[in] val значение
     */
    AbsoluteValue(long val);
    /**
     * @brief Оператор присваивания
     * @param[in] val значение
     * @return AbsoluteValue&
     */
    AbsoluteValue &operator=(long val);
};

/*** Methods Implementation ***/
AbsoluteValue::AbsoluteValue() : m_value(0) {}
AbsoluteValue::AbsoluteValue(long val) : m_value(val < 0 ? static_cast<unsigned long>(-val) : static_cast<unsigned long>(val)) {}
AbsoluteValue &AbsoluteValue::operator=(long val)
{
    m_value = val < 0 ? static_cast<unsigned long>(-val) : static_cast<unsigned long>(val);
    return *this;
}

/*** Main ***/
int main(void)
{
    AbsoluteValue *ptr_abv = new AbsoluteValue;
    *ptr_abv = -512;
    __ASSERT_TESTS__
    delete ptr_abv;
    return 0;
}
