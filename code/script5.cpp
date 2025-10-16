/************************************************************************
 * @file script5.cpp
 * @brief Шаблонный валидатор и проверка попадания в диапазон
 * @version 1.0
 * @date 2025-10-16
 ************************************************************************/

#include <iostream>
#include <string>

/**
 * @brief Базовый шаблонный класс валидатора
 * @tparam T Тип проверяемого значения
 */
template <typename T>
class Validator
{
protected:
    std::string msg_ex; ///< сообщение исключения
public:
    Validator() = default;
    explicit Validator(const std::string &msg) : msg_ex(msg) {}
    virtual bool is_valid(T x, bool exception = true) const = 0;
    virtual ~Validator() {}
};

/**
 * @brief Валидатор диапазона [min_value; max_value]
 * @tparam T Тип проверяемого значения
 */
template <typename T>
class ValidatorRange : public Validator<T>
{
private:
    T min_value{0};
    T max_value{0};

public:
    ValidatorRange() = default;
    ValidatorRange(const std::string &msg, T minv, T maxv)
        : Validator<T>(msg), min_value(minv), max_value(maxv) {}

    bool is_valid(T x, bool exception = true) const override
    {
        if (x >= min_value && x <= max_value)
            return true;
        if (!exception)
            return false;
        throw this->msg_ex;
    }
};

int main(void)
{
    ValidatorRange<double> vr("Value is outside the range [-4.5; 2.5]", -4.5, 2.5);

    try
    {
        double x;
        if (!(std::cin >> x))
        {
            // no input - nothing to do
        }
        else
        {
            vr.is_valid(x); // may throw
        }
    }
    catch (const std::string &ex)
    {
        std::cout << ex;
    }

#ifndef __ASSERT_TESTS__
#define __ASSERT_TESTS__
#endif

    __ASSERT_TESTS__
    return 0;
}
