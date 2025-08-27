/**********************************************************************
 * @file script5.cpp
 * @brief Структура money: конструктор, приватное поле, публичные методы, main (embedded C++ style)
 * @version 1.0 (Stepik exercise)
 * @date 2025-08-27
 **********************************************************************/

#include <iostream>
#include "emb_style_cpp_en.h"

/**
 * @brief Структура денег с конструктором и методами
 */
struct money
{
private:
    int m_total_money_i32;

public:
    /**
     * @brief Конструктор
     * @param volume Количество денег
     */
    explicit money(int volume) : m_total_money_i32(volume) {}
    /**
     * @brief Получить количество денег
     * @return Значение поля total_money
     */
    int get_money(void) const { return m_total_money_i32; }
    /**
     * @brief Установить количество денег
     * @param volume Новое значение
     */
    void set_money(int volume) { m_total_money_i32 = volume; }
};

/*** Main Function ***/
int main(void)
{
    money rubs(100);
    std::cout << rubs.get_money() << std::endl;
    __ASSERT_TESTS__
    return 0;
}