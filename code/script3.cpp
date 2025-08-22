/**********************************************************************
 * @file script3.cpp
 * @brief Inline max of three values (embedded C++ style)
 * @version 1.1
 * @date 2025-08-22
 **********************************************************************/

#include "emb_style_cpp_en.h"
#include <iostream>

/*** Function Prototypes ***/
/**
 * @brief  Возвращает максимальное из трех целых чисел
 * @param  a  Первое число
 * @param  b  Второе число
 * @param  c  Третье число
 * @return Максимальное целое число
 */
inline int get_max_3(int a, int b, int c);

/*** Main Function ***/
int main(void)
{
    int a = 0;
    int b = 0;
    int c = 0;
    std::cin >> a >> b >> c;
    int result = get_max_3(a, b, c);
    std::cout << result << std::endl;
    return 0;
}

/*** Function Implementation ***/
inline int get_max_3(int a, int b, int c)
{
    int max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    return max;
}
