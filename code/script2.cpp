/**********************************************************************
 * @file script2.cpp
 * @brief Класс FilterWater и дружественные функции, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-15
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Types ***/
/**
 * @brief Тип фильтра воды
 */
enum type_filter
{
    flt_aragon = 1,
    flt_calcium = 2
};

/*** Class Definition ***/
/**
 * @brief Класс FilterWater: фильтр воды
 */
class FilterWater
{
public:
    /**
     * @brief Конструктор с параметрами
     * @param[in] t тип фильтра
     * @param[in] d дата установки
     * @param[in] v объём фильтра
     */
    FilterWater(type_filter t, unsigned d, unsigned short v);
    /**
     * @brief Дружественная функция: получить тип фильтра
     * @param[in] flt фильтр
     * @return type_filter
     */
    friend type_filter get_type_filter(const FilterWater &flt);
    /**
     * @brief Дружественная функция: получить дату установки
     * @param[in] flt фильтр
     * @return unsigned
     */
    friend unsigned get_date_filter(const FilterWater &flt);
    /**
     * @brief Дружественная функция: получить объём фильтра
     * @param[in] flt фильтр
     * @return unsigned short
     */
    friend unsigned short get_volume_filter(const FilterWater &flt);

private:
    type_filter m_type;
    unsigned m_date;
    unsigned short m_volume;
};

/*** Methods Implementation ***/
FilterWater::FilterWater(type_filter t, unsigned d, unsigned short v)
    : m_type(t), m_date(d), m_volume(v) {}

type_filter get_type_filter(const FilterWater &flt)
{
    return flt.m_type;
}
unsigned get_date_filter(const FilterWater &flt)
{
    return flt.m_date;
}
unsigned short get_volume_filter(const FilterWater &flt)
{
    return flt.m_volume;
}

/*** Main ***/
int main(void)
{
    FilterWater filter(flt_calcium, 153564646, 108);
    std::cout << get_type_filter(filter) << ' ' << get_date_filter(filter) << ' ' << get_volume_filter(filter) << std::endl;
    __ASSERT_TESTS__
    return 0;
}
