/**********************************************************************
 * @file    script6.cpp
 * @brief   Read and print THING struct (Stepik 9.3.7)
 * @version 1.0
 * @date
 *
 * @note    Embedded C++ style
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Constants ***/
enum
{
    max_size_name = 50
};

/*** Typedefs ***/
typedef struct
{
    unsigned int id_u32;
    char name_arr_i8[max_size_name];
    double weight_f64;
    unsigned int price_u32;
} THING_t;

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Считывает структуру THING, выводит в формате <name> <id>: <weight>, <price>
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    THING_t box_st;
    std::cin >> box_st.id_u32 >> box_st.name_arr_i8 >> box_st.weight_f64 >> box_st.price_u32;
    std::cout << box_st.name_arr_i8 << " " << box_st.id_u32 << ": " << box_st.weight_f64 << ", " << box_st.price_u32 << std::endl;
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}
