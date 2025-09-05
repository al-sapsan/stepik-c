/**********************************************************************
 * @file script5.cpp
 * @brief struct Goods: публичные поля, методы, main
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-05
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <string>

/*** Struct Definition ***/
/**
 * @brief Структура для хранения информации о товаре
 */
struct Goods
{
    std::string name; ///< название
    double weight;    ///< вес
    int price;        ///< цена
    /*** Function Prototypes ***/
    /**
     * @brief Получить ссылку на название
     * @return ссылка на name
     */
    const std::string &get_name() { return name; }
    /**
     * @brief Получить вес
     * @return вес
     */
    double get_weight() { return weight; }
    /**
     * @brief Получить цену
     * @return цена
     */
    int get_price() { return price; }
};

/*** Main Function ***/
int main(void)
{
    Goods book, toy;
    book.name = "Основы ООП";
    book.weight = 234.5;
    book.price = 2000;
    toy.name = "Oculus Quest 3";
    toy.weight = 204.6;
    toy.price = 80000;
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)
        return 0;
}
