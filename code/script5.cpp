/**********************************************************************
 * @file script5.cpp
 * @brief Класс BottleWater: оператор сложения, ограничение объёма, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-13
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс BottleWater: бутылка с водой, ограничение объёма
 */
class BottleWater
{
public:
    /**
     * @brief Конструктор
     * @param[in] volume объём воды
     */
    BottleWater(unsigned volume = 0);
    /**
     * @brief Получить объём воды
     * @return unsigned
     */
    unsigned get_volume() const;
    /**
     * @brief Сложение двух бутылок
     * @param[in] other другая бутылка
     * @return BottleWater
     */
    BottleWater operator+(const BottleWater &other) const;
    /**
     * @brief Сложение с числом (BottleWater + unsigned)
     * @param[in] v объём
     * @return BottleWater
     */
    BottleWater operator+(unsigned v) const;
    /**
     * @brief Сложение с числом (unsigned + BottleWater)
     * @param[in] v объём
     * @param[in] b бутылка
     * @return BottleWater
     */
    friend BottleWater operator+(unsigned v, const BottleWater &b);

private:
    static const unsigned m_max_volume = 320; ///< максимальный объём
    unsigned m_volume{0};                     ///< объём воды
};

/*** Methods Implementation ***/
BottleWater::BottleWater(unsigned volume)
    : m_volume(volume > m_max_volume ? m_max_volume : volume) {}

unsigned BottleWater::get_volume() const { return m_volume; }

BottleWater BottleWater::operator+(const BottleWater &other) const
{
    unsigned sum = m_volume + other.m_volume;
    if (sum > m_max_volume)
        sum = m_max_volume;
    return BottleWater(sum);
}

BottleWater BottleWater::operator+(unsigned v) const
{
    unsigned sum = m_volume + v;
    if (sum > m_max_volume)
        sum = m_max_volume;
    return BottleWater(sum);
}

BottleWater operator+(unsigned v, const BottleWater &b)
{
    unsigned sum = b.m_volume + v;
    if (sum > BottleWater::m_max_volume)
        sum = BottleWater::m_max_volume;
    return BottleWater(sum);
}

/*** Main Function ***/
int main(void)
{
    BottleWater bw1(40), bw2(200);
    BottleWater res = bw1 + bw2;

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

        return 0;
}