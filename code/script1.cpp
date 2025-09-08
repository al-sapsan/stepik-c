/**********************************************************************
 * @file script1.cpp
 * @brief Класс Wallet: приватное поле, конструктор, методы, main
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-06
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс для хранения количества денег в кошельке
 */
class Wallet
{
private:
    long m_volume_i64;

public:
    /*** Default Constructor ***/
    /**
     * @brief Конструктор (по умолчанию и с параметром)
     * @param[in] volume количество денег (по умолчанию 0)
     */
    Wallet(long volume = 0) : m_volume_i64(volume) {}

    /*** Methods Implementation ***/
    /**
     * @brief Установить количество денег
     * @param[in] volume новое значение
     */
    void set_volume(long volume) { m_volume_i64 = volume; }
    /**
     * @brief Получить количество денег
     * @return текущее значение
     */
    long get_volume() { return m_volume_i64; }
};

/*** Main Function ***/
int main(void)
{
    Wallet wt1(1000), wt2;
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)
        return 0;
}
