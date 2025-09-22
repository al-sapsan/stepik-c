/**********************************************************************
 * @file script4.cpp
 * @brief Класс RandomPassword, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-22
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

/*** Class Definition ***/
/**
 * @brief Класс RandomPassword: генератор случайных паролей
 */
class RandomPassword
{
public:
    /**
     * @brief Конструктор
     * @param[in] chars разрешенные символы
     * @param[in] min_len минимальная длина
     * @param[in] max_len максимальная длина
     */
    RandomPassword(const std::string &chars, int min_len, int max_len);
    /**
     * @brief Генерация пароля
     * @return std::string
     */
    std::string operator()() const;

private:
    std::string psw_chars;
    int min_length{0}, max_length{0};
};

/*** Methods Implementation ***/
RandomPassword::RandomPassword(const std::string &chars, int min_len, int max_len)
    : psw_chars(chars), min_length(min_len), max_length(max_len)
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}
std::string RandomPassword::operator()() const
{
    int len = min_length + std::rand() % (max_length - min_length + 1);
    std::string result;
    for (int i = 0; i < len; ++i)
    {
        int idx = std::rand() % psw_chars.size();
        result += psw_chars[idx];
    }
    return result;
}
