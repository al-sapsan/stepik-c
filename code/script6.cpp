/**********************************************************************
 * @file script6.cpp
 * @brief sum_ar for shared_ptr<int[]>, read and sum up to max_size_ar
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-30
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <memory>

enum
{
    max_size_ar = 10
};
using shared_ari_ptr = std::shared_ptr<int[]>;

int sum_ar(const shared_ari_ptr &ar, size_t len)
{
    int sum = 0;
    for (size_t i = 0; i < len; ++i)
        sum += ar[i];
    return sum;
}

/*** Main Function ***/
int main(void)
{
    shared_ari_ptr ar{new int[max_size_ar]{0}};
    unsigned count = 0;
    int val = 0;
    while (count < max_size_ar && std::cin >> val)
    {
        ar[count++] = val;
    }
    std::cout << sum_ar(ar, count) << std::endl;
    return 0;
}
