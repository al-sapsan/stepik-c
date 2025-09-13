/**********************************************************************
 * @file script4.cpp
 * @brief Класс Array: создание только через статические методы create, деструктор
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-12
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <cstddef>

/*** Class Definition ***/
/**
 * @brief Класс Array с приватными конструкторами и статическими фабриками
 */
class Array
{
    double *data{nullptr};
    size_t size{0};
    /**
     * @brief Приватный конструктор по умолчанию
     */
    Array() = default;
    /**
     * @brief Приватный конструктор с размером
     * @param[in] n размер массива
     */
    Array(size_t n) : data(new double[n]{}), size(n) {}
    /**
     * @brief Приватный конструктор с массивом
     * @param[in] d массив
     * @param[in] n размер
     */
    Array(const double *d, size_t n) : data(new double[n]), size(n)
    {
        for (size_t i = 0; i < n; ++i)
            data[i] = d[i];
    }
    /**
     * @brief Приватный копирующий конструктор
     */
    Array(const Array &) = delete;
    Array &operator=(const Array &) = delete;

public:
    /**
     * @brief Деструктор: освобождает память
     */
    ~Array() { delete[] data; }
    /**
     * @brief Создать массив заданной длины
     * @param[in] n длина
     * @return указатель на Array
     */
    static Array *create(size_t n) { return new Array(n); }
    /**
     * @brief Создать массив из данных
     * @param[in] d массив
     * @param[in] n длина
     * @return указатель на Array
     */
    static Array *create(const double *d, size_t n) { return new Array(d, n); }
    /**
     * @brief Установить данные
     * @param[in] d массив
     * @param[in] length длина
     */
    void set_data(double *d, size_t length)
    {
        delete[] data;
        size = length;
        data = new double[size];
        for (size_t i = 0; i < size; ++i)
            data[i] = d[i];
    }
    /**
     * @brief Получить данные
     * @return double*
     */
    double *get_data() { return data; }
    /**
     * @brief Получить размер
     * @return size_t
     */
    size_t get_size() { return size; }
};