/**********************************************************************
 * @file script9.cpp
 * @brief Furniture, Table, Chair class implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-09-25
 **********************************************************************/

#include <iostream>
#include <string>

/********** Class Prototypes **********/
// == < Furniture > == //
/**
 * @brief Класс мебели
 * @param width Ширина
 * @param height Высота
 * @param depth Глубина
 * @param type Тип мебели
 */
class Furniture
{
public:
    enum type_furniture
    {
        fr_none = 0,
        fr_table = 1,
        fr_chair = 2,
        fr_closet = 3
    };

protected:
    short m_width{0}, m_height{0}, m_depth{0};
    type_furniture m_type{fr_none};

public:
    Furniture(short width, short height, short depth, type_furniture type);
    Furniture() = delete;

    void get_dims(short &width, short &height, short &depth) const;
    type_furniture get_type() const;
};

// == < Table > == //
/**
 * @brief Класс стола
 * @param model Модель стола
 */
class Table : public Furniture
{
private:
    std::string m_model;

public:
    Table(const std::string &model, short width, short height, short depth);

    const std::string &get_model() const;
};

// == < Chair > == //
/**
 * @brief Класс стула
 * @param color Цвет
 * @param weight Вес
 */
class Chair : public Furniture
{
private:
    int m_color{0};
    int m_weight{0};

public:
    Chair(short width, short height, short depth, int color, int weight);

    void get_data(int &color, int &weight) const;
};

/********** Main Function **********/
int main(void)
{
    Furniture *fr_lst[5];

    fr_lst[0] = new Table("Черноземья стол 10", 10, 20, 30);
    fr_lst[1] = new Table("Белоземья стол 21", 6, 5, 22);
    fr_lst[2] = new Chair(3, 5, 7, 132, 1650);
    fr_lst[3] = new Chair(3, 6, 5, 200, 1750);
    fr_lst[4] = new Table("Бурый стол", 11, 6, 8);

    __ASSERT_TESTS__

    for (int i = 0; i < 5; ++i)
    {
        delete fr_lst[i];
    }

    return 0;
}

/********** Function Implementations **********/
// == < Furniture Implementation > == //
Furniture::Furniture(short width, short height, short depth, type_furniture type)
    : m_width(width), m_height(height), m_depth(depth), m_type(type)
{
}

void Furniture::get_dims(short &width, short &height, short &depth) const
{
    width = m_width;
    height = m_height;
    depth = m_depth;
}

Furniture::type_furniture Furniture::get_type() const
{
    return m_type;
}

// == < Table Implementation > == //
Table::Table(const std::string &model, short width, short height, short depth)
    : Furniture(width, height, depth, fr_table), m_model(model)
{
}

const std::string &Table::get_model() const
{
    return m_model;
}

// == < Chair Implementation > == //
Chair::Chair(short width, short height, short depth, int color, int weight)
    : Furniture(width, height, depth, fr_chair), m_color(color), m_weight(weight)
{
}

void Chair::get_data(int &color, int &weight) const
{
    color = m_color;
    weight = m_weight;
}