/**********************************************************************
 * @file script2.cpp
 * @brief Struct rectangle: private coords, constructors, methods, dynamic allocation
 * @version 1.1 (Embedded C++ style, struct version)
 * @date 2025-08-29
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Struct Definition ***/
struct rectangle
{
private:
    int m_x0_i32;
    int m_y0_i32;
    int m_x1_i32;
    int m_y1_i32;

public:
    /*** Public Methods ***/
    /**
     * @brief Конструктор по умолчанию
     * @details Все координаты инициализируются нулём.
     */
    rectangle()
        : m_x0_i32(0), m_y0_i32(0), m_x1_i32(0), m_y1_i32(0) {}

    /**
     * @brief Конструктор с координатами
     * @param[in] x0, y0, x1, y1 Координаты прямоугольника
     */
    rectangle(int x0, int y0, int x1, int y1)
        : m_x0_i32(x0), m_y0_i32(y0), m_x1_i32(x1), m_y1_i32(y1) {}

    /**
     * @brief Проверка попадания точки в прямоугольник
     * @param[in] x, y Координаты точки
     * @return true, если точка внутри или на границе, иначе false
     */
    bool is_in_rect(int x, int y)
    {
        return (x >= m_x0_i32 && x <= m_x1_i32 && y >= m_y0_i32 && y <= m_y1_i32);
    }

    /**
     * @brief Задать новые координаты прямоугольника
     * @param[in] x0, y0, x1, y1 Новые координаты
     */
    void set_coords(int x0, int y0, int x1, int y1)
    {
        m_x0_i32 = x0;
        m_y0_i32 = y0;
        m_x1_i32 = x1;
        m_y1_i32 = y1;
    }

    /**
     * @brief Получить текущие координаты прямоугольника
     * @param[out] x0, y0, x1, y1 Текущие координаты
     */
    void get_coords(int &x0, int &y0, int &x1, int &y1)
    {
        x0 = m_x0_i32;
        y0 = m_y0_i32;
        x1 = m_x1_i32;
        y1 = m_y1_i32;
    }
};

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @details Создание прямоугольника, проверка точки, вывод результата, освобождение памяти.
 * @return Код завершения (0 — успешно)
 */
int main()
{
    rectangle *ptr_r = new rectangle(-5, 4, 8, 32);
    int x = 0, y = 0;
    std::cin >> x >> y;
    if (ptr_r->is_in_rect(x, y))
        std::cout << "yes" << std::endl;
    else
        std::cout << "no" << std::endl;
    delete ptr_r;
    return 0;
}
