/**********************************************************************
 * @file script3.cpp
 * @brief Класс BankAccount, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-19
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
     * @brief Оператор += (long)
     * @param[in] volume сумма
     * @return BankAccount&
     */
    BankAccount &operator+=(long volume);
    /**
     * @brief Оператор -= (long)
     * @param[in] volume сумма
     * @return BankAccount&
     */
    BankAccount &operator-=(long volume);
    /**
     * @brief Оператор += (BankAccount)
     * @param[in] other
     * @return BankAccount&
     */
    BankAccount &operator+=(const BankAccount &other);
    /**
     * @brief Оператор -= (BankAccount)
     * @param[in] other
     * @return BankAccount&
     */
    BankAccount &operator-=(const BankAccount &other);
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
    std::string fio;
    long volume_rub{0};
};

/*** Methods Implementation ***/
BankAccount::BankAccount(const std::string &fio_) : fio(fio_), volume_rub(0) {}
BankAccount::BankAccount(const std::string &fio_, long volume) : fio(fio_), volume_rub(volume) {}
BankAccount &BankAccount::operator=(long volume)
{
    volume_rub = volume;
    return *this;
}
BankAccount &BankAccount::operator+=(long volume)
{
    volume_rub += volume;
    return *this;
}
BankAccount &BankAccount::operator-=(long volume)
{
    volume_rub -= volume;
    return *this;
}
BankAccount &BankAccount::operator+=(const BankAccount &other)
{
    volume_rub += other.volume_rub;
    return *this;
}
BankAccount &BankAccount::operator-=(const BankAccount &other)
{
    volume_rub -= other.volume_rub;
    return *this;
}
const std::string &BankAccount::get_fio() const
{
    return fio;
}
long BankAccount::get_volume_rub() const
{
    return volume_rub;
}
