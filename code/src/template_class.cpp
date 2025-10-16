/************************************************************************
 * @file script6.cpp
 * @brief Шаблонный класс Vector2D для радиус-вектора
 * @version 1.0
 * @date 2025-10-16
 ************************************************************************/

#include <iostream>

/**
 * @brief Класс радиус-вектора с координатами x, y
 * @tparam T Тип координат
 */
template <typename T>
class Vector2D
{
private:
    T x{0}; ///< координата x
    T y{0}; ///< координата y
public:
    /**
     * @brief Конструктор по умолчанию
     */
    Vector2D() = default;

    /**
     * @brief Конструктор с параметрами
     * @param x_ координата x
     * @param y_ координата y
     */
    Vector2D(T x_, T y_) : x(x_), y(y_) {}

    /**
     * @brief Получить x
     * @return x
     */
    T get_x() const { return x; }

    /**
     * @brief Получить y
     * @return y
     */
    T get_y() const { return y; }

    /**
     * @brief Задать x и y
     * @param x_ новое значение x
     * @param y_ новое значение y
     */
    void set_xy(T x_, T y_)
    {
        x = x_;
        y = y_;
    }
};

int main()
{
    Vector2D<double> vector(-54.2, 10.8);

    __ASSERT_TESTS__ // макроопределение для тестирования
        return 0;
}