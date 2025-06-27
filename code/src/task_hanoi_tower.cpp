#include <iostream>
using namespace std;

/**
 * @brief Функция для перемещения дисков Ханойской башни
 * @param n Количество дисков
 * @param from Исходный стержень
 * @param to Целевой стержень
 * @param temp Промежуточный стержень
 * @return Количество перемещений
 */
int tower(int n, int from, int to, int temp)
{
    if (n == 0)
    {
        return 0;
    }

    // Перемещаем n-1 диск на временный стержень
    int count = tower(n - 1, from, temp, to);

    // Перемещаем самый большой диск на целевой стержень
    cout << from << "->" << to << endl;
    count++;

    // Перемещаем n-1 диск с временного на целевой стержень
    count += tower(n - 1, temp, to, from);

    return count;
}

int main()
{
    int kolDisk;
    cin >> kolDisk;
    int kol = tower(kolDisk, 1, 3, 2); // Перемещаем с 1 на 3 стержень через 2
    cout << "Количество действий: " << kol << endl;
    return 0;
}