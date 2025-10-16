/************************************************************************
 * @file script8.cpp
 * @brief Шаблонные структуры Point и класс Line
 * @version 1.0
 * @date 2025-10-16
 ************************************************************************/

#include <iostream>

/**
 * @brief Точка в 2D пространстве
 * @tparam T Тип координат
 */
template <typename T>
struct Point
{
    T x{0};
    T y{0};
    Point() = default;
    Point(T x_, T y_) : x(x_), y(y_) {}
};

/**
 * @brief Отрезок, заданный двумя точками sp и ep
 * @tparam D Тип координат
 */
template <typename D>
class Line
{
private:
    Point<D> sp;
    Point<D> ep;

public:
    Line() = default;
    Line(const Point<D> &sp_, const Point<D> &ep_) : sp(sp_), ep(ep_) {}
    Line(D x0, D y0, D x1, D y1) : sp(x0, y0), ep(x1, y1) {}

    Point<D> get_sp() const { return sp; }
    Point<D> get_ep() const { return ep; }

    void set_coords(const Point<D> &sp_, const Point<D> &ep_)
    {
        sp = sp_;
        ep = ep_;
    }
};

int main()
{
    Point<unsigned> sp(1, 2);
    Point<unsigned> ep(11, 54);
    Line<unsigned> line(sp, ep);

    __ASSERT_TESTS__
    return 0;
}
