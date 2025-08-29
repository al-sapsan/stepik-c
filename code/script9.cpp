/**********************************************************************
 * @file script9.cpp
 * @brief struct vector with destructor output, dynamic allocation
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-29
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Typedefs ***/
typedef int i32_t;

struct vector
{
    i32_t x, y, z;
    /*** Function Prototypes ***/
    /**
     * @brief Деструктор
     * @details Выводит "Deleted vector: x, y, z" при удалении
     */
    ~vector()
    {
        std::cout << "Deleted vector: " << x << ", " << y << ", " << z << std::endl;
    }
};

/*** Main Function ***/
int main(void)
{
    i32_t x = 0, y = 0, z = 0;
    std::cin >> x >> y >> z;
    vector *ptr_vec = new vector;
    ptr_vec->x = x;
    ptr_vec->y = y;
    ptr_vec->z = z;
    delete ptr_vec;
    return 0;
}
