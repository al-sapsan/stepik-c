/**********************************************************************
 * @file script2.cpp
 * @brief Point class implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-10-03
 **********************************************************************/

#include <iostream>
#include <stdexcept>

/********** Class Definition **********/

class Point
{
    enum
    {
        min_coord = -10,
        max_coord = 10
    };
    int m_x{0}, m_y{0};

    static void check_coord(int x, int y)
    {
        if (x < min_coord || x > max_coord || y < min_coord || y > max_coord)
            throw std::string("Incorrect coordinate values.");
    }

public:
    Point() : m_x(0), m_y(0) {}

    Point(int x) : m_x(x), m_y(0)
    {
        check_coord(m_x, m_y);
    }

    Point(int x, int y) : m_x(x), m_y(y)
    {
        check_coord(m_x, m_y);
    }
};

/********** Main Function **********/

int main(void)
{
    try
    {
        Point point(11, -5);
    }
    catch (const std::string &ex)
    {
        std::cout << ex << std::endl;
    }

    __ASSERT_TESTS__

    return 0;
}