/**********************************************************************
 * @file script6.cpp
 * @brief Класс Clock: конструкторы, get_time вне класса, динамическое создание
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-12
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс для хранения времени
 */
class Clock
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    Clock() : tm(0) {}
    /**
     * @brief Конструктор с параметром
     * @param[in] t время
     */
    Clock(unsigned t) : tm(t) {}
    /**
     * @brief Получить время
     * @return unsigned
     */
    unsigned get_time();

private:
    unsigned tm{0}; ///< текущее время
};

/*** Methods Implementation ***/
/**
 * @brief Получить время
 * @return unsigned
 */
unsigned Clock::get_time() { return tm; }

/*** Main Function ***/
int main(void)
{
    // создаём объект через new
    Clock *ptr_cl = new Clock(12643);
    unsigned res = ptr_cl->get_time();

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

        // освобождаем память
        delete ptr_cl;

    return 0;
}
