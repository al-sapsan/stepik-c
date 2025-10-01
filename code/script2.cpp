/**********************************************************************
 * @file script2.cpp
 * @brief Thing, Table, TV, Cart implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-09-26
 **********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

/********** Class Definition **********/

// == < Thing > == //
/**
 * @brief Класс товара
 * @param name Название товара
 * @param price Цена товара
 */
class Thing
{
protected:
    std::string m_name;
    int m_price{0};

public:
    Thing(const std::string &name = "", int price = 0)
        : m_name(name), m_price(price) {}

    const std::string &get_name() const { return m_name; }
    int get_price() const { return m_price; }
    virtual void print() {}
    virtual ~Thing() {}
};

// == < Table > == //
/**
 * @brief Класс стола
 * @param color Цвет
 * @param weight Вес
 */
class Table : public Thing
{
private:
    int m_color{0};
    double m_weight{0.0};

public:
    Table(const std::string &name, int price, int color, double weight)
        : Thing(name, price), m_color(color), m_weight(weight) {}

    virtual void print() override
    {
        std::cout << "Table: " << m_name << ", " << m_price << ", " << m_color << ", "
                  << std::fixed << std::setprecision(2) << m_weight << std::endl;
    }
};

// == < TV > == //
/**
 * @brief Класс телевизора
 * @param size Размер
 */
class TV : public Thing
{
private:
    int m_size{0};

public:
    TV(const std::string &name, int price, int size)
        : Thing(name, price), m_size(size) {}

    virtual void print() override
    {
        std::cout << "TV: " << m_name << ", " << m_price << ", " << m_size << std::endl;
    }
};

// == < Cart > == //
/**
 * @brief Класс корзины
 */
class Cart
{
    enum
    {
        max_total_thing = 100
    };
    Thing *m_goods[max_total_thing]{nullptr};
    int m_count{0};

public:
    void append(Thing *th)
    {
        if (m_count >= max_total_thing)
            return;
        m_goods[m_count++] = th;
    }

    Thing **get_goods() { return m_goods; }
    int get_count() const { return m_count; }

    void show()
    {
        for (int i = 0; i < m_count; ++i)
        {
            if (m_goods[i])
                m_goods[i]->print();
        }
    }
};

/********** Main Function **********/

int main(void)
{
    Cart cart;
    cart.append(new Table("Стол", 12000, 0, 12.70));
    cart.append(new TV("Panasonic", 54000, 43));
    cart.append(new TV("Samsung", 83500, 54));
    cart.append(new Table("Стол 2", 9500, 432, 10.74));

    cart.show();

    __ASSERT_TESTS__

    // Освобождение памяти
    Thing **goods = cart.get_goods();
    int count = cart.get_count();
    for (int i = 0; i < count; ++i)
    {
        delete goods[i];
    }

    return 0;
}