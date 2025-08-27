/**********************************************************************
 * @file script3.cpp
 * @brief Структура point: приватные поля, публичные методы, main
 * @version 1.0 (Stepik exercise)
 * @date 2025-08-27
 **********************************************************************/

#include <iostream>
#include <iomanip>

/**
 * @brief Структура точки с перегруженными сеттерами и геттерами
 */
enum data_type
{
    data_none = 1,
    data_int,
    data_double
};

struct point
{
private:
    enum
    {
        max_coords = 3
    };
    union
    {
        int v_int;
        double v_double;
    } coords[max_coords];
    data_type type = data_none;

public:
    /**
     * @brief Установить целочисленные координаты
     */
    void set_coords(int x, int y, int z)
    {
        coords[0].v_int = x;
        coords[1].v_int = y;
        coords[2].v_int = z;
        type = data_int;
    }
    /**
     * @brief Установить вещественные координаты
     */
    void set_coords(double x, double y, double z)
    {
        coords[0].v_double = x;
        coords[1].v_double = y;
        coords[2].v_double = z;
        type = data_double;
    }
    /**
     * @brief Получить тип данных
     */
    data_type get_type() const { return type; }
    /**
     * @brief Получить размер массива координат
     */
    int get_size() const { return max_coords; }
    /**
     * @brief Получить целочисленные координаты
     */
    bool get_coords(int &x, int &y, int &z) const
    {
        if (type != data_int)
            return false;
        x = coords[0].v_int;
        y = coords[1].v_int;
        z = coords[2].v_int;
        return true;
    }
    /**
     * @brief Получить вещественные координаты
     */
    bool get_coords(double &x, double &y, double &z) const
    {
        if (type != data_double)
            return false;
        x = coords[0].v_double;
        y = coords[1].v_double;
        z = coords[2].v_double;
        return true;
    }
};

/*** Main Function ***/
int main(void)
{
    point pt;
    pt.set_coords(5, -8, 34);
    if (pt.get_type() == data_int)
    {
        int x, y, z;
        if (pt.get_coords(x, y, z))
            std::cout << x << " " << y << " " << z << std::endl;
    }
    else if (pt.get_type() == data_double)
    {
        double x, y, z;
        if (pt.get_coords(x, y, z))
            std::cout << std::fixed << std::setprecision(1)
                      << x << " " << y << " " << z << std::endl;
    }
    return 0;
}