/**
 * @file    digit_mask.cpp
 * @brief   Заменяет все цифры в строке на символ '0'
 * @version 1.0
 * @date    2025-07-15
 */

#include <iostream>
#include <cstring>
#include <cstdint>

/*** Constants ***/
static constexpr size_t MAX_STR_LEN = 129;

/*** Function Prototypes ***/

/**
 * @brief Заменяет все цифры в строке на символ '0'
 * @param[in,out] str Входная строка, изменяется на месте
 */
void replace_digits_with_zero(char *str);

/*** Main Function ***/
int main()
{
    char input[MAX_STR_LEN];
    std::cin.getline(input, MAX_STR_LEN);

    replace_digits_with_zero(input);

    std::cout << input << "\n";
    return 0;
}

/*** Function Definitions ***/
void replace_digits_with_zero(char *str)
{
    for (size_t i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            str[i] = '0';
        }
    }
}
