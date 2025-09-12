/**********************************************************************
 * @file script4.cpp
 * @brief Класс Flower: только конструктор с параметрами, запрет копирования и default
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-10
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <cstring>

/*** Class Definition ***/
/**
 * @brief Класс для хранения информации о цветке
 */
class Flower
{
public:
    /**
     * @brief Конструктор с параметрами
     * @param[in] name название цветка
     * @param[in] price цена
     */
    Flower(const char *name, int price) : price(price)
    {
        std::strncpy(this->name, name, sizeof(this->name) - 1);
        this->name[sizeof(this->name) - 1] = '\0';
    }
    /**
     * @brief Получить данные
     * @param[out] name название
     * @param[out] price цена
     */
    void get_data(char *name, int &price)
    {
        std::strcpy(name, this->name);
        price = this->price;
    }
    // Запретить конструктор по умолчанию и копирования
    Flower() = delete;
    Flower(const Flower &) = delete;
    Flower &operator=(const Flower &) = delete;

private:
    char name[100] = {0}; ///< название цветка
    int price{0};         ///< цена цветка
};

/*** Main Function ***/
int main(void)
{
    Flower flower("Тюльпан", 120);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

        return 0;
}
