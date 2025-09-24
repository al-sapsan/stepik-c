/**********************************************************************
 * @file script5.cpp
 * @brief Класс Wallet (embedded C++ style)
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-24
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс Wallet
 */
class Wallet
{
private:
    int volume;
    bool check_volume(int x);

public:
    explicit Wallet(int vol);
    void add(int vol);
    int get_volume();
};

/*** Methods Implementation ***/
Wallet::Wallet(int vol) : volume(vol) {}
bool Wallet::check_volume(int x) { return x >= 0; }
void Wallet::add(int vol)
{
    if (check_volume(vol))
        volume += vol;
}
int Wallet::get_volume() { return volume; }

/*** Main ***/
int main(void)
{
    Wallet wallet(544653);
    int vl = wallet.get_volume();

    __ASSERT_TESTS__ // макроопределение для тестирования
        return 0;
}
