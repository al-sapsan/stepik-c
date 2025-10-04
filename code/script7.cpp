/**********************************************************************
 * @file script7.cpp
 * @brief Vector3D class implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-10-04
 **********************************************************************/

#include <iostream>
#include <string>

/********** Class Definition **********/
class Vector3D
{
private:
    enum
    {
        min_coord = -100,
        max_coord = 100
    };
    int m_x{0}, m_y{0}, m_z{0};

    static bool is_valid(int v) { return v >= min_coord && v <= max_coord; }

public:
    Vector3D() = default;

    Vector3D(int x, int y, int z)
    {
        if (!is_valid(x) || !is_valid(y) || !is_valid(z))
            throw -2;
        m_x = x;
        m_y = y;
        m_z = z;
    }

    void get_coords(int &x, int &y, int &z) const
    {
        x = m_x;
        y = m_y;
        z = m_z;
    }

    void set_coords(int x, int y, int z)
    {
        if (!is_valid(x) || !is_valid(y) || !is_valid(z))
            throw -1;
        m_x = x;
        m_y = y;
        m_z = z;
    }

    int &operator[](int idx)
    {
        if (idx == 0)
            return m_x;
        if (idx == 1)
            return m_y;
        if (idx == 2)
            return m_z;
        throw "Incorrect index.";
    }

    const int &operator[](int idx) const
    {
        if (idx == 0)
            return m_x;
        if (idx == 1)
            return m_y;
        if (idx == 2)
            return m_z;
        throw "Incorrect index.";
    }
};

/********** Main Function **********/
int main(void)
{
    try
    {
        Vector3D v3(10, 1000, -500);
    }
    catch (int ex)
    {
        std::cout << ex << std::endl;
    }
    catch (const char *msg)
    {
        std::cout << msg << std::endl;
    }

    __ASSERT_TESTS__

    return 0;
}