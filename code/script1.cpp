/**********************************************************************
 * @file script1.cpp
 * @brief Структура thing: приватные поля, публичные методы (embedded C++ style)
 * @version 1.0 (Stepik exercise)
 * @date 2025-08-27
 **********************************************************************/

#include <cstddef>
#include "emb_style_cpp_en.h"

/**
 * @brief Структура вещи с приватными полями и публичными методами
 */
struct thing
{
private:
    unsigned int m_id_u32;
    double m_price_f64;
    double m_weight_f64;

public:
    /**
     * @brief Получить идентификатор
     * @return Значение поля id
     */
    unsigned int get_id(void) const
    {
        return m_id_u32;
    }
    /**
     * @brief Получить цену и вес
     * @param[out] price Цена
     * @param[out] weight Вес
     */
    void get_data(double &price, double &weight) const
    {
        price = m_price_f64;
        weight = m_weight_f64;
    }
    /**
     * @brief Установить id, цену и вес
     * @param[in] id Идентификатор
     * @param[in] price Цена
     * @param[in] weight Вес
     */
    void set_data(unsigned int id, double price, double weight)
    {
        m_id_u32 = id;
        m_price_f64 = price;
        m_weight_f64 = weight;
    }
};