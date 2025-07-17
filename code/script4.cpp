/**
 * @file    script4.cpp
 * @brief   Выводит автомобили заданного цвета и лучший по объему двигателя
 * @version 1.0
 * @date    2025-07-17
 */

#include <iostream>
#include <iomanip>
#include <string>

/*** Types ***/
struct Avto
{
    std::string number;
    std::string brand;
    double engine;
    std::string color;
};

/*** Main Function ***/
int main()
{
    const int N = 5;
    Avto arr[N];
    for (int i = 0; i < N; ++i)
    {
        std::cin >> arr[i].number >> arr[i].brand >> arr[i].engine >> arr[i].color;
    }
    std::string search_color;
    std::cin >> search_color;
    int found = 0;
    int best_idx = -1;
    for (int i = 0; i < N; ++i)
    {
        if (arr[i].color == search_color)
        {
            std::cout << arr[i].number << " " << arr[i].brand << std::endl;
            if (best_idx == -1 || arr[i].engine > arr[best_idx].engine)
                best_idx = i;
            ++found;
        }
    }
    if (found > 0)
    {
        std::cout << "The best: " << arr[best_idx].number << " " << arr[best_idx].brand << " "
                  << std::fixed << std::setprecision(1) << arr[best_idx].engine << " " << arr[best_idx].color << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
    return 0;
}
