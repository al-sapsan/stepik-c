/**
 * @file    replace_dot_comma.cpp
 * @brief   Замена последовательности ".," на символ ';' в строке
 * @version 1.0
 * @date    2025-07-08
 */

#include <cstdio>
#include <cstring>

/**
 * @brief   Удаляет символ по указанному адресу в строке
 * @param[in,out] ptr  Указатель на удаляемый символ
 */
void strdel(char *ptr);

/**
 * @brief   Точка входа в программу
 * @return  0 при успешном завершении
 */
int main()
{
    constexpr int MAXLEN = 101; // 100 символов + '\0'
    char mystring[MAXLEN];

    std::fgets(mystring, MAXLEN, stdin);

    // Удаляем символ новой строки, если он есть
    std::size_t len = std::strlen(mystring);
    if (len > 0 && mystring[len - 1] == '\n')
    {
        mystring[len - 1] = '\0';
    }

    char *ptr = mystring;

    while (*ptr != '\0' && *(ptr + 1) != '\0')
    {
        if (*ptr == '.' && *(ptr + 1) == ',')
        {
            *ptr = ';';
            strdel(ptr + 1);
        }
        else
        {
            ptr++;
        }
    }

    std::puts(mystring);
    return 0;
}

/**
 * @brief   Сдвигает строку влево начиная с позиции ptr, удаляя один символ
 * @param[in,out] ptr  Указатель на позицию удаления
 */
void strdel(char *ptr)
{
    while (*ptr != '\0')
    {
        *ptr = *(ptr + 1);
        ptr++;
    }
}
