/************************************************************************
 * @file script1.cpp
 * @brief Класс ArrayException для обработки ошибок массива
 * @version 1.0 (Embedded C++ bare-metal/RTOS)
 * @date 2025-10-06
 *
 *************************************************************************/

#include <iostream>
#include <string>

/********** Exception Classes **********/

// == < Class ArrayException > == //
/**
 * @brief Класс исключения для ошибок работы с массивом
 */
class ArrayException
{
protected:
    std::string m_msg; ///< Сообщение об ошибке
public:
    /**
     * @brief Конструктор с сообщением
     * @param msg Сообщение об ошибке
     */
    explicit ArrayException(const std::string &msg) noexcept : m_msg(msg) {}

    /**
     * @brief Конструктор копирования
     * @param other Другой объект ArrayException
     */
    ArrayException(const ArrayException &other) noexcept : m_msg(other.m_msg) {}

    /**
     * @brief Виртуальный деструктор
     */
    virtual ~ArrayException() noexcept {}

    /**
     * @brief Cообщение об ошибке
     * @return C-строка с сообщением
     */
    const char *what() const noexcept { return m_msg.c_str(); }
};

/********** Main Function **********/

int main()
{
    try
    {
        throw ArrayException("Main exception");
    }
    catch (const ArrayException &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    __ASSERT_TESTS__ // макроопределение для тестирования
        return 0;
}
