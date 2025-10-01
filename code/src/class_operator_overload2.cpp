/**********************************************************************
 * @file script9.cpp
 * @brief LimitLength class implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-10-01
 **********************************************************************/

/********** Class Definition **********/
// == < LimitLength > == //
/**
 * @brief Класс ограничения длины
 * @param length Текущее значение
 */
class LimitLength
{
    enum
    {
        min_length = -10,
        max_length = 10
    };
    int m_length{0};

    static int clamp(int val)
    {
        if (val < min_length)
            return min_length;
        if (val > max_length)
            return max_length;
        return val;
    }

public:
    LimitLength(int len = 0) : m_length(clamp(len)) {}

    int get_length() const { return m_length; }

    // Post-increment
    int operator++(int)
    {
        int old = m_length;
        m_length = clamp(m_length + 1);
        return old;
    }

    // Pre-increment
    int operator++()
    {
        m_length = clamp(m_length + 1);
        return m_length;
    }

    // Post-decrement
    int operator--(int)
    {
        int old = m_length;
        m_length = clamp(m_length - 1);
        return old;
    }

    // Pre-decrement
    int operator--()
    {
        m_length = clamp(m_length - 1);
        return m_length;
    }

    int operator+=(int val)
    {
        m_length = clamp(m_length + val);
        return m_length;
    }

    int operator-=(int val)
    {
        m_length = clamp(m_length - val);
        return m_length;
    }

    int operator*=(int val)
    {
        m_length = clamp(m_length * val);
        return m_length;
    }

    int operator/=(int val)
    {
        if (val == 0)
            return m_length; // avoid division by zero
        m_length = clamp(m_length / val);
        return m_length;
    }
};