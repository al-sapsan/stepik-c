/**********************************************************************
 * @file script2.cpp
 * @brief unique_ptr for thing, allocation, assignment
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-30
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <memory>

struct thing
{
    unsigned long uid;
    unsigned width, height, depth;
};

/*** Main Function ***/
int main(void)
{
    std::unique_ptr<thing> p_th(new thing);
    p_th->uid = 1;
    p_th->width = 10;
    p_th->height = 43;
    p_th->depth = 108;
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}
