/**********************************************************************
 * @file script3.cpp
 * @brief Структура vector4D с методами read_data и length (embedded C++ style)
 * @version 1.0 (Stepik exercise)
 * @date 2025-08-26
 **********************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>

/**
 * @brief Структура 4D-вектора с методами чтения и вычисления длины
 */
struct vector4D
{
    double x, y, z, t;
    /**
     * @brief Чтение данных из потока
     * @param stream Указатель на поток
     * @param sep Разделитель
     */
    void read_data(FILE *stream, char sep = ' ')
    {
        char buf[128];
        if (fgets(buf, sizeof(buf), stream))
        {
            double vals[4] = {0};
            int idx = 0;
            char *p = buf;
            while (idx < 4)
            {
                vals[idx] = strtod(p, &p);
                if (*p == sep)
                    ++p;
                ++idx;
            }
            x = vals[0];
            y = vals[1];
            z = vals[2];
            t = vals[3];
        }
    }
    /**
     * @brief Вычисляет длину радиус-вектора
     * @return Длина (double)
     */
    double length(void) const
    {
        return std::sqrt(x * x + y * y + z * z + t * t);
    }
};

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 * @return Код завершения (0 — успешно, 1 — ошибка памяти)
 */
int main(void)
{
    vector4D v1, v2;
    v1.read_data(stdin, ';');
    v2.read_data(stdin, ';');
    std::cout << std::fixed << std::setprecision(3)
              << v1.length() << " " << v2.length() << std::endl;
    __ASSERT_TESTS__
    return 0;
}
