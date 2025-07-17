/**
 * @file struct_bit_fields.cpp
 * @brief Работа со структурой Weather с использованием битовых полей
 * @version 1.0
 * @date 2025-07-17
 *
 * @note Используются битовые поля для экономии памяти
 * @warning Не осуществляется проверка на переполнение при вводе
 */

#include <iostream>

/*** Data Types ***/

/**
 * @brief Структура, содержащая погодные параметры, реализованные с помощью битовых полей
 */
struct Weather
{
    unsigned int windRate : 7;  ///< скорость ветра (м/с), 0–127
    unsigned int humidity : 7;  ///< влажность (%), 0–127
    unsigned int pressure : 11; ///< давление (мм рт. ст), 0–2047
    signed int temperature : 7; ///< температура (°C), -64…+63
};

/*** Function Prototypes ***/

/**
 * @brief Запрашивает у пользователя данные и заполняет структуру
 *
 * @param[out] data Структура Weather для заполнения
 */
void input(Weather &data);

/**
 * @brief Выводит параметры погоды на экран
 *
 * @param[in] data Структура Weather для отображения
 */
void print(const Weather &data);

/*** Main Function ***/

int main()
{
    std::cout << "Размер структуры: " << sizeof(Weather) << "\n";

    Weather data;
    input(data);
    print(data);

    return 0;
}

/*** Function Definitions ***/

void input(Weather &data)
{
    int temp = 0;

    std::cout << "Введите скорость ветра (м/с): ";
    std::cin >> temp;
    data.windRate = temp;

    std::cout << "Введите влажность воздуха (%): ";
    std::cin >> temp;
    data.humidity = temp;

    std::cout << "Введите атмосферное давление (мм рт. ст): ";
    std::cin >> temp;
    data.pressure = temp;

    std::cout << "Введите температуру воздуха (°C): ";
    std::cin >> temp;
    data.temperature = temp;
}

void print(const Weather &data)
{
    std::cout << "Скорость ветра: " << data.windRate << " м/с\n";
    std::cout << "Влажность воздуха: " << data.humidity << " %\n";
    std::cout << "Атмосферное давление: " << data.pressure << " мм рт. ст\n";
    std::cout << "Температура воздуха: " << data.temperature << " °C\n";
}
