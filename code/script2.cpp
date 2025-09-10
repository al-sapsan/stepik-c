/**********************************************************************
 * @file script2.cpp
 * @brief Класс StringBuffer: копирующий конструктор и деструктор
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-08
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс для хранения строки в динамическом буфере
 */
class StringBuffer
{
public:
    /**
     * @brief Конструктор из C-строки
     * @param[in] str исходная строка
     */
    StringBuffer(const char *str)
    {
        size = 0;
        while (str[size] != '\0' && size < max_size - 1)
            size++;
        buffer = new char[size + 1];
        for (int i = 0; i < size; ++i)
            buffer[i] = str[i];
        buffer[size] = '\0';
    }
    /**
     * @brief Копирующий конструктор
     * @param[in] other другой объект StringBuffer
     */
    StringBuffer(const StringBuffer &other)
    {
        size = other.size;
        buffer = new char[size + 1];
        for (int i = 0; i < size; ++i)
            buffer[i] = other.buffer[i];
        buffer[size] = '\0';
    }
    /**
     * @brief Деструктор: освобождает память
     */
    ~StringBuffer()
    {
        delete[] buffer;
    }
    /**
     * @brief Получить строку
     * @return указатель на строку
     */
    const char *get_data() { return buffer; }
    /**
     * @brief Получить размер строки
     * @return размер
     */
    int get_size() { return size; }

private:
    enum
    {
        max_size = 1024
    };
    char *buffer{nullptr};
    int size{0};
};