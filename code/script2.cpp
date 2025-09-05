/**********************************************************************
 * @file script2.cpp
 * @brief Класс Vector3D: приватные координаты, методы, main
 * @version 1.1
 * @date
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс для хранения 3D-вектора
 */
class Vector3D
{
private:
    int m_x_i32;
    int m_y_i32;
    int m_z_i32;

public:
    /*** Function Prototypes ***/
    /**
     * @brief Установить координаты вектора
     * @param[in] a Координата x
     * @param[in] b Координата y
     * @param[in] c Координата z
     * @details Меняет координаты только если все значения в диапазоне [-100; 100]
     */
    void set_coords(int a, int b, int c)
    {
        constexpr int RANGE_MIN = -100;
        constexpr int RANGE_MAX = 100;

        // Лямбда-функция для проверки диапазона
        auto is_in_range = [](int value)
        {
            return value >= RANGE_MIN && value <= RANGE_MAX;
        };

        if (is_in_range(a) && is_in_range(b) && is_in_range(c))
        {
            m_x_i32 = a;
            m_y_i32 = b;
            m_z_i32 = c;
        }
    }

    /**
     * @brief Получить координаты вектора
     * @param[out] x Ссылка для x
     * @param[out] y Ссылка для y
     * @param[out] z Ссылка для z
     */
    void get_coords(int &x, int &y, int &z)
    {
        x = m_x_i32;
        y = m_y_i32;
        z = m_z_i32;
    }
};

/*** Main Function ***/
int main(void)
{
    Vector3D *ptr_v1 = new Vector3D;
    Vector3D *ptr_v2 = new Vector3D;
    ptr_v1->set_coords(10, -5, 7);
    ptr_v2->set_coords(0, 12, -56);

    __ASSERT_TESTS__ // макроопределение для тестирования

        delete ptr_v1;
    ptr_v1 = nullptr;
    delete ptr_v2;
    ptr_v2 = nullptr;
    return 0;
}