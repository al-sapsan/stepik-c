/************************************************************************
 * @file script3.cpp
 * @brief Класс Clock с обработкой ошибок диапазона и индекса
 * @version 1.0 (Embedded C++ bare-metal/RTOS)
 * @date 2025-10-06
 *
 * @warning Не использовать без "А сколько время?"!)))
 *************************************************************************/

#include <iostream>
#include <string>

using uint8 = unsigned char;

/********** Exception Classes **********/

// == < Class ClockError > == //
/**
 * @brief Базовый класс исключения для ошибок работы с часами
 */
class ClockError : public std::exception
{
protected:
    std::string m_msg;

public:
    explicit ClockError(const std::string &msg) : m_msg(msg) {}
    virtual ~ClockError() {}
    const char *what() const noexcept override { return m_msg.c_str(); }
};

// == < Class ClockValueError > == //
/**
 * @brief Исключение: значение времени вне диапазона
 */
class ClockValueError : public ClockError
{
public:
    explicit ClockValueError(const std::string &msg) : ClockError(msg) {}
};

// == < Class ClockIndexError > == //
/**
 * @brief Исключение: индекс вне диапазона
 */
class ClockIndexError : public ClockError
{
public:
    explicit ClockIndexError(const std::string &msg) : ClockError(msg) {}
};

/************ Class Definition ***********/

// == < Class Clock > == //
class Clock
{
    uint8 m_hours{0};
    uint8 m_mins{0};
    uint8 m_secs{0};

    class Item
    {
        Clock *m_current{nullptr};
        int m_index{-1};

    public:
        Item(Clock *obj, int indx) : m_current{obj}, m_index{indx} {}
        uint8 operator=(uint8 right)
        {
            if (m_index < 0 || m_index > 2)
                throw ClockIndexError("Clock: index error");
            if ((m_index == 0 && (right > 11)) ||
                ((m_index == 1 || m_index == 2) && (right > 59)))
                throw ClockValueError("Clock: out of range");
            switch (m_index)
            {
            case 0:
                m_current->m_hours = right;
                break;
            case 1:
                m_current->m_mins = right;
                break;
            case 2:
                m_current->m_secs = right;
                break;
            }
            return right;
        }
        operator uint8() const
        {
            if (m_index < 0 || m_index > 2)
                throw ClockIndexError("Clock: index error");
            switch (m_index)
            {
            case 0:
                return m_current->m_hours;
            case 1:
                return m_current->m_mins;
            case 2:
                return m_current->m_secs;
            }
            return 0;
        }
    };

public:
    Clock(uint8 hs = 0, uint8 ms = 0, uint8 sc = 0)
    {
        if (hs > 11 || ms > 59 || sc > 59)
            throw ClockValueError("Clock: out of range");
        m_hours = hs;
        m_mins = ms;
        m_secs = sc;
    }
    unsigned get_time() const { return m_hours * 3600 + m_mins * 60 + m_secs; }
    void get_time(uint8 &hours, uint8 &mins, uint8 &secs) const
    {
        hours = m_hours;
        mins = m_mins;
        secs = m_secs;
    }
    void set_time(uint8 hours, uint8 mins, uint8 secs)
    {
        if (hours > 11 || mins > 59 || secs > 59)
            throw ClockValueError("Clock: out of range");
        m_hours = hours;
        m_mins = mins;
        m_secs = secs;
    }
    Item operator[](int indx)
    {
        if (indx < 0 || indx > 2)
            throw ClockIndexError("Clock: index error");
        return Item(this, indx);
    }
};

/********** Main Function **********/

int main()
{
    try
    {
        Clock cl(10, 19, 24);
    }
    catch (const ClockIndexError &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (const ClockValueError &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (const ClockError &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    __ASSERT_TESTS__ // макроопределение для тестирования
        return 0;
}
