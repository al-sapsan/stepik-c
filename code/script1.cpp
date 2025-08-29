/**********************************************************************
 * @file script1.cpp
 * @brief Struct thing: auto-increment id, constructors, dynamic allocation
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-29
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <cstring>

/*** Typedefs ***/
typedef unsigned long u32_id_t;
typedef unsigned int u32_price_t;
typedef double f64_weight_t;

/*** Struct Definition ***/
typedef struct
{
    u32_id_t m_id_u32;
    char m_name_str[50];
    u32_price_t m_price_u32;
    f64_weight_t m_weight_f64;

    /*** Static id counter ***/
    static u32_id_t s_id_counter_u32;

    /*** Function Prototypes ***/
    /**
     * @brief Конструктор по умолчанию
     * @details Инициализирует пустое название, цену и вес равными нулю. Автоматически увеличивает идентификатор.
     */
    thing()
    {
        m_id_u32 = ++s_id_counter_u32;
        m_name_str[0] = '\0';
        m_price_u32 = 0;
        m_weight_f64 = 0.0;
    }
    /**
     * @brief Конструктор с названием
     * @param[in] ptr_name Название предмета
     * @details Цена и вес устанавливаются в 0. Идентификатор увеличивается автоматически.
     */
    thing(const char *ptr_name)
    {
        m_id_u32 = ++s_id_counter_u32;
        strncpy(m_name_str, ptr_name, sizeof(m_name_str) - 1);
        m_name_str[sizeof(m_name_str) - 1] = '\0';
        m_price_u32 = 0;
        m_weight_f64 = 0.0;
    }
    /**
     * @brief Конструктор с названием и ценой
     * @param[in] ptr_name Название предмета
     * @param[in] price_u32 Цена предмета
     * @details Вес устанавливается в 0. Идентификатор увеличивается автоматически.
     */
    thing(const char *ptr_name, u32_price_t price_u32)
    {
        m_id_u32 = ++s_id_counter_u32;
        strncpy(m_name_str, ptr_name, sizeof(m_name_str) - 1);
        m_name_str[sizeof(m_name_str) - 1] = '\0';
        m_price_u32 = price_u32;
        m_weight_f64 = 0.0;
    }
    /**
     * @brief Конструктор с названием, ценой и весом
     * @param[in] ptr_name Название предмета
     * @param[in] price_u32 Цена предмета
     * @param[in] weight_f64 Вес предмета
     * @details Идентификатор увеличивается автоматически.
     */
    thing(const char *ptr_name, u32_price_t price_u32, f64_weight_t weight_f64)
    {
        m_id_u32 = ++s_id_counter_u32;
        strncpy(m_name_str, ptr_name, sizeof(m_name_str) - 1);
        m_name_str[sizeof(m_name_str) - 1] = '\0';
        m_price_u32 = price_u32;
        m_weight_f64 = weight_f64;
    }
} thing_t;

/*** Static member initialization ***/
u32_id_t thing_t::s_id_counter_u32 = 0;

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @details Чтение данных о предмете, динамическое создание объекта, вывод цены и освобождение памяти.
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    char name_str[50];
    u32_price_t price_u32 = 0;
    f64_weight_t weight_f64 = 0.0;

    std::cin >> name_str >> price_u32 >> weight_f64;

    thing_t *ptr_th = new thing_t(name_str, price_u32, weight_f64);
    std::cout << ptr_th->m_price_u32 << std::endl;

    delete ptr_th;

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}
