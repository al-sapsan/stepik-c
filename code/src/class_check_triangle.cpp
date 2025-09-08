/**********************************************************************
 * @file script2.cpp
 * @brief Класс TriangleChecker: приватные стороны, методы, main
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-06
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс для проверки возможности построения треугольника
 */
class TriangleChecker
{
private:
    int m_a_i32;
    int m_b_i32;
    int m_c_i32;

public:
    /*** Constructors ***/
    /**
     * @brief Конструктор с параметрами сторон
     * @param[in] a длина стороны a
     * @param[in] b длина стороны b
     * @param[in] c длина стороны c
     */
    TriangleChecker(int a, int b, int c) : m_a_i32(a), m_b_i32(b), m_c_i32(c) {}

    /*** Methods Implementation ***/
    /**
     * @brief Проверить возможность построения треугольника
     * @return 1 - некорректные значения, 2 - не треугольник, 3 - треугольник
     */
    int is_triangle()
    {
        // Проверка положительных сторон
        if (m_a_i32 <= 0 || m_b_i32 <= 0 || m_c_i32 <= 0)
            return 1;

        // Оптимизированная проверка неравенства треугольника
        int a = m_a_i32, b = m_b_i32, c = m_c_i32;

        // Сортируем стороны для более эффективной проверки
        if (a > b)
            std::swap(a, b);
        if (b > c)
            std::swap(b, c);
        if (a > b)
            std::swap(a, b);

        // Теперь a ≤ b ≤ c, проверяем a + b > c
        if (a + b <= c)
            return 2;

        return 3;
    }
};

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @details Считывает стороны, создает объект TriangleChecker, выводит результат проверки, освобождает память
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    int a, b, c;
    std::cin >> a >> b >> c;
    TriangleChecker *ptr_tr = new TriangleChecker(a, b, c);
    std::cout << ptr_tr->is_triangle() << std::endl;
    delete ptr_tr;
    ptr_tr = nullptr; // <- тренируем мышечную память
    return 0;
}
