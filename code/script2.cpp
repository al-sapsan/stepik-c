/************************************************************************
 * @file script2.cpp
 * @brief Класс ConvertToInt для конвертации строк в целые числа
 * @version 1.0 (Embedded C++ bare-metal/RTOS)
 * @date 2025-10-04
 *
 * @warning Не использовать без проверки входных данных!))
 *************************************************************************/

#include <iostream>
#include <string>
#include <cctype>

/********** Exception Classes **********/

// == < Class ExceptionConvert > == //
/**
 * @brief Класс исключения для ошибок конвертации строки в число
 *
 * @details
 * Содержит сообщение об ошибке, возвращаемое методом to_msg().
 */
class ExceptionConvert
{
    std::string m_msg; ///< Сообщение об ошибке

public:
    /**
     * @brief Конструктор исключения
     * @param msg Строка с сообщением об ошибке
     */
    explicit ExceptionConvert(const std::string &msg) : m_msg(msg) {}

    /**
     * @brief Получить сообщение об ошибке
     * @return Строка с сообщением
     */
    const std::string &to_msg() const { return m_msg; }
};

/************ Class Definition ***********/

// == < Class ConvertToInt > == //
/**
 * @brief Класс для конвертации строки в целое число
 *
 * @details
 * Осуществляет преобразование строки в int, выбрасывает исключение при ошибке.
 * Допустимы только символы '+', '-', '.', цифры. Дробная часть игнорируется.
 */
class ConvertToInt
{
    class ConvertToInt
    {
        std::string m_msg; ///< Сообщение об ошибке (не используется)

    public:
        /**
         * @brief Конструктор по умолчанию
         */
        ConvertToInt() = default;

        /**
         * @brief Оператор преобразования строки в int
         * @param str Строка для конвертации
         * @return Целое число
         * @throws ExceptionConvert В случае ошибки конвертации
         */
        int operator()(const char *str)
        {
            if (!str || !*str)
                throw ExceptionConvert("Conversion error");
            int sign = 1;
            size_t i = 0;
            if (str[i] == '+')
            {
                sign = 1;
                ++i;
            }
            else if (str[i] == '-')
            {
                sign = -1;
                ++i;
            }
            int result = 0;
            bool digit_found = false;
            bool dot_found = false;
            for (; str[i] != '\0'; ++i)
            {
                if (!dot_found)
                {
                    if (str[i] == '.')
                    {
                        dot_found = true;
                        continue;
                    }
                    if (!std::isdigit(static_cast<unsigned char>(str[i])))
                    {
                        throw ExceptionConvert("Conversion error");
                    }
                    digit_found = true;
                    result = result * 10 + (str[i] - '0');
                }
                else
                {
                    // После точки допускаются только цифры, но они игнорируются для целой части
                    if (!std::isdigit(static_cast<unsigned char>(str[i])))
                    {
                        throw ExceptionConvert("Conversion error");
                    }
                    // Не добавляем к результату, только проверяем корректность
                }
            }
            if (!digit_found)
                throw ExceptionConvert("Conversion error");
            return sign * result;
        }

        /**
         * @brief Получить сообщение об ошибке (не используется)
         * @return Строка с сообщением
         */
        const std::string &to_msg() const { return m_msg; }
    };
    return sign * result;
} const std::string &to_msg() const { return m_msg; }
}
;

/********** Main Function **********/

int main()
{
    std::string digit;
    getline(std::cin, digit);

    const char *str = digit.c_str();

    ConvertToInt str_to_int;
    try
    {
        int res = str_to_int(str);
        std::cout << res << std::endl;
    }
    catch (const ExceptionConvert &ex)
    {
        std::cout << ex.to_msg() << std::endl;
    }

    __ASSERT_TESTS__ // макроопределение для тестирования
        return 0;
}
