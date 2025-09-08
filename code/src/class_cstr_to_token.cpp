/**********************************************************************
 * @file script6.cpp
 * @brief Класс Vector3D: конструкторы из строки и массива, методы-геттеры
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-08
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

/*** Class Definition ***/
/**
 * @brief Класс для хранения 3D-вектора с разными конструкторами
 */
class Vector3D
{
public:
    /*** Constructors ***/
    /**
     * @brief Конструктор по умолчанию
     */
    Vector3D() : m_x_i32(0), m_y_i32(0), m_z_i32(0) {}
    /**
     * @brief Конструктор из C-строки
     * @param[in] str C-строка с координатами
     * @details Извлекает первые три числа, преобразует к int, нечисловое = 0
     */
    Vector3D(const char *str) : m_x_i32(0), m_y_i32(0), m_z_i32(0)
    {
        char buf[128] = {0};
        if (str)
        {
            std::strncpy(buf, str, sizeof(buf) - 1);
            char *token = std::strtok(buf, " ,;:");
            if (token)
            {
                m_x_i32 = std::atoi(token);
                token = std::strtok(nullptr, " ,;:");
            }
            if (token)
            {
                m_y_i32 = std::atoi(token);
                token = std::strtok(nullptr, " ,;:");
            }
            if (token)
            {
                m_z_i32 = std::atoi(token);
            }
        }
    }
    /**
     * @brief Конструктор из массива int
     * @param[in] arr массив int
     */
    Vector3D(const int arr[]) : m_x_i32(0), m_y_i32(0), m_z_i32(0)
    {
        if (arr)
        {
            m_x_i32 = arr[0];
            m_y_i32 = arr[1];
            m_z_i32 = arr[2];
        }
    }
    /*** Methods Implementation ***/
    /**
     * @brief Получить координаты
     * @param[out] a x
     * @param[out] b y
     * @param[out] c z
     */
    void get_coords(int &a, int &b, int &c)
    {
        a = m_x_i32;
        b = m_y_i32;
        c = m_z_i32;
    }

private:
    int m_x_i32, m_y_i32, m_z_i32;
};
/*** Пример использования ***/
int main()
{
    // Разные способы создания объектов
    Vector3D v1;                // (0, 0, 0)
    Vector3D v2("10 20 30");    // (10, 20, 30)
    Vector3D v3("5, -7; 12");   // (5, -7, 12)
    Vector3D v4("1.5 2.8 3.2"); // (1, 2, 3)

    int arr[] = {15, 25, 35};
    Vector3D v5(arr); // (15, 25, 35)

    Vector3D v6(100, 200, 300); // (100, 200, 300)

    return 0;
}