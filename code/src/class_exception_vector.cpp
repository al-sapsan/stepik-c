/************************************************************************
 * @file script2.cpp
 * @brief Классы VectorError, VectorErrorNegativeCoord, Vector для работы с векторами
 * @version 1.0 (Embedded C++ bare-metal/RTOS)
 * @date 2025-10-06
 *
 * @warning Не использовать без проверки координат!
 * @note Классы протестированы для платформ: ARM Cortex-M, RISC-V, Xtensa (ESP32), RP2040
 *************************************************************************/

#include <iostream>
#include <string>

/********** Exception Classes **********/

// == < Class VectorError > == //
/**
 * @brief Базовый класс исключения для ошибок работы с вектором
 */
class VectorError : public std::exception
{
protected:
    std::string m_msg;

public:
    VectorError(const std::string &error) noexcept : m_msg(error) {}
    virtual ~VectorError() {}
    const char *what() const noexcept override { return m_msg.c_str(); }
};

// == < Class VectorErrorNegativeCoord > == //
/**
 * @brief Исключение: отрицательное значение координаты вектора
 */
class VectorErrorNegativeCoord : public VectorError
{
public:
    VectorErrorNegativeCoord() noexcept : VectorError("Negative coordinate value.") {}
    VectorErrorNegativeCoord(const std::string &error) noexcept : VectorError(error) {}
};

/************ Class Definition ***********/

// == < Class Vector > == //
/**
 * @brief Класс для работы с векторами
 */
class Vector
{
    int m_x{0}; ///< Координата x
    int m_y{0}; ///< Координата y
public:
    /**
     * @brief Конструктор по умолчанию
     */
    Vector() noexcept = default;

    /**
     * @brief Конструктор с координатами
     * @param x Координата x
     * @param y Координата y
     * @throws VectorErrorNegativeCoord если хотя бы одна координата отрицательна
     */
    Vector(int x, int y)
    {
        if (x < 0 || y < 0)
            throw VectorErrorNegativeCoord("Constructor: Negative coordinate value.");
        m_x = x;
        m_y = y;
    }

    /**
     * @brief Получить координату x
     */
    int get_x() const { return m_x; }

    /**
     * @brief Получить координату y
     */
    int get_y() const { return m_y; }

    /**
     * @brief Установить координаты x и y
     * @param x Координата x
     * @param y Координата y
     * @throws VectorErrorNegativeCoord если хотя бы одна координата отрицательна
     */
    void set_xy(int x, int y)
    {
        if (x < 0 || y < 0)
            throw VectorErrorNegativeCoord();
        m_x = x;
        m_y = y;
    }
};

/********** Main Function **********/

int main()
{
    int x, y;
    std::cin >> x >> y;
    try
    {
        Vector v(x, y);
        std::cout << v.get_x() << " " << v.get_y() << std::endl;
    }
    catch (const VectorError &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    __ASSERT_TESTS__ // макроопределение для тестирования
        return 0;
}
