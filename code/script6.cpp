/**********************************************************************
 * @file script6.cpp
 * @brief Структура triangle: конструкторы, приватные поля, публичные методы, main (embedded C++ style)
 * @version 1.0 (Stepik exercise)
 * @date 2025-08-27
 **********************************************************************/

#include <iostream>

/**
 * @brief Структура треугольника с конструктором и методами
 */
struct triangle
{
private:
    int m_a_i32;
    int m_b_i32;
    int m_c_i32;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    triangle() : m_a_i32(0), m_b_i32(0), m_c_i32(0) {}
    /**
     * @brief Конструктор с параметрами
     */
    triangle(int a, int b, int c) : m_a_i32(a), m_b_i32(b), m_c_i32(c) {}
    /**
     * @brief Проверка возможности построения треугольника
     * @return true, если стороны образуют треугольник
     */
    bool is_triangle(void) const
    {
        return m_a_i32 > 0 && m_b_i32 > 0 && m_c_i32 > 0 &&
               m_a_i32 + m_b_i32 > m_c_i32 &&
               m_a_i32 + m_c_i32 > m_b_i32 &&
               m_b_i32 + m_c_i32 > m_a_i32;
    }
    /**
     * @brief Получить длины сторон
     * @param[out] a, b, c
     */
    void get_lengths(int &a, int &b, int &c) const
    {
        a = m_a_i32;
        b = m_b_i32;
        c = m_c_i32;
    }
    /**
     * @brief Установить длины сторон
     * @param[in] a, b, c
     */
    void set_lengths(int a, int b, int c)
    {
        m_a_i32 = a;
        m_b_i32 = b;
        m_c_i32 = c;
    }
};

/*** Main Function ***/
int main(void)
{
    triangle tr_1;
    triangle tr_2(7, 4, 8);
    __ASSERT_TESTS__
    return 0;
}