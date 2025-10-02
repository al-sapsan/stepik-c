/**********************************************************************
 * @file script4.cpp
 * @brief Vector3D class implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-10-02
 **********************************************************************/

#include <cmath> // for std::sqrt

/********** Class Definition **********/

// == < Vector3D > == //
/**
 * @brief Класс трехмерного вектора
 * @param x, y, z Координаты
 */
class Vector3D
{
private:
    int m_x{0}, m_y{0}, m_z{0};

public:
    Vector3D(int a = 0, int b = 0, int c = 0) : m_x(a), m_y(b), m_z(c) {}

    void set_data(int a, int b, int c)
    {
        m_x = a;
        m_y = b;
        m_z = c;
    }

    int &operator[](int idx)
    {
        if (idx == 0)
            return m_x;
        if (idx == 1)
            return m_y;
        // idx == 2
        return m_z;
    }

    const int &operator[](int idx) const
    {
        if (idx == 0)
            return m_x;
        if (idx == 1)
            return m_y;
        // idx == 2
        return m_z;
    }

    operator double() const
    {
        return std::sqrt(static_cast<double>(m_x * m_x + m_y * m_y + m_z * m_z));
    }
};