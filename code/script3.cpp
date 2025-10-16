/************************************************************************
 * @file script3.cpp
 * @brief Классы Window и Rect и шаблон get_square
 * @date 2025-10-16
 ************************************************************************/

#include <iostream>
#include <exception>
#include <string>

// ********** Exception Classes **********/

/**
 * @brief Класс исключения ValueError
 *
 * Используется при передаче невалидных (нуль или отрицательных) размеров в конструкторах.
 */
class ValueError : public std::exception
{
    std::string m_msg;

public:
    /**
     * @brief Конструктор исключения
     * @param msg Сообщение об ошибке
     */
    explicit ValueError(const std::string &msg) noexcept : m_msg(msg) {}

    /**
     * @brief Возвращает сообщение об ошибке
     */
    const char *what() const noexcept override { return m_msg.c_str(); }
};

// ************ Class Definition ***********/

/**
 * @brief Класс Window — прямоугольное окно с целочисленными размерами
 *
 * Поля width и height имеют тип int. Конструктор генерирует ValueError,
 * если переданы нулевые или отрицательные значения.
 */
class Window
{
    int m_width{0};
    int m_height{0};

public:
    Window(int width, int height)
    {
        if (width <= 0 || height <= 0)
            throw ValueError("The value must be positive");
        m_width = width;
        m_height = height;
    }
    /**
     * @brief Получить размеры окна
     * @param width Ссылка для записи ширины
     * @param height Ссылка для записи высоты
     */
    void get_data(int &width, int &height) const
    {
        width = m_width;
        height = m_height;
    }
};

/**
 * @brief Класс Rect — прямоугольник с вещественными размерами
 *
 * Поля width и height имеют тип double. Конструктор генерирует ValueError,
 * если переданы нулевые или отрицательные значения.
 */
class Rect
{
    double m_width{0};
    double m_height{0};

public:
    Rect(double width, double height)
    {
        if (width <= 0.0 || height <= 0.0)
            throw ValueError("The value must be positive");
        m_width = width;
        m_height = height;
    }
    /**
     * @brief Получить размеры прямоугольника
     * @param width Ссылка для записи ширины
     * @param height Ссылка для записи высоты
     */
    void get_data(double &width, double &height) const
    {
        width = m_width;
        height = m_height;
    }
};

// Template get_square
template <typename Obj, typename ValT = int>
ValT get_square(const Obj &obj)
{
    ValT w{};
    ValT h{};
    obj.get_data(w, h);
    return static_cast<ValT>(w * h);
}

int main()
{
    try
    {
        Window w(100, -5);
        auto res_sq = get_square<Window, int>(w);
        (void)res_sq;
    }
    catch (const ValueError &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    __ASSERT_TESTS__
    return 0;
}
