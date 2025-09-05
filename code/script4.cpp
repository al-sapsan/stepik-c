/**********************************************************************
 * @file script4.cpp
 * @brief Класс Clock: приватное время, методы, main
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-05
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <iomanip>

/*** Class Definition ***/
/**
 * @brief Класс для хранения времени в секундах и получения часов, минут, секунд
 */
class Clock
{
private:
    unsigned m_time_current_u32;

public:
    /*** Methods Implementation ***/
    /**
     * @brief Установить текущее время в секундах
     * @param[in] tm время в секундах
     */
    void set_time(unsigned tm)
    {
        m_time_current_u32 = tm;
    }
    /**
     * @brief Получить количество часов
     * @return часы
     */
    unsigned get_hours()
    {
        return m_time_current_u32 / 3600;
    }
    /**
     * @brief Получить количество минут (без учёта часов)
     * @return минуты
     */
    unsigned get_minutes()
    {
        return (m_time_current_u32 / 60) % 60;
    }
    /**
     * @brief Получить количество секунд (без учёта часов и минут)
     * @return секунды
     */
    unsigned get_seconds()
    {
        return m_time_current_u32 % 60;
    }
};

/*** Main Function ***/
int main(void)
{
    Clock *ptr_cl = new Clock;
    unsigned tm;
    std::cin >> tm;
    ptr_cl->set_time(tm);
    unsigned hh = ptr_cl->get_hours();
    unsigned mm = ptr_cl->get_minutes();
    unsigned ss = ptr_cl->get_seconds();
    std::cout << std::setfill('0'); // Установить fill для всех полей
    std::cout << std::setw(2) << hh << ":"
              << std::setw(2) << mm << ":"
              << std::setw(2) << ss << std::endl;
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)
        delete ptr_cl;
    ptr_cl = nullptr; // <- тренируем мышечную память
    return 0;
}
