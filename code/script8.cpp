/**********************************************************************
 * @file script8.cpp
 * @brief Clock, ClockOperators, ClockPrint, TimeValue implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-10-02
 **********************************************************************/

#include <iostream>
#include <cstdio>

/********** Class Definition **********/
class TimeValue
{
protected:
    unsigned m_tm{0};

public:
    int get_time() const { return m_tm; }
    virtual ~TimeValue() = default;
};

class ClockOperators : virtual public TimeValue
{
public:
    ClockOperators(unsigned tm = 0) { m_tm = tm; }
    unsigned operator+(const ClockOperators &right) const
    {
        return m_tm + right.m_tm;
    }
    virtual ~ClockOperators() = default;
};

class ClockPrint : virtual public TimeValue
{
public:
    void print() const
    {
        unsigned h = m_tm / 3600;
        unsigned m = (m_tm - h * 3600) / 60;
        unsigned s = (m_tm - h * 3600 - m * 60);

        std::printf("%02u:%02u:%02u\n", h, m, s);
    }
    virtual ~ClockPrint() = default;
};

// == < Clock > == //
/**
 * @brief Класс Clock (часы с операциями и выводом)
 * @details Позволяет складывать объекты, выводить время, получать текущее значение.
 * @note Использует множественное наследование от ClockOperators и ClockPrint.
 */
class Clock : public ClockOperators, public ClockPrint
{
public:
    Clock() : TimeValue(), ClockOperators(), ClockPrint() {}
    Clock(unsigned tm) : TimeValue(), ClockOperators(tm), ClockPrint() { m_tm = tm; }

    // Addition operator for Clock objects
    Clock operator+(const Clock &right) const
    {
        return Clock(m_tm + right.m_tm);
    }
    // get_time() is inherited from TimeValue
    // print() is inherited from ClockPrint
    // virtual destructor is not strictly needed, but for style:
    virtual ~Clock() = default;
};

/********** Main Function **********/
int main(void)
{
    Clock cl_1(15334), cl_2(43654);
    Clock res = cl_1 + cl_2;
    std::cout << res.get_time() << std::endl;

    __ASSERT_TESTS__

    return 0;
}