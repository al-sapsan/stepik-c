/**********************************************************************
 * @file script4.cpp
 * @brief struct Point, class PolyLine: приватные поля, методы, main
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-06
 **********************************************************************/

/*** Core ***/
#include <iostream>

struct Point
{
    short x, y;
};

/*** Class Definition ***/
/**
 * @brief Класс для хранения полилинии (массива точек)
 */
class PolyLine
{
private:
    enum
    {
        max_coords = 10
    };
    Point m_coords[max_coords];
    int m_total_i32;

public:
    /*** Constructors ***/
    /**
     * @brief Конструктор по умолчанию (без координат)
     */
    PolyLine() : m_total_i32(0) {}
    /**
     * @brief Конструктор с массивом координат
     * @param[in] ar массив точек
     * @param[in] size количество точек
     */
    PolyLine(const Point *ar, int size) : m_total_i32(0)
    {
        set_coords(ar, size);
    }

    /*** Methods Implementation ***/
    /**
     * @brief Установить координаты из массива
     * @param[in] ar массив точек
     * @param[in] size количество точек
     */
    void set_coords(const Point *ar, int size)
    {
        m_total_i32 = (size > max_coords) ? max_coords : size;
        for (int i = 0; i < m_total_i32; ++i)
        {
            m_coords[i] = ar[i];
        }
    }
    /**
     * @brief Добавить координату в конец
     * @param[in] pt точка
     */
    void append_coord(Point pt)
    {
        if (m_total_i32 < max_coords)
        {
            m_coords[m_total_i32++] = pt;
        }
    }
    /**
     * @brief Получить указатель на массив координат
     * @return указатель на массив
     */
    const Point *get_coords() { return m_coords; }
    /**
     * @brief Получить количество точек
     * @return количество точек
     */
    int get_total() { return m_total_i32; }
};

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @details Создает объекты PolyLine, добавляет координаты
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    Point coords[20];
    for (int i = 0; i < 20; ++i)
    {
        coords[i].x = i + 1;
        coords[i].y = i + 2;
    }
    PolyLine poly(coords, 20);
    PolyLine pl;
    pl.append_coord(coords[19]);
    return 0;
}
