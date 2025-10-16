/************************************************************************
 * @file script9.cpp
 * @brief Complex class and calc_data template for embedded C++ style
 * @version 1.0 (Embedded C++ bare-metal/RTOS)
 * @date 2025-10-06
 *
 * @warning Ensure all input values are validated!
 * @note Tested on ARM Cortex-M, RISC-V, Xtensa (ESP32), RP2040
 *************************************************************************/

#include <iostream>

enum ar_operation
{
    ar_sum = 1, // сложение
    ar_sub = 2, // вычитание
    ar_mul = 3  // умножение
};

/************ Class Definition ***********/

class Complex
{
public:
    Complex() = default;
    Complex(int real) : m_re(real), m_im(0) {}
    Complex(int real, int imag) : m_re(real), m_im(imag) {}

    int real() const { return m_re; }
    int imag() const { return m_im; }
    void set_value(int real, int imag)
    {
        m_re = real;
        m_im = imag;
    }

    Complex operator+(const Complex &other) const
    {
        return Complex(m_re + other.m_re, m_im + other.m_im);
    }
    Complex operator-(const Complex &other) const
    {
        return Complex(m_re - other.m_re, m_im - other.m_im);
    }
    Complex operator*(const Complex &other) const
    {
        int re = m_re * other.m_re - m_im * other.m_im;
        int im = m_re * other.m_im + other.m_re * m_im;
        return Complex(re, im);
    }

private:
    int m_re{0}, m_im{0};
};

/********** Template Function **********/

template <typename T>
T calc_data(T a, T b, ar_operation type = ar_sum)
{
    switch (type)
    {
    case ar_sum:
        return a + b;
    case ar_sub:
        return a - b;
    case ar_mul:
        return a * b;
    default:
        return a + b;
    }
}

/********** Main Function **********/

int main()
{
    Complex cmp_1(-5, 23), cmp_2(14, 7);
    Complex res_1 = calc_data(cmp_1, cmp_2, ar_sub);
    double res_2 = calc_data(0.5, 10.4, ar_sum);
    int res_3 = calc_data(5, -11, ar_mul);

    __ASSERT_TESTS__ // макроопределение для тестирования
        return 0;
}
