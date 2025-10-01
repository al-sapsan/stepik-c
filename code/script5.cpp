/**********************************************************************
 * @file script5.cpp
 * @brief Dish, FishDish, MeatDish implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-09-30
 **********************************************************************/

#include <iostream>
#include <string>

/********** Class Definition **********/
// == < Dish > == //
/**
 * @brief Класс блюда
 * @param name Наименование
 * @param price Цена
 */
class Dish
{
protected:
    std::string m_name;
    int m_price{0};

public:
    Dish(const std::string &name, int price)
        : m_name(name), m_price(price) {}

    virtual void print_dish()
    {
        std::cout << "Dish: " << m_name << "; " << m_price << std::endl;
    }
    virtual ~Dish() {}
};

// == < FishDish > == //
/**
 * @brief Класс рыбного блюда
 * @param weight Вес
 */
class FishDish : public Dish
{
private:
    int m_weight{0};

public:
    FishDish(const std::string &name, int price, int weight)
        : Dish(name, price), m_weight(weight) {}

    virtual void print_dish() override
    {
        std::cout << "FishDish: " << m_name << "; " << m_price << "; " << m_weight << std::endl;
    }
};

// == < MeatDish > == //
/**
 * @brief Класс мясного блюда
 * @param fry_type Тип прожарки
 * @param weight Вес
 */
class MeatDish : public Dish
{
private:
    short m_fry_type{1};
    int m_weight{0};

public:
    MeatDish(const std::string &name, int price, short fry_type, int weight)
        : Dish(name, price), m_fry_type(fry_type), m_weight(weight) {}

    virtual void print_dish() override
    {
        std::cout << "MeatDish: " << m_name << "; " << m_price << "; " << m_fry_type << "; " << m_weight << std::endl;
    }
};

/********** Main Function **********/
int main(void)
{
    FishDish *ptr_fd_1 = new FishDish("Устрицы", 900, 300);
    MeatDish *ptr_md_1 = new MeatDish("Бекон", 800, 2, 420);
    FishDish *ptr_fd_2 = new FishDish("Форель", 400, 210);

    Dish *dishes[3];
    dishes[0] = ptr_fd_1;
    dishes[1] = ptr_md_1;
    dishes[2] = ptr_fd_2;

    for (int i = 0; i < 3; ++i)
    {
        dishes[i]->print_dish();
    }

    __ASSERT_TESTS__

    for (int i = 0; i < 3; ++i)
    {
        delete dishes[i];
    }

    return 0;
}