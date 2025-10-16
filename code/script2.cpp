/************************************************************************
 * @file script2.cpp
 * @brief Реализация шаблонного класса Ellipse от GraphInterface
 * @version 1.0
 * @date 2025-10-16
 ************************************************************************/

#include <iostream>

template <typename T>
class GraphInterface
{
public:
    virtual void get_coords(T &x0, T &y0, T &x1, T &y1) const = 0;
    virtual void set_coords(T x0, T y0, T x1, T y1) = 0;
    virtual void draw() const = 0;
    virtual ~GraphInterface() {}
};

template <typename T>
/**
 * @brief Эллипс, заданный двумя координатами (x0,y0) и (x1,y1)
 *
 * Шаблонный класс Ellipse наследует интерфейс GraphInterface и
 * реализует методы для установки/получения координат и отображения
 * (печати) координат в консоль.
 *
 * @tparam T Тип координат
 */
class Ellipse : public GraphInterface<T>
{
private:
    T x0{0}; ///< первая координата x0
    T y0{0}; ///< первая координата y0
    T x1{0}; ///< вторая координата x1
    T y1{0}; ///< вторая координата y1

public:
    /**
     * @brief Конструктор по умолчанию, инициализирует координаты нулями
     */
    Ellipse() = default;

    /**
     * @brief Конструктор с параметрами
     * @param ax0 Значение x0
     * @param ay0 Значение y0
     * @param ax1 Значение x1
     * @param ay1 Значение y1
     */
    Ellipse(T ax0, T ay0, T ax1, T ay1) : x0(ax0), y0(ay0), x1(ax1), y1(ay1) {}

    /**
     * @brief Получить координаты эллипса
     * @param ox0 Ссылка для записи x0
     * @param oy0 Ссылка для записи y0
     * @param ox1 Ссылка для записи x1
     * @param oy1 Ссылка для записи y1
     */
    void get_coords(T &ox0, T &oy0, T &ox1, T &oy1) const override
    {
        ox0 = x0;
        oy0 = y0;
        ox1 = x1;
        oy1 = y1;
    }

    /**
     * @brief Установить координаты эллипса
     * @param ax0 Значение x0
     * @param ay0 Значение y0
     * @param ax1 Значение x1
     * @param ay1 Значение y1
     */
    void set_coords(T ax0, T ay0, T ax1, T ay1) override
    {
        x0 = ax0;
        y0 = ay0;
        x1 = ax1;
        y1 = ay1;
    }

    /**
     * @brief Отобразить координаты эллипса в формате: x0 y0 x1 y1\n
     */
    void draw() const override
    {
        std::cout << x0 << " " << y0 << " " << x1 << " " << y1 << '\n';
    }
};

int main()
{
    GraphInterface<short> *lst[] = {
        new Ellipse<short>(-5, 10, 0, 11),
        new Ellipse<short>(5, 2, -4, -3),
        new Ellipse<short>(1, 5, 10, 22)};

    for (auto &p : lst)
    {
        p->draw();
    }

    for (auto &p : lst)
        delete p;

#ifndef __ASSERT_TESTS__
#define __ASSERT_TESTS__
#endif

    __ASSERT_TESTS__
    return 0;
}
