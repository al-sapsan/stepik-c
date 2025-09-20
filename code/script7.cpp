/**********************************************************************
 * @file script7.cpp
 * @brief Класс Clock, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-20
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс Clock: время
 */
class Clock
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    Clock();
    /**
     * @brief Конструктор с параметром
     * @param[in] t время
     */
    Clock(unsigned t);
    /**
     * @brief Получить время
     * @return unsigned
     */
    unsigned get_time() const;
    /**
     * @brief Оператор +
     * @param[in] other
     * @return Clock
     */
    Clock operator+(const Clock &other) const;
    /**
     * @brief Оператор += (unsigned)
     * @param[in] val
     * @return Clock&
     */
    Clock &operator+=(unsigned val);
    /**
     * @brief Оператор -= (unsigned)
     * @param[in] val
     * @return Clock&
     */
    Clock &operator-=(unsigned val);
    /**
     * @brief Оператор += (Clock)
     * @param[in] other
     * @return Clock&
     */
    Clock &operator+=(const Clock &other);
    /**
     * @brief Оператор -= (Clock)
     * @param[in] other
     * @return Clock&
     */
    Clock &operator-=(const Clock &other);
    /**
     * @brief Оператор постфиксного инкремента
     * @return unsigned (старое значение)
     */
    unsigned operator++(int);
    /**
     * @brief Оператор префиксного инкремента
     * @return unsigned (новое значение)
     */
    unsigned operator++();
    /**
     * @brief Оператор постфиксного декремента
     * @return unsigned (старое значение)
     */
    unsigned operator--(int);
    /**
     * @brief Оператор префиксного декремента
     * @return unsigned (новое значение)
     */
    unsigned operator--();

private:
    unsigned tm{0};
    void clamp();
};

/*** Methods Implementation ***/
Clock::Clock() : tm(0) {}
Clock::Clock(unsigned t) : tm(t) {}
unsigned Clock::get_time() const { return tm; }
void Clock::clamp()
{
    if (tm > 0xFFFFFFFF)
        tm = 0xFFFFFFFF;
}
Clock Clock::operator+(const Clock &other) const
{
    return Clock(tm + other.tm);
}
Clock &Clock::operator+=(unsigned val)
{
    tm += val;
    clamp();
    return *this;
}
Clock &Clock::operator-=(unsigned val)
{
    if (tm < val)
        tm = 0;
    else
        tm -= val;
    return *this;
}
Clock &Clock::operator+=(const Clock &other)
{
    tm += other.tm;
    clamp();
    return *this;
}
Clock &Clock::operator-=(const Clock &other)
{
    if (tm < other.tm)
        tm = 0;
    else
        tm -= other.tm;
    return *this;
}
unsigned Clock::operator++(int)
{
    unsigned old = tm;
    ++tm;
    clamp();
    return old;
}
unsigned Clock::operator++()
{
    ++tm;
    clamp();
    return tm;
}
unsigned Clock::operator--(int)
{
    unsigned old = tm;
    if (tm > 0)
        --tm;
    return old;
}
unsigned Clock::operator--()
{
    if (tm > 0)
        --tm;
    return tm;
}

/*** Main ***/
int main(void)
{
    Clock clock_1(100), clock_2(430);
    Clock res = clock_1 + clock_2;
    __ASSERT_TESTS__
    return 0;
}
