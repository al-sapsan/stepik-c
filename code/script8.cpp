/**********************************************************************
 * @file script8.cpp
 * @brief Класс Thing: конструкторы, приватные проверки, методы вне класса
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-12
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс для хранения информации о товаре
 */
class Thing
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    Thing();
    /**
     * @brief Конструктор с параметрами
     * @param[in] id id товара
     * @param[in] price цена
     * @param[in] weight вес
     */
    Thing(long id, int price, double weight);
    /**
     * @brief Получить информацию
     * @param[out] id id
     * @param[out] price цена
     * @param[out] weight вес
     */
    void get_info(long &id, int &price, double &weight);

private:
    long id{0};         ///< id товара
    int price{0};       ///< цена товара
    double weight{0.0}; ///< вес товара
    /**
     * @brief Проверить цену
     * @param[in] x цена
     * @return true если x >= 0
     */
    bool check_price(int x);
    /**
     * @brief Проверить вес
     * @param[in] x вес
     * @return true если x >= 0
     */
    bool check_weight(double x);
};

/*** Methods Implementation ***/
Thing::Thing() : id(0), price(0), weight(0.0) {}

Thing::Thing(long id, int price, double weight) : id(id), price(0), weight(0.0)
{
    if (check_price(price))
        this->price = price;
    if (check_weight(weight))
        this->weight = weight;
}

void Thing::get_info(long &id, int &price, double &weight)
{
    id = this->id;
    price = this->price;
    weight = this->weight;
}

bool Thing::check_price(int x) { return x >= 0; }

bool Thing::check_weight(double x) { return x >= 0; }

/*** Main Function ***/
int main(void)
{
    Thing th(5, 53403, 87.4);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

        return 0;
}
