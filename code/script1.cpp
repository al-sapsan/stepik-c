/**********************************************************************
 * @file script1.cpp
 * @brief unique_ptr for int, allocation, assignment, output
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-30
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <memory>

/*** Main Function ***/
int main(void)
{
    int x;
    std::cin >> x;
    std::unique_ptr<int> p_int(new int);
    *p_int = x;
    std::cout << *p_int << std::endl;
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}
