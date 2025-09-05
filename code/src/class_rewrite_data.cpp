/**********************************************************************
 * @file script7.cpp
 * @brief Класс TravelBlog: приватные поля, методы, main
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-05
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <string>

/*** Class Definition ***/
/**
 * @brief Класс для хранения информации о путешествии
 */
class TravelBlog
{
private:
    std::string m_country_str;
    short m_days_i16;

public:
    /*** Function Prototypes ***/
    /**
     * @brief Задать страну и дни
     * @param[in] country страна
     * @param[in] days число дней
     */
    void set_info(const std::string &country, short days)
    {
        m_country_str = country;
        m_days_i16 = days;
    }
    /**
     * @brief Задать данные из другого блога
     * @param[in] blog объект TravelBlog
     */
    void set_info(const TravelBlog &blog)
    {
        m_country_str = blog.m_country_str;
        m_days_i16 = blog.m_days_i16;
    }
    /**
     * @brief Получить страну
     * @return ссылка на страну
     */
    const std::string &get_country() { return m_country_str; }
    /**
     * @brief Получить число дней
     * @return число дней
     */
    short get_days() { return m_days_i16; }
};

/*** Main Function ***/
int main(void)
{
    TravelBlog blog1, blog2;
    blog1.set_info("ОАЭ", 10);
    blog2.set_info(blog1);
    return 0;
}
