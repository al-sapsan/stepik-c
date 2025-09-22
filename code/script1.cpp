/**********************************************************************
 * @file script1.cpp
 * @brief Класс StringBuffer, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-20
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <cstring>

/*** Class Definition ***/
/**
 * @brief Класс StringBuffer: строковый буфер
 */
class StringBuffer
{
public:
    /**
     * @brief Конструктор из строки
     * @param[in] str исходная строка
     */
    StringBuffer(const char *str);
    /**
     * @brief Конструктор копирования
     * @param[in] other другой объект StringBuffer
     */
    StringBuffer(const StringBuffer &other);
    /**
     * @brief Деструктор
     */
    ~StringBuffer();
    /**
     * @brief Оператор сложения (строка + StringBuffer)
     * @param[in] lhs строка
     * @param[in] rhs StringBuffer
     * @return StringBuffer
     */
    friend StringBuffer operator+(const char *lhs, const StringBuffer &rhs);
    /**
     * @brief Оператор сложения (StringBuffer + строка)
     * @param[in] rhs строка
     * @return StringBuffer
     */
    StringBuffer operator+(const char *rhs) const;
    /**
     * @brief Оператор += (строка)
     * @param[in] rhs строка
     * @return StringBuffer&
     */
    StringBuffer &operator+=(const char *rhs);
    /**
     * @brief Получить данные
     * @return const char*
     */
    const char *get_data() const;
    /**
     * @brief Получить размер
     * @return int
     */
    int get_size() const;

private:
    enum
    {
        max_size = 1024
    };
    char *buffer{nullptr};
    int size{0};
    // Конструктор с capacity для внутренних операций
    StringBuffer(int capacity) : buffer(new char[capacity + 1]), size(0) { buffer[0] = '\0'; }
};

/*** Methods Implementation ***/
StringBuffer::StringBuffer(const char *str) : buffer(nullptr), size(0)
{
    while (str[size] != '\0' && size < max_size - 1)
        size++;
    buffer = new char[size + 1];
    for (int i = 0; i < size; ++i)
        buffer[i] = str[i];
    buffer[size] = '\0';
}
StringBuffer::StringBuffer(const StringBuffer &other) : buffer(nullptr), size(other.size)
{
    buffer = new char[size + 1];
    for (int i = 0; i < size; ++i)
        buffer[i] = other.buffer[i];
    buffer[size] = '\0';
}
StringBuffer::~StringBuffer() { delete[] buffer; }
StringBuffer StringBuffer::operator+(const char *rhs) const
{
    int rhs_len = 0;
    while (rhs[rhs_len] != '\0' && rhs_len < max_size - 1)
        rhs_len++;
    int new_size = size + rhs_len;
    if (new_size > max_size - 1)
        new_size = max_size - 1;
    StringBuffer result(new_size);
    int i = 0;
    for (; i < size && i < new_size; ++i)
        result.buffer[i] = buffer[i];
    for (int j = 0; i < new_size && j < rhs_len; ++i, ++j)
        result.buffer[i] = rhs[j];
    result.size = new_size;
    result.buffer[new_size] = '\0';
    return result;
}
StringBuffer &StringBuffer::operator+=(const char *rhs)
{
    int rhs_len = 0;
    while (rhs[rhs_len] != '\0' && rhs_len < max_size - 1)
        rhs_len++;
    int new_size = size + rhs_len;
    if (new_size > max_size - 1)
        new_size = max_size - 1;
    char *new_buf = new char[new_size + 1];
    int i = 0;
    for (; i < size && i < new_size; ++i)
        new_buf[i] = buffer[i];
    for (int j = 0; i < new_size && j < rhs_len; ++i, ++j)
        new_buf[i] = rhs[j];
    new_buf[new_size] = '\0';
    delete[] buffer;
    buffer = new_buf;
    size = new_size;
    return *this;
}
const char *StringBuffer::get_data() const { return buffer; }
int StringBuffer::get_size() const { return size; }
StringBuffer operator+(const char *lhs, const StringBuffer &rhs)
{
    int lhs_len = 0;
    while (lhs[lhs_len] != '\0' && lhs_len < StringBuffer::max_size - 1)
        lhs_len++;
    int new_size = lhs_len + rhs.size;
    if (new_size > StringBuffer::max_size - 1)
        new_size = StringBuffer::max_size - 1;
    StringBuffer result(new_size);
    int i = 0;
    for (; i < lhs_len && i < new_size; ++i)
        result.buffer[i] = lhs[i];
    for (int j = 0; i < new_size && j < rhs.size; ++i, ++j)
        result.buffer[i] = rhs.buffer[j];
    result.size = new_size;
    result.buffer[new_size] = '\0';
    return result;
}
