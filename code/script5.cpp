/**
 * @file    operator_counter.cpp
 * @brief   Подсчет количества арифметических знаков в строке
 * @version 1.0
 * @date    2025-07-15
 */

#include <iostream>
#include <cstring>
#include <cstdint>

/*** Constants ***/
static constexpr size_t MAX_STR_LEN = 21;

/*** Function Prototypes ***/

/**
 * @brief Подсчитывает количество арифметических операторов в строке
 * @param[in] str Строка (максимум 20 символов + '\0')
 * @return Количество знаков +, -, *, /, %
 */
size_t count_operators(const char *str);

/*** Main Function ***/
int main()
{
    char input[MAX_STR_LEN];
    std::cin.getline(input, MAX_STR_LEN);
    std::cout << count_operators(input) << "\n";
    return 0;
}

/*** Function Definitions ***/
size_t count_operators(const char *str)
{
    size_t count = 0;
    for (size_t i = 0; str[i] != '\0'; ++i)
    {
        switch (str[i])
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            ++count;
            break;
        default:
            break;
        }
    }
    return count;
}
