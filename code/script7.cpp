/**********************************************************************
 * @file script7.cpp
 * @brief Класс Wallet: только конструктор с параметром, приватная проверка, методы вне класса
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-12
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Кошелёк для хранения средств
 */
class Wallet
{
public:
    /**
     * @brief Конструктор с параметром
     * @param[in] vol начальный объём
     */
    Wallet(int vol);
    /**
     * @brief Добавить средства
     * @param[in] vol сумма
     */
    void add(int vol);
    /**
     * @brief Получить объём
     * @return int
     */
    int get_volume();
    // Запретить конструктор по умолчанию
    Wallet() = delete;

private:
    int volume{0}; ///< объём средств
    /**
     * @brief Проверить корректность суммы
     * @param[in] x сумма
     * @return true если x >= 0
     */
    bool check_volume(int x);
};

/*** Methods Implementation ***/
Wallet::Wallet(int vol) : volume(0)
{
    if (check_volume(vol))
        volume = vol;
}

void Wallet::add(int vol)
{
    if (check_volume(vol))
        volume += vol;
}

int Wallet::get_volume() { return volume; }

bool Wallet::check_volume(int x) { return x >= 0; }

/*** Main Function ***/
int main(void)
{
    Wallet wallet(544653);
    int vl = wallet.get_volume();

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

        return 0;
}
