/**********************************************************************
 * @file script3.cpp
 * @brief BankAccount class implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-10-02
 **********************************************************************/

#include <string> // for std::string

/********** Class Definition **********/
// == < BankAccount > == //
/**
 * @brief Класс банковского счета
 * @param fio Владелец счета
 * @param volume_rub Объем средств в рублях
 */
class BankAccount
{
private:
    std::string m_fio;
    long m_volume_rub{0};

public:
    BankAccount(const std::string &fio) : m_fio(fio), m_volume_rub(0) {}
    BankAccount(const std::string &fio, long volume_rub) : m_fio(fio), m_volume_rub(volume_rub) {}

    const std::string &get_fio() const { return m_fio; }
    long get_volume_rub() const { return m_volume_rub; }

    // Assignment from long
    BankAccount &operator=(long value)
    {
        m_volume_rub = value;
        return *this;
    }

    // += long
    BankAccount &operator+=(long value)
    {
        m_volume_rub += value;
        return *this;
    }

    // -= long
    BankAccount &operator-=(long value)
    {
        m_volume_rub -= value;
        return *this;
    }

    // += BankAccount
    BankAccount &operator+=(const BankAccount &other)
    {
        m_volume_rub += other.m_volume_rub;
        return *this;
    }

    // -= BankAccount
    BankAccount &operator-=(const BankAccount &other)
    {
        m_volume_rub -= other.m_volume_rub;
        return *this;
    }
};