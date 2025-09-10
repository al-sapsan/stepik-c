/**********************************************************************
 * @file script4.cpp
 * @brief Класс Complex: конструкторы, копирование с модулем, геттеры
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-10
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <cstdlib>

/*** Class Definition ***/
/**
 * @brief Класс для хранения комплексного числа
 */
class Complex
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    Complex() : re(0), im(0) {}
    /**
     * @brief Конструктор с одним параметром
     * @param[in] r действительная часть
     */
    Complex(short r) : re(r), im(0) {}
    /**
     * @brief Конструктор с двумя параметрами
     * @param[in] r действительная часть
     * @param[in] i мнимая часть
     */
    Complex(short r, short i) : re(r), im(i) {}
    /**
     * @brief Конструктор копирования (копирует модули)
     * @param[in] other другой объект Complex
     */
    Complex(const Complex &other) : re(std::abs(other.re)), im(std::abs(other.im)) {}
    /**
     * @brief Получить действительную часть
     * @return short
     */
    short real() { return re; }
    /**
     * @brief Получить мнимую часть
     * @return short
     */
    short imag() { return im; }

private:
    short re{0}; ///< действительная часть
    short im{0}; ///< мнимая часть
};

/*** Main Function ***/
int main(void)
{
    // создаём объект с re=-4, im=7
    Complex digit(-4, 7);
    // копируем с модулем
    Complex res = digit;

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

        return 0;
}
