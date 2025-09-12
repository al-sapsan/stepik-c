/**********************************************************************
 * @file script3.cpp
 * @brief Класс Figure: запрет копирования, конструкторы, get_data
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-10
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс для хранения координат фигуры
 */
class Figure
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    Figure() : x0(0), y0(0), x1(0), y1(0) {}
    /**
     * @brief Конструктор с параметрами
     * @param[in] x0 x0
     * @param[in] y0 y0
     * @param[in] x1 x1
     * @param[in] y1 y1
     */
    Figure(int x0, int y0, int x1, int y1) : x0(x0), y0(y0), x1(x1), y1(y1) {}
    /**
     * @brief Получить координаты
     * @param[out] x0 x0
     * @param[out] y0 y0
     * @param[out] x1 x1
     * @param[out] y1 y1
     */
    void get_data(int &x0, int &y0, int &x1, int &y1)
    {
        x0 = this->x0;
        y0 = this->y0;
        x1 = this->x1;
        y1 = this->y1;
    }
    // Запрет копирования и присваивания
    Figure(const Figure &) = delete;
    Figure &operator=(const Figure &) = delete;
    Figure(Figure &&) = delete;
    Figure &operator=(Figure &&) = delete;

private:
    int x0{0}, y0{0}, x1{0}, y1{0};
};

/*** Main Function ***/
int main(void)
{
    Figure fig(-4, 2, 11, 7);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

        return 0;
}
