/**********************************************************************
 * @file script1.cpp
 * @brief Класс CartData: приватные поля, публичные методы, main
 * @version 1.0 (Stepik exercise)
 * @date 2025-09-05
 **********************************************************************/

/*** Libraries ***/
#include <iostream>
#include <cstring>

/*** Main Class ***/
/**
 * @brief Класс для хранения данных о товаре (корзина)
 */
class CartData
{
private:
    unsigned long id;
    char name[100];
    unsigned price;
    double weight;

public:
    /**
     * @brief Возвращает значения id, price, weight по ссылкам
     * @param[out] id_ ссылка для id
     * @param[out] price_ ссылка для price
     * @param[out] weight_ ссылка для weight
     */
    void get_data(unsigned long &id_, unsigned &price_, double &weight_)
    {
        id_ = id;
        price_ = price;
        weight_ = weight;
    }

    /**
     * @brief Возвращает указатель на строку name
     * @return указатель на name
     */
    char *get_name()
    {
        return name;
    }

    /**
     * @brief Заносит значения в поля id, name, price, weight
     * @param[in] id_ идентификатор
     * @param[in] name_ имя товара (строка)
     * @param[in] price_ цена
     * @param[in] weight_ вес
     */
    void set_data(unsigned long id_, const char *name_, unsigned price_, double weight_)
    {
        id = id_;
        std::strncpy(name, name_, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0';
        price = price_;
        weight = weight_;
    }
};

/*** Main Function ***/
int main(void)
{
    CartData item;
    item.set_data(10, "Toy", 2000, 5.45);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;