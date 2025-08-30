/**********************************************************************
 * @file script5.cpp
 * @brief shared_ptr for short, print bytes as unsigned decimals
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
    std::shared_ptr<short> p_val(new short);
    *p_val = static_cast<short>(x);
    unsigned char *ptr = reinterpret_cast<unsigned char *>(p_val.get());
    for (size_t i = 0; i < sizeof(short); ++i)
    {
        std::cout << static_cast<unsigned int>(ptr[i]) << " ";
    }
    std::cout << std::endl;
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}
