/**********************************************************************
 * @file script8.cpp
 * @brief Класс PointND, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-20
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <cstddef>

/*** Class Definition ***/
/**
 * @brief Класс PointND: точка в N-мерном пространстве
 */
class PointND
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    PointND();
    /**
     * @brief Конструктор с координатами
     * @param[in] cds массив координат
     * @param[in] len размерность
     */
    PointND(const short *cds, size_t len);
    /**
     * @brief Конструктор копирования
     * @param[in] other другой объект PointND
     */
    PointND(const PointND &other);
    /**
     * @brief Деструктор
     */
    ~PointND();
    /**
     * @brief Оператор присваивания (глубокое копирование)
     * @param[in] other другой объект PointND
     * @return PointND&
     */
    PointND &operator=(const PointND &other);
    /**
     * @brief Оператор доступа по индексу
     * @param[in] idx индекс
     * @return short&
     */
    short &operator[](size_t idx);
    /**
     * @brief Оператор доступа по индексу (const)
     * @param[in] idx индекс
     * @return short
     */
    short operator[](size_t idx) const;
    /**
     * @brief Оператор постфиксного инкремента
     * @return PointND&
     */
    PointND &operator++(int);
    /**
     * @brief Оператор префиксного инкремента
     * @return PointND&
     */
    PointND &operator++();
    /**
     * @brief Оператор постфиксного декремента
     * @return PointND&
     */
    PointND &operator--(int);
    /**
     * @brief Оператор префиксного декремента
     * @return PointND&
     */
    PointND &operator--();
    /**
     * @brief Оператор += (PointND)
     * @param[in] other
     * @return PointND&
     */
    PointND &operator+=(const PointND &other);
    /**
     * @brief Оператор -= (PointND)
     * @param[in] other
     * @return PointND&
     */
    PointND &operator-=(const PointND &other);
    /**
     * @brief Получить размерность
     * @return size_t
     */
    size_t get_dims() const;

private:
    short *coords{nullptr};
    size_t dims{0};
};

/*** Methods Implementation ***/
PointND::PointND() : coords(nullptr), dims(0) {}
PointND::PointND(const short *cds, size_t len) : coords(nullptr), dims(len)
{
    if (dims > 0)
    {
        coords = new short[dims];
        for (size_t i = 0; i < dims; ++i)
            coords[i] = cds[i];
    }
}
PointND::PointND(const PointND &other) : coords(nullptr), dims(other.dims)
{
    if (dims > 0)
    {
        coords = new short[dims];
        for (size_t i = 0; i < dims; ++i)
            coords[i] = other.coords[i];
    }
}
PointND::~PointND()
{
    delete[] coords;
}
PointND &PointND::operator=(const PointND &other)
{
    if (this != &other)
    {
        delete[] coords;
        dims = other.dims;
        if (dims > 0)
        {
            coords = new short[dims];
            for (size_t i = 0; i < dims; ++i)
                coords[i] = other.coords[i];
        }
        else
        {
            coords = nullptr;
        }
    }
    return *this;
}
short &PointND::operator[](size_t idx)
{
    static short dummy = 0;
    if (idx < dims)
        return coords[idx];
    return dummy;
}
short PointND::operator[](size_t idx) const
{
    if (idx < dims)
        return coords[idx];
    return 0;
}
PointND &PointND::operator++(int)
{
    for (size_t i = 0; i < dims; ++i)
        ++coords[i];
    return *this;
}
PointND &PointND::operator++()
{
    for (size_t i = 0; i < dims; ++i)
        ++coords[i];
    return *this;
}
PointND &PointND::operator--(int)
{
    for (size_t i = 0; i < dims; ++i)
        --coords[i];
    return *this;
}
PointND &PointND::operator--()
{
    for (size_t i = 0; i < dims; ++i)
        --coords[i];
    return *this;
}
PointND &PointND::operator+=(const PointND &other)
{
    if (dims == other.dims)
    {
        for (size_t i = 0; i < dims; ++i)
            coords[i] += other.coords[i];
    }
    return *this;
}
PointND &PointND::operator-=(const PointND &other)
{
    if (dims == other.dims)
    {
        for (size_t i = 0; i < dims; ++i)
            coords[i] -= other.coords[i];
    }
    return *this;
}
size_t PointND::get_dims() const { return dims; }
