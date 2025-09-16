/**********************************************************************
 * @file script8.cpp
 * @brief Класс BankAccount, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-16
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <string>

/*** Class Definition ***/
/**
 * @brief Класс BankAccount: банковский счет
 */
class BankAccount
{
public:
    /**
     * @brief Конструктор с ФИО
     * @param[in] fio владелец счета
     */
    BankAccount(const std::string &fio);
    /**
     * @brief Конструктор с ФИО и суммой
     * @param[in] fio владелец счета
     * @param[in] volume сумма в рублях
     */
    BankAccount(const std::string &fio, long volume);
    /**
     * @brief Оператор присваивания (только сумма)
     * @param[in] volume сумма в рублях
     * @return BankAccount&
     */
    BankAccount &operator=(long volume);
    /**
     * @brief Получить ФИО
     * @return const std::string&
     */
    const std::string &get_fio() const;
    /**
     * @brief Получить сумму
     * @return long
     */
    long get_volume_rub() const;

private:
    std::string m_fio;
    long m_volume_rub{0};
};

/*** Methods Implementation ***/
BankAccount::BankAccount(const std::string &fio) : m_fio(fio), m_volume_rub(0) {}
BankAccount::BankAccount(const std::string &fio, long volume) : m_fio(fio), m_volume_rub(volume) {}
BankAccount &BankAccount::operator=(long volume)
{
    m_volume_rub = volume;
    return *this;
}
const std::string &BankAccount::get_fio() const
{
    return m_fio;
}
long BankAccount::get_volume_rub() const
{
    return m_volume_rub;
}
