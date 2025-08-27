/**********************************************************************
 * @file script2.cpp
 * @brief Структура point: приватные поля, публичные методы, main (embedded C++ style)
 * @version 1.0 (Stepik exercise)
 * @date 2025-08-27
 **********************************************************************/

#include <iostream>

/**
 * @brief Структура точки с приватными координатами и публичными методами
 */
struct point
{
private:
    int m_x_i32;
    int m_y_i32;

public:
    /**
     * @brief Получить координату x
     * @return x
     */
    int get_x(void) const { return m_x_i32; }
    /**
     * @brief Получить координату y
     * @return y
     */
    int get_y(void) const { return m_y_i32; }
    /**
     * @brief Получить обе координаты
     * @param[out] x x
     * @param[out] y y
     */
    void get_coords(int &x, int &y) const
    {
        x = m_x_i32;
        y = m_y_i32;
    }
    /**
     * @brief Установить координаты
     * @param[in] x x
     * @param[in] y y
     */
    void set_coords(int x, int y)
    {
        m_x_i32 = x;
        m_y_i32 = y;
    }
    /**
     * @brief Суммировать две точки
     * @param[in] p1 Первая точка
     * @param[in] p2 Вторая точка
     * @return Новая точка с суммой координат
     */
    static point sum(point &p1, point &p2)
    {
        point res;
        res.m_x_i32 = p1.m_x_i32 + p2.m_x_i32;
        res.m_y_i32 = p1.m_y_i32 + p2.m_y_i32;
        return res;
    }
};

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 * @return Код завершения (0 — успешно, 1 — ошибка памяти)
 */
int main(void)
{
    point pt1, pt2;
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    pt1.set_coords(x1, y1);
    pt2.set_coords(x2, y2);
    point pt_sum = point::sum(pt1, pt2);
    std::cout << pt_sum.get_x() << " " << pt_sum.get_y() << std::endl;
    return 0;
}