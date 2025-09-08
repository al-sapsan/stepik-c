/**********************************************************************
 * @file script5.cpp
 * @brief Класс Point: конструктор из строки, методы-геттеры
 * @version 1.1 (Fixed compilation)
 * @date 2025-09-06
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <cstdlib> // для atoi
#include <cstring> // для strchr

/*** Class Definition ***/
/**
 * @brief Класс для хранения точки с конструктором из строки
 */
class Point
{
public:
    /*** Constructor ***/
    /**
     * @brief Конструктор (secured)
     */
    Point(const char *str) : m_x_i32(0), m_y_i32(0)
    {
        if (str == nullptr)
            return;

        // Безопасное преобразование первого числа
        x = std::atoi(str);

        // Безопасный поиск пробела
        const char *space_pos = std::strchr(str, ' ');
        if (space_pos != nullptr && *(space_pos + 1) != '\0')
        {
            y = std::atoi(space_pos + 1);
        }
    }
    /*** Methods Implementation ***/
    /**
     * @brief Получить x
     * @return x
     */
    int get_x() { return m_x_i32; }

    /**
     * @brief Получить y
     * @return y
     */
    int get_y() { return m_y_i32; }

private:
    int m_x_i32, m_y_i32;
};

/*** Main Function ***/
int main()
{
    Point pt = "5 10 12 0";             // x=5, y=10
    Point pt2 = "-5.5  -0.78 abc";      // x=-5, y=0
    Point pt3 = "14.2 -5.8 point data"; // x=14, y=-5

    return 0;
}