/**********************************************************************
 * @file script7.cpp
 * @brief Password check (embedded C++ style)
 * @version 1.0
 * @date 2025-08-20
 **********************************************************************/

#include "emb_style_cpp_en.h"
#include <iostream>
#include <cstring>

/*** Function Prototypes ***/
/**
 * @brief  Проверяет корректность пароля
 * @param  password  Си-строка (пароль)
 * @param  chars     Строка символов для проверки (по умолчанию "$%!?@#")
 * @return true, если пароль корректен, иначе false
 */
bool check_password(const char *password, const char *chars = "$%!?@#");

/*** Main Function ***/
int main(void)
{
    char password[128] = {0};
    std::cin >> password;
    bool valid = check_password(password);
    std::cout << (valid ? "yes" : "no") << std::endl;
    return 0;
}

/*** Function Implementation ***/
bool check_password(const char *password, const char *chars)
{
    size_t len = std::strlen(password);
    if (len < 8)
    {
        return false;
    }
    for (size_t i = 0; i < len; ++i)
    {
        if (std::strchr(chars, password[i]) != nullptr)
        {
            return true;
        }
    }
    return false;
}
