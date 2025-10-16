/************************************************************************
 * @file script5.cpp
 * @brief Main file for embedded C++ task implementation
 * @version 1.0 (Embedded C++ bare-metal/RTOS)
 * @date 2025-10-06
 *
 * @warning Ensure all input values are validated!
 * @note Tested on ARM Cortex-M, RISC-V, Xtensa (ESP32), RP2040
 *************************************************************************/
#include <iostream>
#include <exception>

/********** Exception Classes **********/

/// @brief Базовый класс исключения для ошибок ColorRGB
class ColorRGBError : public std::exception
{
protected:
    std::string m_msg;

public:
    ColorRGBError(const std::string &error) noexcept : m_msg(error) {}
    virtual ~ColorRGBError() {}
    const char *what() const noexcept override { return m_msg.c_str(); }
};

/// @brief Исключение: некорректное значение цветовой компоненты
class ColorRGBValueError : public ColorRGBError
{
public:
    ColorRGBValueError() noexcept : ColorRGBError("Valid values must be in the range [0; 255]") {}
    ColorRGBValueError(const std::string &error) noexcept : ColorRGBError(error) {}
};

/// @brief Исключение: некорректный индекс компоненты
class ColorRGBIndexError : public ColorRGBError
{
public:
    ColorRGBIndexError() noexcept : ColorRGBError("Index must be in range [0; 2]") {}
    ColorRGBIndexError(const std::string &error) noexcept : ColorRGBError(error) {}
};

/************ Class Definition ***********/

/// @brief Класс для работы с цветом RGB
class ColorRGB
{
private:
    short r{0}, g{0}, b{0};

    // Вспомогательный метод для проверки значений
    void validate_value(short value) const
    {
        if (value < 0 || value > 255)
        {
            throw ColorRGBValueError();
        }
    }

    // Вспомогательный метод для проверки индекса
    void validate_index(int indx) const
    {
        if (indx < 0 || indx > 2)
        {
            throw ColorRGBIndexError();
        }
    }

public:
    // Конструктор по умолчанию
    ColorRGB() noexcept = default;

    // Конструктор с параметрами
    ColorRGB(short r, short g, short b)
    {
        validate_value(r);
        validate_value(g);
        validate_value(b);
        this->r = r;
        this->g = g;
        this->b = b;
    }

    // Метод установки значений
    void set_rgb(short r, short g, short b)
    {
        validate_value(r);
        validate_value(g);
        validate_value(b);
        this->r = r;
        this->g = g;
        this->b = b;
    }

    // Оператор [] для чтения
    short operator[](int indx) const
    {
        validate_index(indx);
        switch (indx)
        {
        case 0:
            return r;
        case 1:
            return g;
        case 2:
            return b;
        default:
            return 0; // никогда не выполнится из-за проверки
        }
    }

    // Вспомогательный класс для проверки присваивания
    class Proxy
    {
    private:
        ColorRGB &m_color;
        int m_index;

    public:
        Proxy(ColorRGB &color, int index) : m_color(color), m_index(index) {}

        // Оператор присваивания с проверкой значения
        Proxy &operator=(short value)
        {
            m_color.validate_value(value); // проверяем значение
            switch (m_index)
            {
            case 0:
                m_color.r = value;
                break;
            case 1:
                m_color.g = value;
                break;
            case 2:
                m_color.b = value;
                break;
            }
            return *this;
        }

        // Неявное преобразование к short для чтения
        operator short() const
        {
            switch (m_index)
            {
            case 0:
                return m_color.r;
            case 1:
                return m_color.g;
            case 2:
                return m_color.b;
            default:
                return 0;
            }
        }
    };

    // Оператор [] для записи с проверкой значения
    Proxy operator[](int indx)
    {
        validate_index(indx); // проверяем индекс
        return Proxy(*this, indx);
    }
};

/********** Main Function **********/

int main()
{
    try
    {
        ColorRGB yellow(255, 201, -14); // Здесь должно возникнуть исключение
    }
    catch (const ColorRGBIndexError &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (const ColorRGBValueError &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (const ColorRGBError &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    __ASSERT_TESTS__ // макроопределение для тестирования
        return 0;
}