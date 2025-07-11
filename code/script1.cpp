/**
 * @brief Проверка, заканчивается ли строка s на подстроку t
 * @version 1.0
 */

#include <cstdio>
#include <cstring>

//=== Прототипы функций ===

/**
 * @brief Проверяет, заканчивается ли строка на подстроку
 * @param[in,out] s Строка
 * @param[in,out] t Суффикс
 * @return true Если s заканчивается на t
 * @return false В противном случае
 */
bool findend(char *s, char *t);

//=== main ===

/**
 * @brief Точка входа
 * @return int Код завершения
 */
int main()
{
    constexpr int MAXLEN = 128;
    char l_str_s[MAXLEN];
    char l_str_t[MAXLEN];

    std::fgets(l_str_s, MAXLEN, stdin);
    std::fgets(l_str_t, MAXLEN, stdin);

    if (findend(l_str_s, l_str_t))
    {
        std::puts("Yes");
    }
    else
    {
        std::puts("No");
    }

    return 0;
}

//=== Реализация функций ===

bool findend(char *s, char *t)
{
    int l_len_s = std::strlen(s);
    int l_len_t = std::strlen(t);

    if (l_len_s > 0 && s[l_len_s - 1] == '\n')
    {
        s[l_len_s - 1] = '\0';
        l_len_s--;
    }

    if (l_len_t > 0 && t[l_len_t - 1] == '\n')
    {
        t[l_len_t - 1] = '\0';
        l_len_t--;
    }

    if (l_len_t > l_len_s)
    {
        return false;
    }

    for (int l_i = 0; l_i < l_len_t; l_i++)
    {
        if (s[l_len_s - l_len_t + l_i] != t[l_i])
        {
            return false;
        }
    }

    return true;
}
