/************************************************************************
 * @file script4.cpp
 * @brief Класс Box3D с обработкой ошибок диапазона и операций
 * @version 1.0 (Embedded C++ bare-metal/RTOS)
 * @date 2025-10-06
 *
 * @warning Не использовать без проверки диапазона!
 * @note Класс протестирован для платформ: ARM Cortex-M, RISC-V, Xtensa (ESP32), RP2040
 *************************************************************************/

#include <iostream>
#include <exception>

/********** Exception Classes **********/

// == < Class BoxError > == //
/**
 * @brief Базовый класс исключения для ошибок работы с Box3D
 */
class BoxError : public std::exception
{
protected:
    std::string m_msg;

public:
    explicit BoxError(const std::string &msg) : m_msg(msg) {}
    virtual ~BoxError() {}
    const char *what() const noexcept override { return m_msg.c_str(); }
};

// == < Class BoxLimitError > == //
/**
 * @brief Исключение: габариты вне диапазона
 */
class BoxLimitError : public BoxError
{
public:
    explicit BoxLimitError(const std::string &msg) : BoxError(msg) {}
};

// == < Class BoxCalcError > == //
/**
 * @brief Исключение: ошибка вычисления габаритов
 */
class BoxCalcError : public BoxError
{
public:
    explicit BoxCalcError(const std::string &msg) : BoxError(msg) {}
};

/************ Class Definition ***********/

// == < Class Box3D > == //
/**
 * @brief Класс для работы с трехмерными габаритами
 */
class Box3D
{
public:
    enum
    {
        limit_dim = 100
    };

private:
    short m_a{0}, m_b{0}, m_c{0};

    static bool is_valid(short a, short b, short c)
    {
        return (a >= 0 && a <= limit_dim) && (b >= 0 && b <= limit_dim) && (c >= 0 && c <= limit_dim);
    }

public:
    Box3D() = default;
    Box3D(short a, short b, short c)
    {
        if (!is_valid(a, b, c))
            throw BoxLimitError("Exceeding the size range.");
        m_a = a;
        m_b = b;
        m_c = c;
    }

    void get_dims(short &a, short &b, short &c)
    {
        a = m_a;
        b = m_b;
        c = m_c;
    }

    void set_dims(short a, short b, short c)
    {
        if (!is_valid(a, b, c))
            throw BoxLimitError("Exceeding the size range.");
        m_a = a;
        m_b = b;
        m_c = c;
    }

    Box3D operator+(const Box3D &other) const
    {
        short na = m_a + other.m_a;
        short nb = m_b + other.m_b;
        short nc = m_c + other.m_c;
        if (!is_valid(na, nb, nc))
            throw BoxCalcError("Calculation: Exceeding the size range.");
        return Box3D(na, nb, nc);
    }

    Box3D operator-(const Box3D &other) const
    {
        short na = m_a - other.m_a;
        short nb = m_b - other.m_b;
        short nc = m_c - other.m_c;
        if (!is_valid(na, nb, nc))
            throw BoxCalcError("Calculation: Exceeding the size range.");
        return Box3D(na, nb, nc);
    }
};

/********** Main Function **********/

int main()
{
    try
    {
        Box3D box(5, -1, 10);
    }
    catch (const BoxLimitError &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (const BoxCalcError &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (const BoxError &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    __ASSERT_TESTS__ // макроопределение для тестирования
        return 0;
}
