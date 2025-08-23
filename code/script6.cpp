/**********************************************************************
 * @file script6.cpp
 * @brief Lambda sum with capture (embedded C++ style)
 * @version 1.1
 * @date 2025-08-23
 **********************************************************************/

#include <iostream>

/*** Main Function ***/
int main(void)
{
    int w = 0, h = 0;
    std::cin >> w >> h;
    auto sum_ab = [w, h]()
    { return w + h; };
    std::cout << sum_ab() << std::endl;
    __ASSERT_TESTS__
    return 0;
}
