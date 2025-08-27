/**********************************************************************
 * @file script7.cpp
 * @brief Структуры point3D и line3D: конструкторы, методы, деструктор, main (embedded C++ style)
 * @version 1.0 (Stepik exercise)
 * @date 2025-08-27
 **********************************************************************/

#include <iostream>
#include <cmath>

/**
 * @brief Структура точки в 3D пространстве
 */
struct point3D
{
private:
    int m_x_i32, m_y_i32, m_z_i32;

public:
    point3D() : m_x_i32(0), m_y_i32(0), m_z_i32(0) {}
    point3D(int x, int y, int z) : m_x_i32(x), m_y_i32(y), m_z_i32(z) {}
    /**
     * @brief Получить координаты
     */
    void get_coords(int &x, int &y, int &z) const
    {
        x = m_x_i32;
        y = m_y_i32;
        z = m_z_i32;
    }
};

/**
 * @brief Структура линии в 3D пространстве
 */
struct line3D
{
private:
    point3D m_start_pt;
    point3D m_end_pt;

public:
    line3D(const point3D &start, const point3D &end) : m_start_pt(start), m_end_pt(end) {}
    ~line3D()
    {
        int x0, y0, z0, x1, y1, z1;
        m_start_pt.get_coords(x0, y0, z0);
        m_end_pt.get_coords(x1, y1, z1);
        std::cout << "Deleted line: (" << x0 << ", " << y0 << ", " << z0 << ") ("
                  << x1 << ", " << y1 << ", " << z1 << ")\n";
    }
    /**
     * @brief Длина линии
     */
    double length(void) const
    {
        int x0, y0, z0, x1, y1, z1;
        m_start_pt.get_coords(x0, y0, z0);
        m_end_pt.get_coords(x1, y1, z1);
        return std::sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1) + (z0 - z1) * (z0 - z1));
    }
    /**
     * @brief Получить константную ссылку на стартовую точку
     */
    const point3D &get_coords_start(void) const { return m_start_pt; }
    /**
     * @brief Получить константную ссылку на конечную точку
     */
    const point3D &get_coords_end(void) const { return m_end_pt; }
};

/*** Main Function ***/
int main(void)
{
    line3D line(point3D(-5, 100, 45), point3D(0, 32, -42));
    __ASSERT_TESTS__
    return 0;
}