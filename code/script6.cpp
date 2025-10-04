/**********************************************************************
 * @file script6.cpp
 * @brief Wallet class implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-10-04
 **********************************************************************/

#include <iostream>
#include <stdexcept>

/********** Class Definition **********/
/**
 * @brief Класс Wallet (кошелек)
 * @details Хранит количество денег, поддерживает лимит, арифметические операции и проверки.
 * @note Исключения генерируются при выходе за пределы диапазона.
 */
class Wallet
{
private:
    enum
    {
        wallet_limit = 1000000
    };
    long m_volume{0};

    static void check_bounds(long value, const char *msg)
    {
        if (value < 0 || value > wallet_limit)
            throw std::string(msg);
    }

public:
    Wallet() : m_volume(0) {}

    Wallet(long value)
    {
        check_bounds(value, "Value is out of bounds.");
        m_volume = value;
    }

    long get_volume() const { return m_volume; }

    // Assignment from long
    Wallet &operator=(long value)
    {
        check_bounds(value, "Volume is out of bounds.");
        m_volume = value;
        return *this;
    }

    // += long
    Wallet &operator+=(long value)
    {
        check_bounds(m_volume + value, "Volume is out of bounds.");
        m_volume += value;
        return *this;
    }

    // -= long
    Wallet &operator-=(long value)
    {
        check_bounds(m_volume - value, "Volume is out of bounds.");
        m_volume -= value;
        return *this;
    }

    // + Wallet
    Wallet operator+(const Wallet &other) const
    {
        check_bounds(m_volume + other.m_volume, "Volume is out of bounds.");
        return Wallet(m_volume + other.m_volume);
    }

    // + long (Wallet + long)
    Wallet operator+(long value) const
    {
        check_bounds(m_volume + value, "Volume is out of bounds.");
        return Wallet(m_volume + value);
    }

    // friend for long + Wallet
    friend Wallet operator+(long value, const Wallet &w)
    {
        check_bounds(value + w.m_volume, "Volume is out of bounds.");
        return Wallet(value + w.m_volume);
    }
};

/********** Main Function **********/
int main(void)
{
    try
    {
        Wallet wl(500);
    }
    catch (const std::string &ex)
    {
        std::cout << ex << std::endl;
    }

    __ASSERT_TESTS__

    return 0;
}