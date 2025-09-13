/**********************************************************************
 * @file script1.cpp
 * @brief Класс Point: статические границы, проверка координат, методы вне класса
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-12
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс для хранения точки с границами
 */
class Point
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    Point();
    /**
     * @brief Конструктор с параметрами
     * @param[in] x x
     * @param[in] y y
     */
    Point(int x, int y);
    /**
     * @brief Установить координаты
     * @param[in] x x
     * @param[in] y y
     */
    void set_coords(int x, int y);
    /**
     * @brief Получить x
     * @return int
     */
    int get_x();
    /**
     * @brief Получить y
     * @return int
     */
    int get_y();
    /**
     * @brief Установить границы (статический)
     * @param[in] left левая граница
     * @param[in] right правая граница
     */
    static void set_bounds(int left, int right);
    /**
     * @brief Получить границы (статический)
     * @param[out] left левая граница
     * @param[out] right правая граница
     */
    static void get_bounds(int &left, int &right);

private:
    static int m_MIN_COORD;
    static int m_MAX_COORD;
    int m_x{0}, m_y{0};
    /**
     * @brief Проверить координату
     * @param[in] coord координата
     * @return true если в границах
     */
    bool check_coord(int coord);
};

/*** Static Members Initialization ***/
int Point::m_MIN_COORD = 0;
int Point::m_MAX_COORD = 10;

/*** Methods Implementation ***/
Point::Point() : m_x(0), m_y(0) {}

Point::Point(int x, int y) : m_x(0), m_y(0)
{
    if (check_coord(x) && check_coord(y))
    {
        m_x = x;
        m_y = y;
    }
}

void Point::set_coords(int x, int y)
{
    if (check_coord(x) && check_coord(y))
    {
        m_x = x;
        m_y = y;
    }
}

int Point::get_x() { return m_x; }
int Point::get_y() { return m_y; }

void Point::set_bounds(int left, int right)
{
    m_MIN_COORD = left;
    m_MAX_COORD = right;
}

void Point::get_bounds(int &left, int &right)
{
    left = m_MIN_COORD;
    right = m_MAX_COORD;
}

bool Point::check_coord(int coord)
{
    return coord >= m_MIN_COORD && coord <= m_MAX_COORD;
}

/*** Main Function ***/
int main(void)
{
    Point::set_bounds(-100, 100);
    Point pt(-5, 7);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

        return 0;
}
