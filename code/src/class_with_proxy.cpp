/**********************************************************************
 * @file script3.cpp
 * @brief Класс Box3D, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-18
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс Box3D: габаритная коробка
 */
class Box3D
{
public:
    /**
     * @brief Прокси для безопасного присваивания
     */
    class DimProxy
    {
    public:
        DimProxy(short &ref) : ref_(ref) {}
        DimProxy &operator=(short val)
        {
            if (val > 0)
                ref_ = val;
            return *this;
        }
        operator short() const { return ref_; }

    private:
        short &ref_;
    };
    /**
     * @brief Конструктор по умолчанию
     */
    Box3D();
    /**
     * @brief Конструктор с параметрами
     * @param[in] a длина
     * @param[in] b ширина
     * @param[in] c высота
     */
    Box3D(short a, short b, short c);
    /**
     * @brief Получить габариты
     * @param[out] a
     * @param[out] b
     * @param[out] c
     */
    void get_dims(short &a, short &b, short &c) const;
    /**
     * @brief Установить габариты
     * @param[in] a
     * @param[in] b
     * @param[in] c
     */
    void set_dims(short a, short b, short c);
    /**
     * @brief Оператор доступа по индексу
     * @param[in] idx индекс (0-a, 1-b, 2-c)
     * @return DimProxy
     */
    DimProxy operator[](size_t idx);
    /**
     * @brief Оператор доступа по индексу (const)
     * @param[in] idx индекс (0-a, 1-b, 2-c)
     * @return short
     */
    short operator[](size_t idx) const;
    /**
     * @brief Оператор преобразования к int (объем)
     * @return int
     */
    operator int() const;

private:
    short a{0}, b{0}, c{0};
};

/*** Methods Implementation ***/
Box3D::Box3D() : a(0), b(0), c(0) {}
Box3D::Box3D(short a_, short b_, short c_) : a(a_ > 0 ? a_ : 0), b(b_ > 0 ? b_ : 0), c(c_ > 0 ? c_ : 0) {}
void Box3D::get_dims(short &a_, short &b_, short &c_) const
{
    a_ = a;
    b_ = b;
    c_ = c;
}
void Box3D::set_dims(short a_, short b_, short c_)
{
    if (a_ > 0)
        a = a_;
    if (b_ > 0)
        b = b_;
    if (c_ > 0)
        c = c_;
}
Box3D::DimProxy Box3D::operator[](size_t idx)
{
    if (idx == 0)
        return DimProxy(a);
    if (idx == 1)
        return DimProxy(b);
    if (idx == 2)
        return DimProxy(c);
    static short dummy = 0;
    return DimProxy(dummy);
}
short Box3D::operator[](size_t idx) const
{
    if (idx == 0)
        return a;
    if (idx == 1)
        return b;
    if (idx == 2)
        return c;
    return 0;
}
Box3D::operator int() const
{
    return static_cast<int>(a) * static_cast<int>(b) * static_cast<int>(c);
}
