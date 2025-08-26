/**********************************************************************
 * @file script5.cpp
 * @brief Структура tag_time: методы get_time и sum_time (embedded C++ style)
 * @version 1.0 (Stepik exercise)
 * @date 2025-08-26
 **********************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

/**
 * @brief Структура времени с методами форматирования и сложения
 */
struct tag_time
{
    unsigned char hours;
    unsigned char minutes;
    unsigned char seconds;
    /**
     * @brief Формирует строку времени hh:mm:ss
     * @param str Буфер для строки
     * @param max_length Максимальная длина строки
     * @return Адрес строки str
     */
    char *get_time(char *str, size_t max_length) const
    {
        if (max_length < 9)
        { // "hh:mm:ss" + '\0'
            if (max_length > 0)
                str[0] = '\0';
            return str;
        }
        std::snprintf(str, max_length, "%02u:%02u:%02u", hours, minutes, seconds);
        return str;
    }
    /**
     * @brief Складывает два времени
     * @param t1 Первое время
     * @param t2 Второе время
     * @return Сумма времен
     */
    static tag_time sum_time(const tag_time &t1, const tag_time &t2)
    {
        tag_time res;
        unsigned int s = t1.seconds + t2.seconds;
        unsigned int m = t1.minutes + t2.minutes + s / 60;
        res.seconds = s % 60;
        res.minutes = m % 60;
        res.hours = t1.hours + t2.hours + m / 60;
        return res;
    }
};

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 * @return Код завершения (0 — успешно, 1 — ошибка памяти)
 */
int main(void)
{
    tag_time tm1, tm2;
    std::cin >> tm1.hours >> tm1.minutes >> tm1.seconds >> tm2.hours >> tm2.minutes >> tm2.seconds;
    tag_time time_res = tag_time::sum_time(tm1, tm2);
    char arr_str_time[16];
    std::cout << time_res.get_time(arr_str_time, sizeof(arr_str_time)) << std::endl;
    __ASSERT_TESTS__
    return 0;
}
