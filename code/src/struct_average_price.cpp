/**
 * @file    script8.cpp
 * @brief   Выводит товары из заданной страны и их среднюю цену
 * @version 1.0
 * @date    2025-07-17
 */

#include <iostream>
#include <iomanip>
#include <string>

/*** Types ***/
struct Tovar
{
    std::string name;
    std::string country;
    double price;
};

/*** Main Function ***/
int main()
{
    const size_t N = 7;
    Tovar arr[N];
    for (size_t i = 0; i < N; ++i)
    {
        std::cin >> arr[i].name >> arr[i].country >> arr[i].price;
    }
    std::string search_country;
    std::cin >> search_country;
    double sum = 0.0;
    size_t count = 0;
    for (size_t i = 0; i < N; ++i)
    {
        if (arr[i].country == search_country)
        {
            std::cout << arr[i].name << " " << arr[i].country << " " << arr[i].price << std::endl;
            sum += arr[i].price;
            ++count;
        }
    }
    if (count > 0)
    {
        std::cout << std::fixed << std::setprecision(2) << (sum / count) << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
    return 0;
}
