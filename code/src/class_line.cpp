/**********************************************************************
 * @file script3.cpp
 * @brief struct Point, class Line: приватные поля, методы, main
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
 * @brief Класс для хранения линии по двум точкам
 */
class Line
{
private:
    short m_x0_i16, m_y0_i16, m_x1_i16, m_y1_i16;

public:
    /*** Constructors ***/
    /**
     * @brief Конструктор по умолчанию (все координаты 0)
     */
    Line() : m_x0_i16(0), m_y0_i16(0), m_x1_i16(0), m_y1_i16(0) {}
    /**
     * @brief Конструктор по координатам
     * @param[in] a x0
     * @param[in] b y0
     * @param[in] c x1
     * @param[in] d y1
     */
    Line(short a, short b, short c, short d) : m_x0_i16(a), m_y0_i16(b), m_x1_i16(c), m_y1_i16(d) {}
    /**
     * @brief Конструктор по двум точкам
     * @param[in] sp начальная точка
     * @param[in] ep конечная точка
     */
    Line(Point sp, Point ep) : m_x0_i16(sp.x), m_y0_i16(sp.y), m_x1_i16(ep.x), m_y1_i16(ep.y) {}

    /*** Methods Implementation ***/
    /**
     * @brief Установить координаты по значениям
     * @param[in] a x0
     * @param[in] b y0
     * @param[in] c x1
     * @param[in] d y1
     */
    void set_coords(short a, short b, short c, short d)
    {
        m_x0_i16 = a;
        m_y0_i16 = b;
        m_x1_i16 = c;
        m_y1_i16 = d;
    }
    /**
     * @brief Установить координаты по двум точкам
     * @param[in] sp начальная точка
     * @param[in] ep конечная точка
     */
    void set_coords(Point sp, Point ep)
    {
        m_x0_i16 = sp.x;
        m_y0_i16 = sp.y;
        m_x1_i16 = ep.x;
        m_y1_i16 = ep.y;
    }
    /**
     * @brief Получить начальную точку
     * @return Point (x0, y0)
     */
    Point get_start() { return Point{m_x0_i16, m_y0_i16}; }
    /**
     * @brief Получить конечную точку
     * @return Point (x1, y1)
     */
    Point get_end() { return Point{m_x1_i16, m_y1_i16}; }
};

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @details Создает объекты Line, выводит координаты, освобождает память
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    Point sp, ep;
    short a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cin >> sp.x >> sp.y >> ep.x >> ep.y;
    Line *ptr_ln1 = new Line(a, b, c, d);
    Line *ptr_ln2 = new Line(sp, ep);
    Point s1 = ptr_ln1->get_start();
    Point e1 = ptr_ln1->get_end();
    Point s2 = ptr_ln2->get_start();
    Point e2 = ptr_ln2->get_end();
    std::cout << s1.x << " " << s1.y << " " << e1.x << " " << e1.y << " ";
    std::cout << s2.x << " " << s2.y << " " << e2.x << " " << e2.y << std::endl;
    delete ptr_ln1;
    delete ptr_ln2;
    return 0;
}
