/**********************************************************************
 * @file script5.cpp
 * @brief Класс Vector3D: конструкторы, set/get, проверка диапазона
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-10
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс для хранения 3D-вектора
 */
class Vector3D
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    Vector3D() : x(0), y(0), z(0) {}
    /**
     * @brief Конструктор с одним параметром
     * @param[in] a координата x
     */
    Vector3D(int a) : x(a), y(0), z(0) {}
    /**
     * @brief Конструктор с тремя параметрами
     * @param[in] a координата x
     * @param[in] b координата y
     * @param[in] c координата z
     */
    Vector3D(int a, int b, int c) : x(a), y(b), z(c) {}
    /**
     * @brief Установить координаты (с проверкой диапазона)
     * @param[in] a x
     * @param[in] b y
     * @param[in] c z
     */
    void set_coords(int a, int b, int c)
    {
        if (a >= -100 && a <= 100 && b >= -100 && b <= 100 && c >= -100 && c <= 100)
        {
            x = a;
            y = b;
            z = c;
        }
    }
    /**
     * @brief Получить координаты
     * @param[out] a x
     * @param[out] b y
     * @param[out] c z
     */
    void get_coords(int &a, int &b, int &c)
    {
        a = x;
        b = y;
        c = z;
    }

private:
    int x, y, z;
};

/*** Main Function ***/
int main(void)
{
    // создаём объекты через new
    Vector3D *ptr_v1 = new Vector3D(10, -5, 7);
    Vector3D *ptr_v2 = new Vector3D(0, 12, -56);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

        delete ptr_v1;
    ptr_v1 = nullptr;
    delete ptr_v2;
    ptr_v2 = nullptr;
    return 0;
}
