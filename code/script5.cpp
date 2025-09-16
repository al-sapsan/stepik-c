/**********************************************************************
 * @file script5.cpp
 * @brief Класс Array: динамический массив, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-15
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <cstddef>

/*** Class Definition ***/
/**
 * @brief Класс Array: динамический массив
 */
class Array
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    Array();
    /**
     * @brief Конструктор копирования из массива
     * @param[in] d указатель на массив
     * @param[in] length размер массива
     */
    Array(const int *d, size_t length);
    /**
     * @brief Конструктор копирования
     * @param[in] other другой объект Array
     */
    Array(const Array &other);
    /**
     * @brief Деструктор
     */
    ~Array();
    /**
     * @brief Оператор присваивания
     * @param[in] other другой объект Array
     * @return Array&
     */
    Array &operator=(const Array &other);
    /**
     * @brief Оператор сложения
     * @param[in] other другой объект Array
     * @return Array
     */
    Array operator+(const Array &other) const;
    /**
     * @brief Установить данные массива
     * @param[in] d указатель на массив
     * @param[in] length размер массива
     */
    void set_data(const int *d, size_t length);
    /**
     * @brief Получить данные массива
     * @return int*
     */
    int *get_data();
    /**
     * @brief Получить размер массива
     * @return size_t
     */
    size_t get_size() const;

private:
    int *m_data{nullptr};
    size_t m_size{0};
};

/*** Methods Implementation ***/
Array::Array() : m_data(nullptr), m_size(0) {}
Array::Array(const int *d, size_t length) : m_data(nullptr), m_size(0)
{
    set_data(d, length);
}
Array::Array(const Array &other) : m_data(nullptr), m_size(0)
{
    set_data(other.m_data, other.m_size);
}
Array::~Array()
{
    delete[] m_data;
}
Array &Array::operator=(const Array &other)
{
    if (this != &other)
    {
        set_data(other.m_data, other.m_size);
    }
    return *this;
}
Array Array::operator+(const Array &other) const
{
    Array result;
    result.m_size = m_size + other.m_size;
    result.m_data = new int[result.m_size];
    for (size_t i = 0; i < m_size; ++i)
    {
        result.m_data[i] = m_data[i];
    }
    for (size_t i = 0; i < other.m_size; ++i)
    {
        result.m_data[m_size + i] = other.m_data[i];
    }
    return result;
}
void Array::set_data(const int *d, size_t length)
{
    if (m_data != nullptr)
    {
        delete[] m_data;
    }
    m_size = length;
    if (m_size > 0)
    {
        m_data = new int[m_size];
        for (size_t i = 0; i < m_size; ++i)
        {
            m_data[i] = d[i];
        }
    }
    else
    {
        m_data = nullptr;
    }
}
int *Array::get_data()
{
    return m_data;
}
size_t Array::get_size() const
{
    return m_size;
}
