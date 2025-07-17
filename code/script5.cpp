#include <iostream>
using namespace std;
struct Weather
{
    unsigned int windRate : 7;
    unsigned int humidity : 7;
    unsigned int pressure : 11;
    signed int temperature : 7;
};
int main()
{
    cout << "Размер структуры: " << sizeof(Weather) << endl;
    Weather data;
    input(data);
    print(data);
    return 0;
}

void input(Weather &a)
{
    int temp;
    cout << "Введите скорость ветра (м/с): ";
    cin >> temp;
    a.windRate = temp;
    cout << "Введите влажность воздуха  (%): ";
    cin >> temp;
    a.humidity = temp;
    cout << "Введите атмосферное давление (мм рт. столба): ";
    cin >> temp;
    a.pressure = temp;
    cout << "Введите температуру воздуха (С): ";
    cin >> temp;
    a.temperature = temp;
}
void print(Weather a)
{
    cout << "Скорость ветра: " << a.windRate << " м/с\n";
    cout << "Влажность воздуха " << a.humidity << "%\n";
    cout << "Атмосферное давление: " << a.pressure << " мм. рт. ст\n";
    cout << "Температура воздуха: " << a.temperature << " С\n";
}