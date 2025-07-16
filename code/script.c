
/**
 * @file    digit_remove.cpp
 * @brief   Удаляет все цифры из строки
 * @version 1.0
 * @date    2025-07-16
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

/*** Constants ***/
static const size_t MAX_STR_LEN = 129;

/*** Function Prototypes ***/

/**
 * @brief Удаляет все цифры из строки
 * @param[in,out] str Входная строка, изменяется на месте
 */
void remove_digits(char *str);

/*** Main Function ***/
int main(void)
{
    char input[MAX_STR_LEN];
    fgets(input, MAX_STR_LEN, stdin);
    // Удаляем символ новой строки, если есть
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
        input[len - 1] = '\0';

    remove_digits(input);

    printf("%s\n", input);
    return 0;
}

/*** Function Definitions ***/
void remove_digits(char *str)
{
    size_t write = 0;
    for (size_t read = 0; str[read] != '\0'; ++read)
    {
        if (str[read] < '0' || str[read] > '9')
        {
            str[write++] = str[read];
        }
    }
    str[write] = '\0';
}
