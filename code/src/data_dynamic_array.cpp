/************************************************************************
 * @file    vector.hpp
 * @brief   Реализация класса динамического массива Vector и исключения VectorIndexError
 * @version 1.0
 * @date    2025-10-17
 ************************************************************************/

#include <cstddef>
#include <stdexcept>
#include <iostream>

/**
 * @brief Исключение для некорректного индекса динамического массива
 */
class VectorIndexError : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid element index.";
    }
};

/**
 * @brief Шаблонный класс динамического массива (Vector)
 * @tparam T Тип элементов массива
 */
template <typename T>
class Vector
{
    T *data{nullptr};         ///< Указатель на динамический массив
    size_t length{0};         ///< Текущее число элементов
    size_t capacity_value{8}; ///< Ёмкость (размер выделенной памяти)

    /**
     * @brief Увеличивает емкость массива вдвое и копирует старые элементы
     */
    void expand_capacity()
    {
        capacity_value *= 2;
        T *new_data = new T[capacity_value];
        for (size_t i = 0; i < length; ++i)
            new_data[i] = data[i];
        delete[] data;
        data = new_data;
    }

public:
    /*** Конструкторы и деструктор ***/
    Vector() : data(new T[capacity_value]) {}
    ~Vector() { delete[] data; }

    Vector(const Vector &other) : data(new T[other.capacity_value]),
                                  length(other.length),
                                  capacity_value(other.capacity_value)
    {
        for (size_t i = 0; i < length; ++i)
            data[i] = other.data[i];
    }

    Vector &operator=(const Vector &other)
    {
        if (this != &other)
        {
            delete[] data;
            capacity_value = other.capacity_value;
            length = other.length;
            data = new T[capacity_value];
            for (size_t i = 0; i < length; ++i)
                data[i] = other.data[i];
        }
        return *this;
    }

    /*** Методы вставки и удаления ***/
    void push_back(const T &value)
    {
        if (length >= capacity_value)
            expand_capacity();
        data[length++] = value;
    }

    void push_front(const T &value)
    {
        if (length >= capacity_value)
            expand_capacity();
        for (size_t i = length; i > 0; --i)
            data[i] = data[i - 1];
        data[0] = value;
        ++length;
    }

    void pop_back()
    {
        if (length > 0)
            --length;
    }

    void pop_front()
    {
        if (length == 0)
            return;
        for (size_t i = 0; i < length - 1; ++i)
            data[i] = data[i + 1];
        --length;
    }

    void insert(int index, const T &value)
    {
        if (index < 0 || static_cast<size_t>(index) > length)
            throw VectorIndexError();

        if (length >= capacity_value)
            expand_capacity();

        for (size_t i = length; i > static_cast<size_t>(index); --i)
            data[i] = data[i - 1];

        data[index] = value;
        ++length;
    }

    void remove(int index)
    {
        if (index < 0 || static_cast<size_t>(index) >= length)
            throw VectorIndexError();

        for (size_t i = static_cast<size_t>(index); i < length - 1; ++i)
            data[i] = data[i + 1];

        --length;
    }

    /*** Операторы доступа по индексу ***/
    T &operator[](int index)
    {
        if (index < 0 || static_cast<size_t>(index) >= length)
            throw VectorIndexError();
        return data[index];
    }

    const T &operator[](int index) const
    {
        if (index < 0 || static_cast<size_t>(index) >= length)
            throw VectorIndexError();
        return data[index];
    }

    /*** Методы состояния и информации ***/
    size_t size() const noexcept { return length; }
    size_t capacity() const noexcept { return capacity_value; }
    bool empty() const noexcept { return length == 0; }

    void clear() noexcept { length = 0; }

    /*** Операторы сложения ***/
    Vector &operator+=(const Vector &other)
    {
        for (size_t i = 0; i < other.length; ++i)
            push_back(other.data[i]);
        return *this;
    }

    friend Vector operator+(const Vector &lhs, const Vector &rhs)
    {
        Vector result(lhs);
        result += rhs;
        return result;
    }
};
