/************************************************************************
 * @file script1.cpp
 * @brief Вычисление площади треугольника по формуле Герона (шаблонная функция)
 * @version 1.0 (Embedded C++)
 * @date 2025-10-16
 ************************************************************************/

#include <iostream>
#include <type_traits>
#include <cmath>

/**
 * @brief Вычисляет площадь треугольника по формуле Герона
 * @tparam A Тип стороны a
 * @tparam B Тип стороны b
 * @tparam C Тип стороны c
 * @param a Длина стороны a
 * @param b Длина стороны b
 * @param c Длина стороны c
 * @return Площадь треугольника в общем типе аргументов
 */
template <typename A, typename B, typename C>
double tr_square(A a, B b, C c)
{
    // Вычисляем в двойной точности, чтобы избежать целочисленного усечения
    const double ca = static_cast<double>(a);
    const double cb = static_cast<double>(b);
    const double cc = static_cast<double>(c);
    const double p = (ca + cb + cc) / 2.0;
    const double prod = p * (p - ca) * (p - cb) * (p - cc);
    if (prod <= 0.0)
        return 0.0;
    return std::sqrt(prod);
}

int main()
{
    // вызовы функции tr_square с требуемыми наборами аргументов
    double res_1 = tr_square(10, 6, 8);
    double res_2 = tr_square(5.3, 2.7, 7);
    double res_3 = tr_square(90, 'a', 55.4);

    (void)res_1;
    (void)res_2;
    (void)res_3;

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

        return 0;
}
