/**
 * @file    struct_compare.cpp
 * @brief   Выводит номер и пункт назначения рейса с наибольшим номером
 * @version 1.0
 * @date    2025-07-17
 */

#include <iostream>
#include <string>

/*** Types ***/
struct Aeroflot
{
    int flight_number;
    char destination[64];
    char plane_type[64];
};

/*** Main Function ***/
int main()
{
    Aeroflot a1, a2;
    std::cin >> a1.flight_number >> a1.destination >> a1.plane_type;
    std::cin >> a2.flight_number >> a2.destination >> a2.plane_type;
    const Aeroflot &max_flight = (a1.flight_number >= a2.flight_number) ? a1 : a2;
    std::cout << max_flight.flight_number << " " << max_flight.destination << std::endl;
    return 0;
}
