/**********************************************************************
 * @file script1.cpp
 * @brief Перегруженные функции для вычисления периметра
 * @version 1.0
 * @date 2025-08-20
 **********************************************************************/

/*** Function Prototypes ***/
/**
 * @brief Вычисляет периметр треугольника
 * @param a Сторона 1
 * @param b Сторона 2
 * @param c Сторона 3
 * @return int Периметр
 */
int get_perimetr(int a, int b, int c);

/**
 * @brief Вычисляет периметр прямоугольника
 * @param a Сторона 1
 * @param b Сторона 2
 * @return int Периметр
 */
int get_perimetr(int a, int b);

/*** Function Implementation ***/
int get_perimetr(int a, int b, int c)
{
    return a + b + c;
}

int get_perimetr(int a, int b)
{
    return 2 * (a + b);
}
