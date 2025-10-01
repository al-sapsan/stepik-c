/**********************************************************************
 * @file script4.cpp
 * @brief Validator, PositiveValidator, RangeValidator implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-09-29
 **********************************************************************/

#include <iostream>

/********** Class Definition **********/
// == < Validator > == //
/**
 * @brief Базовый валидатор
 */
class Validator
{
public:
    virtual bool is_valid(int x) { return true; }
    virtual ~Validator() {}
};

// == < PositiveValidator > == //
/**
 * @brief Валидатор положительных чисел
 */
class PositiveValidator : public Validator
{
public:
    virtual bool is_valid(int x) override { return x >= 0; }
};

// == < RangeValidator > == //
/**
 * @brief Валидатор диапазона
 * @param left Левая граница
 * @param right Правая граница
 */
class RangeValidator : public Validator
{
private:
    int m_left{0};
    int m_right{0};

public:
    RangeValidator(int left, int right) : m_left(left), m_right(right) {}

    virtual bool is_valid(int x) override { return x >= m_left && x <= m_right; }
};

/********** Main Function **********/
int main(void)
{
    Validator *vs[3]{nullptr};

    vs[0] = new PositiveValidator();
    vs[1] = new RangeValidator(-5, 5);
    vs[2] = new RangeValidator(-15, 10);

    int x;
    std::cin >> x;

    for (int i = 0; i < 3; ++i)
    {
        std::cout << (vs[i]->is_valid(x) ? 1 : 0);
        if (i < 2)
            std::cout << " ";
    }
    std::cout << std::endl;

    __ASSERT_TESTS__

    for (int i = 0; i < 3; ++i)
    {
        delete vs[i];
    }

    return 0;
}