/**********************************************************************
 * @file script5.cpp
 * @brief Структуры AUTO и MEASURE, заполнение из переменных
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-15
 **********************************************************************/

#include <iostream>
#include <cstring>

/*** Typedefs ***/
using u16_t = unsigned short;
using f64_t = double;
using MEASURE = struct
{
    u16_t width_u16;
    u16_t height_u16;
    u16_t depth_u16;
};
using AUTO = struct
{
    char model_str[51];
    u16_t max_speed_u16;
    f64_t weight_f64;
    MEASURE m;
};

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    AUTO auto_sell = {0};
    char model_str[51] = {0};
    u16_t max_speed_u16 = 0;
    f64_t weight_f64 = 0.0;
    u16_t width_u16 = 0, height_u16 = 0, depth_u16 = 0;
    std::cin >> model_str >> max_speed_u16 >> weight_f64 >> width_u16 >> height_u16 >> depth_u16;
    std::strncpy(auto_sell.model_str, model_str, 50);
    auto_sell.model_str[50] = '\0';
    auto_sell.max_speed_u16 = max_speed_u16;
    auto_sell.weight_f64 = weight_f64;
    auto_sell.m.width_u16 = width_u16;
    auto_sell.m.height_u16 = height_u16;
    auto_sell.m.depth_u16 = depth_u16;
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}
