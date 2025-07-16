/**
 * @file    script7.cpp
 * @brief   Prints the longest word from a user input string (words separated by spaces)
 * @version 1.0
 * @date    2025-07-16
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

/*** Constants ***/
static const size_t MAX_STR_LEN = 129;

/*** Function Prototypes ***/
/**
 * @brief Finds and prints the longest word in a string
 * @param[in] str Input string
 */
void print_longest_word(const char *str);

/*** Main Function ***/
int main(void)
{
    char input[MAX_STR_LEN];
    if (fgets(input, MAX_STR_LEN, stdin) == NULL)
        return 1;
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
        input[len - 1] = '\0';
    print_longest_word(input);
    return 0;
}

/*** Function Definitions ***/
void print_longest_word(const char *str)
{
    size_t i = 0, n = strlen(str);
    size_t max_start = 0, max_len = 0;
    while (i < n)
    {
        // Skip spaces
        while (i < n && str[i] == ' ')
            ++i;
        if (i == n)
            break;
        size_t start = i;
        while (i < n && str[i] != ' ')
            ++i;
        size_t word_len = i - start;
        if (word_len > max_len)
        {
            max_len = word_len;
            max_start = start;
        }
    }
    if (max_len > 0)
        printf("%.*s\n", (int)max_len, str + max_start);
}
