/**********************************************************************
 * @file script1.cpp
 * @brief FunctionInterface, LinearFunction, ReluFunction implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-09-26
 **********************************************************************/

#include <iostream>
#include <iomanip>

/********** Class Definition **********/

// == < FunctionInterface > == //
/**
 * @brief Интерфейс функции
 */
class FunctionInterface
{
public:
    virtual double func(double arg) { return 0; }
    virtual double operator()(double arg) { return 0; }
    virtual ~FunctionInterface() {}
};

// == < LinearFunction > == //
/**
 * @brief Линейная функция
 * @param k Угловой коэффициент
 * @param b Смещение
 */
class LinearFunction : public FunctionInterface
{
private:
    double m_k{0.0};
    double m_b{0.0};

public:
    LinearFunction(double k, double b) : m_k(k), m_b(b) {}

    virtual double func(double arg) override
    {
        return m_k * arg + m_b;
    }
    virtual double operator()(double arg) override
    {
        return m_k * arg + m_b;
    }
};

// == < ReluFunction > == //
/**
 * @brief Функция ReLU
 */
class ReluFunction : public FunctionInterface
{
public:
    ReluFunction() {}

    virtual double func(double arg) override
    {
        return arg > 0 ? arg : 0;
    }
    virtual double operator()(double arg) override
    {
        return arg > 0 ? arg : 0;
    }
};

/********** Main Function **********/

int main(void)
{
    std::vector<std::unique_ptr<FunctionInterface>> funcs;
    funcs.push_back(std::make_unique<LinearFunction>(0.5, 0.0));
    funcs.push_back(std::make_unique<LinearFunction>(1.2, -5.4));
    funcs.push_back(std::make_unique<ReluFunction>());

    double x;
    std::cin >> x;

    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < 3; ++i)
    {
        std::cout << funcs[i]->func(x);
        if (i < 2)
            std::cout << " ";
    }
    std::cout << std::endl;

    __ASSERT_TESTS__

    return 0;
}