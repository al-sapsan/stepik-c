/**********************************************************************
 * @file script9.cpp
 * @brief Lambda for triangle area (embedded C++ style)
 * @version 1.1
 * @date 2025-08-22
 **********************************************************************/

#include "emb_style_cpp_en.h"
#include <iostream>
#include <cmath>

int main(void)
{
    int a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;

    auto sq_tr = [](int a, int b, int c) -> double
    {
        double p = (a + b + c) / 2.0;
        return std::sqrt(p * (p - a) * (p - b) * (p - c));
    };

    double result = sq_tr(a, b, c);
    std::cout << std::fixed << std::setprecision(2) << result << std::endl;

    __ASSERT_TESTS__
    return 0;
}
