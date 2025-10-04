/**********************************************************************
 * @file script5.cpp
 * @brief Validator, ValidatorRange class implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-10-03
 **********************************************************************/

#include <iostream>
#include <string>

/********** Class Definition **********/
class Validator
{
protected:
    std::string m_msg_ex;

public:
    virtual bool is_valid(int x, bool exception = true) const = 0;
    virtual ~Validator() = default;
};

/**
 * @brief Класс для проверки диапазона целых чисел
 * @param min_value Минимальное значение
 * @param max_value Максимальное значение
 * @param msg_ex Сообщение исключения
 */
class ValidatorRange : public Validator
{
private:
    int m_min_value{0}, m_max_value{0};

public:
    ValidatorRange(const std::string &msg_ex, int min_value, int max_value)
    {
        m_msg_ex = msg_ex;
        m_min_value = min_value;
        m_max_value = max_value;
    }

    virtual bool is_valid(int x, bool exception = true) const override
    {
        if (x < m_min_value || x > m_max_value)
        {
            if (exception)
                throw m_msg_ex;
            return false;
        }
        return true;
    }
};

/********** Main Function **********/
int main(void)
{
    ValidatorRange vr("Value is outside the range [0; 15]", 0, 15);

    int x;
    std::cin >> x;

    try
    {
        vr.is_valid(x, true);
    }
    catch (const std::string &ex)
    {
        std::cout << ex << std::endl;
    }

    __ASSERT_TESTS__

    return 0;
}