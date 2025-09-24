/**********************************************************************
 * @file script2.cpp
 * @brief Классы ValidatorInteger, ValidatorRange, ValidatorPositive (embedded C++ style)
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-24
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс ValidatorInteger
 */
class ValidatorInteger
{
private:
    int err_no = 0;

public:
    ValidatorInteger() = default;
    int get_errno() const { return err_no; }
    virtual bool is_valid(int x) const { return true; }
};

/**
 * @brief Класс ValidatorRange (наследник ValidatorInteger)
 */
class ValidatorRange : public ValidatorInteger
{
private:
    int min_value = 0, max_value = 0;

public:
    ValidatorRange(int min_v, int max_v) : min_value(min_v), max_value(max_v) {}
    bool is_valid(int x) const override { return x >= min_value && x <= max_value; }
};

/**
 * @brief Класс ValidatorPositive (наследник ValidatorInteger)
 */
class ValidatorPositive : public ValidatorInteger
{
public:
    ValidatorPositive() = default;
    bool is_valid(int x) const override { return x >= 0; }
};

/*** Main ***/
int main()
{
    ValidatorRange vr(-5, 7);
    ValidatorPositive v_positive;
    int value;
    std::cin >> value;
    std::cout << vr.is_valid(value) << " " << v_positive.is_valid(value) << std::endl;

    __ASSERT_TESTS__ // макроопределение для тестирования
        return 0;
}
