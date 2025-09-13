/**********************************************************************
 * @file script2.cpp
 * @brief Класс Window: статический счётчик, методы вне класса, только конструктор с параметрами
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-12
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс для хранения параметров окна
 */
class Window
{
public:
    /**
     * @brief Конструктор с параметрами
     * @param[in] width ширина
     * @param[in] height высота
     * @param[in] color цвет
     */
    Window(int width, int height, int color);
    /**
     * @brief Установить размер
     * @param[in] w ширина
     * @param[in] h высота
     */
    void set_size(int w, int h);
    /**
     * @brief Получить размер
     * @param[out] w ширина
     * @param[out] h высота
     */
    void get_size(int &w, int &h);
    /**
     * @brief Получить цвет
     * @return int
     */
    int get_color();
    /**
     * @brief Получить общее число окон (статический)
     * @return unsigned long
     */
    static unsigned long get_total();
    // Запретить конструктор по умолчанию
    Window() = delete;

private:
    static unsigned long total;
    int width, height, color;
};

/*** Static Members Initialization ***/
unsigned long Window::total = 0;

/*** Methods Implementation ***/
Window::Window(int width, int height, int color)
    : width(width), height(height), color(color)
{
    ++total;
}

void Window::set_size(int w, int h)
{
    width = w;
    height = h;
}

void Window::get_size(int &w, int &h)
{
    w = width;
    h = height;
}

int Window::get_color() { return color; }

unsigned long Window::get_total() { return total; }

/*** Main Function ***/
int main(void)
{
    Window *ptr_wnd = new Window(200, 100, 255);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

        delete ptr_wnd;
    ptr_wnd = nullptr;
    return 0;
}
