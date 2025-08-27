/**********************************************************************
 * @file script8.cpp
 * @brief Структура dtime: конструктор, методы, main (embedded C++ style)
 * @version 1.0 (Stepik exercise)
 * @date 2025-08-27
 **********************************************************************/

#include <iostream>
#include <string>
#include <sstream>

/**
 * @brief Структура времени с конструктором и методами
 */
struct dtime
{
private:
    unsigned char hs, ms, sc;

public:
    dtime(unsigned char hours = 0, unsigned char minutes = 0, unsigned char seconds = 0)
        : hs(hours), ms(minutes), sc(seconds) {}
    /**
     * @brief Получить строку времени hh:mm:ss
     */
    std::string get_time(void) const
    {
        std::ostringstream oss;
        oss << (hs < 10 ? "0" : "") << static_cast<int>(hs) << ":"
            << (ms < 10 ? "0" : "") << static_cast<int>(ms) << ":"
            << (sc < 10 ? "0" : "") << static_cast<int>(sc);
        return oss.str();
    }
    /**
     * @brief Установить время
     */
    void set_time(unsigned char hours, unsigned char minutes, unsigned char seconds)
    {
        hs = hours;
        ms = minutes;
        sc = seconds;
    }
    /**
     * @brief Сумма двух времен
     */
    static dtime sum_time(const dtime &t1, const dtime &t2)
    {
        unsigned int s = t1.sc + t2.sc;
        unsigned int m = t1.ms + t2.ms + s / 60;
        unsigned char res_s = s % 60;
        unsigned char res_m = m % 60;
        unsigned char res_h = t1.hs + t2.hs + m / 60;
        return dtime(res_h, res_m, res_s);
    }
};

/*** Main Function ***/
int main(void)
{
    dtime tm1, tm2;
    unsigned int h1, m1, s1, h2, m2, s2;
    std::cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    tm1.set_time(h1, m1, s1);
    tm2.set_time(h2, m2, s2);
    dtime time_res = dtime::sum_time(tm1, tm2);
    std::cout << time_res.get_time() << std::endl;
    __ASSERT_TESTS__
    return 0;
}