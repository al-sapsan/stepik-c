/**********************************************************************
 * @file script2.cpp
 * @brief Класс BottleWater, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-19
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс BottleWater: бутылка воды
 */
class BottleWater
{
public:
    /**
     * @brief Конструктор
     * @param[in] volume объем воды
     */
    BottleWater(short volume = 0);
    /**
     * @brief Получить объем воды
     * @return short
     */
    short get_volume() const;
    /**
     * @brief Оператор +
     * @param[in] other
     * @return BottleWater
     */
    BottleWater operator+(const BottleWater &other) const;
    /**
     * @brief Оператор += (short)
     * @param[in] val
     * @return BottleWater&
     */
    BottleWater &operator+=(short val);
    /**
     * @brief Оператор -= (short)
     * @param[in] val
     * @return BottleWater&
     */
    BottleWater &operator-=(short val);
    /**
     * @brief Оператор *= (short)
     * @param[in] val
     * @return BottleWater&
     */
    BottleWater &operator*=(short val);
    /**
     * @brief Оператор /= (short)
     * @param[in] val
     * @return BottleWater&
     */
    BottleWater &operator/=(short val);
    /**
     * @brief Оператор += (BottleWater)
     * @param[in] other
     * @return BottleWater&
     */
    BottleWater &operator+=(const BottleWater &other);
    /**
     * @brief Оператор -= (BottleWater)
     * @param[in] other
     * @return BottleWater&
     */
    BottleWater &operator-=(const BottleWater &other);
    /**
     * @brief Оператор *= (BottleWater)
     * @param[in] other
     * @return BottleWater&
     */
    BottleWater &operator*=(const BottleWater &other);
    /**
     * @brief Оператор /= (BottleWater)
     * @param[in] other
     * @return BottleWater&
     */
    BottleWater &operator/=(const BottleWater &other);

private:
    enum
    {
        max_volume = 640
    };
    short volume{0};
    void clamp();
};

/*** Methods Implementation ***/
BottleWater::BottleWater(short volume_) : volume(volume_) { clamp(); }
short BottleWater::get_volume() const { return volume; }
void BottleWater::clamp()
{
    if (volume < 0)
        volume = 0;
    if (volume > max_volume)
        volume = max_volume;
}
BottleWater BottleWater::operator+(const BottleWater &other) const
{
    BottleWater res(volume + other.volume);
    return res;
}
BottleWater &BottleWater::operator+=(short val)
{
    volume += val;
    clamp();
    return *this;
}
BottleWater &BottleWater::operator-=(short val)
{
    volume -= val;
    clamp();
    return *this;
}
BottleWater &BottleWater::operator*=(short val)
{
    volume *= val;
    clamp();
    return *this;
}
BottleWater &BottleWater::operator/=(short val)
{
    if (val != 0)
        volume /= val;
    clamp();
    return *this;
}
BottleWater &BottleWater::operator+=(const BottleWater &other)
{
    volume += other.volume;
    clamp();
    return *this;
}
BottleWater &BottleWater::operator-=(const BottleWater &other)
{
    volume -= other.volume;
    clamp();
    return *this;
}
BottleWater &BottleWater::operator*=(const BottleWater &other)
{
    volume *= other.volume;
    clamp();
    return *this;
}
BottleWater &BottleWater::operator/=(const BottleWater &other)
{
    if (other.volume != 0)
        volume /= other.volume;
    clamp();
    return *this;
}

/*** Main ***/
int main(void)
{
    BottleWater bw1(40), bw2(200);
    BottleWater res = bw1 + bw2;
    __ASSERT_TESTS__
    return 0;
}
