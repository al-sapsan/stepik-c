/**********************************************************************
 * @file script2.cpp
 * @brief ConvertToInt, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-22
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <string>
#include <cstdint>

/*** Data Types ***/
typedef int32_t i32_t;
typedef int16_t i16_t;
typedef uint32_t u32_t;

/*** Class Definition ***/

/**
 * @brief Класс конвертации C-строк в целые числа типа i32_t
 *
 * Разрешённые символы:
 * - ведущий знак '+' или '-';
 * - цифры '0'..'9';
 * - один символ '.' (точка) — дробная часть игнорируется.
 * Любой другой символ приводит к ошибке конвертации и результату 0.
 */
class ConvertToInt
{
public:
    /**
     * @brief Преобразует C-строку в i32_t
     * @param str_ptr Указатель на нуль-терминированную строку
     * @return Сконвертированное число или 0 при ошибке
     */
    i32_t operator()(const char* str_ptr);

    /**
     * @brief Признак ошибки последней конвертации
     * @return false — без ошибок; true — была ошибка
     */
    bool is_error() const;

private:
    bool m_error_b {false};
};

/*** Methods Implementation ***/

i32_t ConvertToInt::operator()(const char* str_ptr)
{
    m_error_b = false;
    if (str_ptr == nullptr)
    {
        m_error_b = true;
        return 0;
    }

    // Парсинг знака
    i32_t sign = 1;
    const char* p = str_ptr;
    if (*p == '+')
    {
        ++p;
    }
    else if (*p == '-')
    {
        sign = -1;
        ++p;
    }

    // Должна быть хотя бы одна цифра до возможной точки
    bool has_digit_before_dot = false;
    i32_t value = 0;

    while (*p >= '0' && *p <= '9')
    {
        has_digit_before_dot = true;
        value = value * 10 + static_cast<i32_t>(*p - '0');
        ++p;
    }

    // Обработка дробной части (после первой точки)
    if (*p == '.')
    {
        ++p; // пропускаем точку
        // после точки допускаются только цифры; дробная часть отбрасывается
        while (*p >= '0' && *p <= '9')
        {
            ++p;
        }
    }

    // Если первая часть не содержит цифр — ошибка
    if (!has_digit_before_dot)
    {
        m_error_b = true;
        return 0;
    }

    // Любой оставшийся символ — ошибка
    if (*p != '\0')
    {
        m_error_b = true;
        return 0;
    }

    return sign * value;
}

bool ConvertToInt::is_error() const
{
    return m_error_b;
}

/*** Main ***/
int main()
{
    std::string digit;
    getline(std::cin, digit);

    const char* str = digit.c_str(); // массив символов char с прочитанной строкой

    ConvertToInt str_to_int;
    i32_t result = str_to_int(str);
    std::cout << result << std::endl;

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}
