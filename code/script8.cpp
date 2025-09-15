/**********************************************************************
 * @file script8.cpp
 * @brief Класс StringChars: строка, оператор сложения, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-15
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <cstring>

/*** Class Definition ***/
/**
 * @brief Класс StringChars: строка, оператор сложения
 */
class StringChars
{
public:
    /**
     * @brief Конструктор из C-строки
     * @param[in] str строка
     */
    StringChars(const char *str);
    /**
     * @brief Копирующий конструктор
     * @param[in] other другой объект
     */
    StringChars(const StringChars &other);
    /**
     * @brief Деструктор
     */
    ~StringChars();
    /**
     * @brief Оператор сложения
     * @param[in] other другой объект
     * @return StringChars
     */
    StringChars operator+(const StringChars &other) const;
    /**
     * @brief Получить строку
     * @return char*
     */
    char *to_str() const;
    /**
     * @brief Получить длину
     * @return size_t
     */
    size_t get_length() const;

private:
    char *m_buffer{nullptr}; ///< строка
    size_t m_length{0};      ///< длина
};

/*** Methods Implementation ***/
StringChars::StringChars(const char *str)
{
    m_length = std::strlen(str);
    m_buffer = new char[m_length + 1];
    std::strcpy(m_buffer, str);
}

StringChars::StringChars(const StringChars &other)
{
    m_length = other.m_length;
    m_buffer = new char[m_length + 1];
    std::strcpy(m_buffer, other.m_buffer);
}

StringChars::~StringChars()
{
    delete[] m_buffer;
}

StringChars StringChars::operator+(const StringChars &other) const
{
    size_t new_len = m_length + other.m_length;
    char *buf = new char[new_len + 1];
    std::strcpy(buf, m_buffer);
    std::strcat(buf, other.m_buffer);
    StringChars res(buf);
    delete[] buf;
    return res;
}

char *StringChars::to_str() const { return m_buffer; }
size_t StringChars::get_length() const { return m_length; }

/*** Main Function ***/
int main(void)
{
    StringChars *ptr_str1 = new StringChars("Language");
    StringChars *ptr_str2 = new StringChars(" C++");
    StringChars res = *ptr_str1 + *ptr_str2;

    __ASSERT_TESTS__ // макроопределение для тестирования

        delete ptr_str1;
    ptr_str1 = nullptr;
    delete ptr_str2;
    ptr_str2 = nullptr;
    return 0;
}
