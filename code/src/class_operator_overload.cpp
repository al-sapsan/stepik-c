/**********************************************************************
 * @file script5.cpp
 * @brief Класс Bank и BankAccount, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-19
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <string>

/*** Struct Definition ***/
/**
 * @brief Структура BankAccount: банковский счет
 */
struct BankAccount
{
    std::string fio;
    long volume{0};
    BankAccount() = default;
    BankAccount(const std::string &fio_, long vol) : fio(fio_), volume(vol) {}
    /**
     * @brief Оператор += (long)
     * @param[in] val
     * @return BankAccount&
     */
    BankAccount &operator+=(long val)
    {
        volume += val;
        return *this;
    }
    /**
     * @brief Оператор -= (long)
     * @param[in] val
     * @return BankAccount&
     */
    BankAccount &operator-=(long val)
    {
        volume -= val;
        return *this;
    }
    /**
     * @brief Оператор *= (double)
     * @param[in] val
     * @return BankAccount&
     */
    BankAccount &operator*=(double val)
    {
        volume = static_cast<long>(volume * val);
        return *this;
    }
    /**
     * @brief Оператор /= (long)
     * @param[in] val
     * @return BankAccount&
     */
    BankAccount &operator/=(long val)
    {
        if (val != 0)
            volume /= val;
        return *this;
    }
    /**
     * @brief Оператор %= (long)
     * @param[in] val
     * @return BankAccount&
     */
    BankAccount &operator%=(long val)
    {
        if (val != 0)
            volume %= val;
        return *this;
    }
};

/*** Class Definition ***/
/**
 * @brief Класс Bank: банк
 */
class Bank
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    Bank();
    /**
     * @brief Конструктор копирования из массива
     * @param[in] lst массив счетов
     * @param[in] size количество счетов
     */
    Bank(const BankAccount *lst, size_t size);
    /**
     * @brief Конструктор копирования
     * @param[in] other другой объект Bank
     */
    Bank(const Bank &other);
    /**
     * @brief Деструктор
     */
    ~Bank();
    /**
     * @brief Оператор присваивания
     * @param[in] other другой объект Bank
     * @return Bank&
     */
    Bank &operator=(const Bank &other);
    /**
     * @brief Оператор += (BankAccount)
     * @param[in] ac счет
     * @return Bank&
     */
    Bank &operator+=(const BankAccount &ac);
    /**
     * @brief Оператор + (BankAccount)
     * @param[in] ac счет
     * @return Bank
     */
    Bank operator+(const BankAccount &ac) const;
    /**
     * @brief Получить массив счетов
     * @return const BankAccount*
     */
    const BankAccount *get_accounts() const;
    /**
     * @brief Получить количество счетов
     * @return size_t
     */
    size_t get_count() const;

private:
    enum
    {
        max_accounts = 100
    };
    BankAccount *acs{nullptr};
    size_t count{0};
};

/*** Methods Implementation ***/
Bank::Bank() : acs(new BankAccount[max_accounts]), count(0) {}
Bank::Bank(const BankAccount *lst, size_t size)
    : acs(new BankAccount[max_accounts]), count(size > max_accounts ? max_accounts : size)
{
    for (size_t i = 0; i < count; ++i)
        acs[i] = lst[i];
}
Bank::Bank(const Bank &other)
    : acs(new BankAccount[max_accounts]), count(other.count)
{
    for (size_t i = 0; i < count; ++i)
        acs[i] = other.acs[i];
}
Bank::~Bank() { delete[] acs; }
Bank &Bank::operator=(const Bank &other)
{
    if (this != &other)
    {
        delete[] acs;
        acs = new BankAccount[max_accounts];
        count = other.count;
        for (size_t i = 0; i < count; ++i)
            acs[i] = other.acs[i];
    }
    return *this;
}
Bank &Bank::operator+=(const BankAccount &ac)
{
    if (count < max_accounts)
    {
        acs[count++] = ac;
    }
    return *this;
}
Bank Bank::operator+(const BankAccount &ac) const
{
    Bank result(*this);
    result += ac;
    return result;
}
const BankAccount *Bank::get_accounts() const { return acs; }
size_t Bank::get_count() const { return count; }

/*** Main ***/
int main(void)
{
    Bank my_bank;
    my_bank += BankAccount("А. Дзюба", 43056);
    my_bank += BankAccount("П. Гагарина", 1335395);
    my_bank += BankAccount("О. Бузова", 0);
    my_bank += BankAccount("Тимати", -546);
    __ASSERT_TESTS__
    return 0;
}
