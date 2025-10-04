/**********************************************************************
 * @file script4.cpp
 * @brief ArrayInt class implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-10-03
 **********************************************************************/

#include <cstddef> // for size_t
#include <stdexcept>

/********** Class Definition **********/
/**
 * @brief Класс для хранения массива целых чисел
 * @param data Массив целых чисел
 * @param size Размер массива
 */
class ArrayInt
{
private:
    int *m_data{nullptr};
    size_t m_size{0};

public:
    ArrayInt() = default;

    ArrayInt(int *d, size_t length)
        : m_data(nullptr), m_size(0)
    {
        set_data(d, length);
    }

    void set_data(int *d, size_t length)
    {
        if (m_data)
            delete[] m_data;
        m_size = length;
        m_data = (length > 0) ? new int[length] : nullptr;
        for (size_t i = 0; i < length; ++i)
            m_data[i] = d[i];
    }

    int *get_data() { return m_data; }
    size_t get_size() const { return m_size; }

    int &operator[](size_t index)
    {
        if (index >= m_size)
            throw std::runtime_error("Incorrect index.");
        return m_data[index];
    }

    const int &operator[](size_t index) const
    {
        if (index >= m_size)
            throw std::runtime_error("Incorrect index.");
        return m_data[index];
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }
};