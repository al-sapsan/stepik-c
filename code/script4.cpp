/**********************************************************************
 * @file script4.cpp
 * @brief Копирование структуры tag_price и вывод полей (embedded C++ style)
 * @version 1.0 (Stepik exercise)
 * @date 2025-08-26
 **********************************************************************/

#include <iostream>
#include <cstring>

/**
 * @brief Структура цены товара
 */
struct tag_price
{
    char name[100];
    unsigned int rubs;
    unsigned char kops;
    unsigned int foreign_key;
};

extern tag_price price_100;

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 * @return Код завершения (0 — успешно, 1 — ошибка памяти)
 */
int main(void)
{
    tag_price pr;
    std::memcpy(&pr, &price_100, sizeof(tag_price));
    std::cout << pr.name << " " << pr.rubs << " " << static_cast<unsigned int>(pr.kops) << " " << pr.foreign_key << std::endl;
    __ASSERT_TESTS__
    return 0;
}
