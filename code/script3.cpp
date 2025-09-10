/**********************************************************************
 * @file script3.cpp
 * @brief Класс Thing: делегирующий конструктор, геттеры, динамическое создание
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-08
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <string>

/*** Class Definition ***/
/**
 * @brief Класс для хранения информации о предмете
 */
class Thing
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    Thing() { std::cout << "default constructor" << std::endl; }
    /**
     * @brief Конструктор с одним параметром
     * @param[in] name наименование
     */
    Thing(const std::string &name) : name(name), weight(0), price(0)
    {
        std::cout << "constructor 1" << std::endl;
    }
    /**
     * @brief Конструктор с тремя параметрами (делегирующий)
     * @param[in] name наименование
     * @param[in] weight вес
     * @param[in] price цена
     */
    Thing(const std::string &name, double weight, int price)
        : Thing(name)
    {
        this->weight = weight;
        this->price = price;
        std::cout << "constructor 3" << std::endl;
    }
    /**
     * @brief Получить наименование
     * @return std::string
     */
    std::string get_name() { return name; }
    /**
     * @brief Получить вес
     * @return double
     */
    double get_weight() { return weight; }
    /**
     * @brief Получить цену
     * @return int
     */
    int get_price() { return price; }

private:
    std::string name; ///< наименование предмета
    double weight{0}; ///< вес предмета
    int price{0};     ///< цена предмета
};

/*** Main Function ***/
int main(void)
{
    // создаём объект через делегирующий конструктор
    Thing *ptr_th = new Thing("HP Omen", 2.3, 120000);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

        // освобождаем память
        delete ptr_th;

    return 0;
}
