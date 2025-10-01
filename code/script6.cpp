/**********************************************************************
 * @file script6.cpp
 * @brief Equipment, PC class implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-10-01
 **********************************************************************/

#include <iostream>
#include <string>

/********** Class Definition **********/

// == < Equipment > == //
/**
 * @brief Класс оборудования
 * @param uid Идентификатор
 * @param is_exists Наличие оборудования
 */
class Equipment
{
private:
    unsigned long m_uid{0};
    static unsigned long s_uid_counter;

protected:
    bool m_is_exists{false};

public:
    Equipment() : m_is_exists(false), m_uid(++s_uid_counter) {}
    Equipment(bool is_exists) : m_is_exists(is_exists), m_uid(++s_uid_counter) {}

    unsigned long get_uid() const { return m_uid; }
    virtual void print() const {}
    virtual ~Equipment() {}
};

unsigned long Equipment::s_uid_counter = 0;

// == < PC > == //
/**
 * @brief Класс компьютера
 * @param model Модель компьютера
 * @param price Цена
 * @param is_exists Наличие оборудования
 */
class PC : public Equipment
{
private:
    std::string m_model;
    int m_price{0};

public:
    PC(const std::string &model, int price, bool is_exists)
        : Equipment(is_exists), m_model(model), m_price(price) {}

    const std::string &get_model() const { return m_model; }
    int get_price() const { return m_price; }

    virtual void print() const override
    {
        std::cout << "PC: " << m_model << ", " << m_price << ", " << (m_is_exists ? 1 : 0) << std::endl;
    }

    virtual ~PC() override
    {
        std::cout << "~PC" << std::endl;
    }
};