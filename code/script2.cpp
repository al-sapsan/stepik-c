/************************************************************************
 * @file script2.cpp
 * @brief Функция sum_coords — сумма координат объектов (шаблон)
 * @date 2025-10-16
 ************************************************************************/

#include <iostream>

class Point
{
    double x{0}, y{0};

public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    void get_coords(double &x, double &y) const
    {
        x = this->x;
        y = this->y;
    }
};

class Vector
{
    int x{0}, y{0};

public:
    Vector(int x = 0, int y = 0) : x(x), y(y) {}
    void get_coords(int &x, int &y) const
    {
        x = this->x;
        y = this->y;
    }
};

/**
 * @brief Шаблонная функция для суммирования координат
 * @tparam Obj Тип объекта (должен иметь метод get_coords)
 * @tparam CoordT Тип координат (по умолчанию double)
 * @param obj Константная ссылка на объект
 * @return Сумма координат в типе CoordT
 */
template <typename Obj, typename CoordT = double>
CoordT sum_coords(const Obj &obj)
{
    CoordT a{};
    CoordT b{};
    obj.get_coords(a, b);
    return a + b;
}

int main()
{
    Point p(10.5, -4.7);
    Vector v(132, 55);

    double sm1 = sum_coords<Point, double>(p);
    int sm2 = sum_coords<Vector, int>(v);

    (void)sm1;
    (void)sm2;

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

        return 0;
}
