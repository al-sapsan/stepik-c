/************************************************************************
 * @file script9.cpp
 * @brief Шаблонный класс Array для хранения массива элементов типа T
 * @version 1.0
 * @date 2025-10-16
 ************************************************************************/

#include <cstddef>
#include <algorithm>
#include <iterator>

/**
 * @brief Динамический массив с элементами типа T
 * @tparam T Тип элементов (по умолчанию int)
 */
template <typename T = int>
class Array
{
    T *data{nullptr};
    size_t size{0};

public:
    Array() = default;

    Array(const T *d, size_t size_) : size(size_)
    {
        if (size_ > 0)
        {
            data = new T[size_];
            for (size_t i = 0; i < size_; ++i)
                data[i] = d[i];
        }
    }

    Array(const Array &other)
    {
        size = other.size;
        if (size > 0)
        {
            data = new T[size];
            for (size_t i = 0; i < size; ++i)
                data[i] = other.data[i];
        }
        else
            data = nullptr;
    }

    ~Array() { delete[] data; }

    Array operator+(const Array &right) const
    {
        Array array_obj;
        array_obj.size = size + right.size;
        if (array_obj.size > 0)
        {
            array_obj.data = new T[array_obj.size];
            size_t idx = 0;
            for (size_t i = 0; i < size; ++i)
                array_obj.data[idx++] = data[i];
            for (size_t i = 0; i < right.size; ++i)
                array_obj.data[idx++] = right.data[i];
        }
        return array_obj;
    }

    const Array &operator=(const Array &right)
    {
        if (this == &right)
            return *this;
        delete[] data;
        size = right.size;
        if (size > 0)
        {
            data = new T[size];
            for (size_t i = 0; i < size; ++i)
                data[i] = right.data[i];
        }
        else
            data = nullptr;
        return *this;
    }

    const T *get_data() const { return data; }
    size_t get_length() const { return size; }
};
