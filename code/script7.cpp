/************************************************************************
 * @file script7.cpp
 * @brief Шаблонный класс Triangle и исключение LengthValueError
 * @version 1.0
 * @date 2025-10-16
 ************************************************************************/

#include <iostream>
#include <exception>

/**
 * @brief Исключение для неверных длин сторон треугольника
 */
class LengthValueError : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Length must be a positive number.";
    }
};

/**
 * @brief Шаблонный класс Triangle
 * @tparam T Тип длины стороны (по умолчанию short)
 */
template <typename T = short>
class Triangle
{
private:
    T a{0}, b{0}, c{0};
    static void validate(T a_, T b_, T c_)
    {
        if (a_ < 0 || b_ < 0 || c_ < 0)
            throw LengthValueError();
    }

public:
    Triangle() = default;
    Triangle(T a_, T b_, T c_)
    {
        validate(a_, b_, c_);
        a = a_;
        b = b_;
        c = c_;
    }

    void get_abc(T &a_, T &b_, T &c_) const
    {
        a_ = a;
        b_ = b;
        c_ = c;
    }

    void set_abc(T a_, T b_, T c_)
    {
        validate(a_, b_, c_);
        a = a_;
        b = b_;
        c = c_;
    }
};

int main()
{
    try
    {
        Triangle<int> tr(7, -4, 10);
    }
    catch (const LengthValueError &e)
    {
        std::cout << e.what();
    }

    __ASSERT_TESTS__
    return 0;
}
