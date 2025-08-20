/**********************************************************************
 * @file script2.cpp
 * @brief Вычисление площади треугольника и прямоугольника
 * @version 1.0
 * @date 2025-08-20
 **********************************************************************/

/*** Libraries ***/
#include <iostream>
#include <iomanip>
#include <cmath>

/*** Usings ***/
using std::cin;
using std::cout;
using std::endl;

/*** Function Prototypes ***/
/**
 * @brief Вычисляет площадь треугольника по трем сторонам
 * @param a Сторона 1
 * @param b Сторона 2
 * @param c Сторона 3
 * @return double Площадь
 */
double get_square(int a, int b, int c);

/**
 * @brief Вычисляет площадь прямоугольника
 * @param a Сторона 1
 * @param b Сторона 2
 * @return int Площадь
 */
int get_square(int a, int b);

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main()
{
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    cin >> a >> b >> c >> d >> e;
    double area_triangle = get_square(a, b, c);
    int area_rectangle = get_square(d, e);
    cout << std::fixed << std::setprecision(1) << area_triangle << " " << static_cast<double>(area_rectangle) << endl;
    return 0;
}

/*** Function Implementation ***/
double get_square(int a, int b, int c)
{
    double p = (a + b + c) / 2.0;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

int get_square(int a, int b)
{
    return a * b;
}
