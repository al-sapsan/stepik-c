#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/**
 * @brief Функция 1: вычисляет y = x^4 - 2
 * @param x Значение аргумента
 * @return Значение функции y
 */
double func1(double x)
{
    return pow(x, 4) - 2;
}

/**
 * @brief Функция 2: вычисляет y = 2x + 4
 * @param x Значение аргумента
 * @return Значение функции y
 */
double func2(double x)
{
    return 2 * x + 4;
}

/**
 * @brief Табулирует переданную функцию на отрезке [start, end] в 10 точках
 *
 * @param func Указатель на функцию, которую нужно табулировать
 * @param start Начальное значение x
 * @param end Конечное значение x
 */
void tabulate(double (*func)(double), double start, double end)
{
    // Шапка таблицы
    cout << "---------------------" << endl;
    cout << "|    x    |    y    |" << endl;
    cout << "---------------------" << endl;

    // Вычисляем шаг
    double step = (end - start) / 9;

    // Выводим 10 значений
    for (int i = 0; i < 10; i++)
    {
        double x = start + i * step;
        double y = func(x);

        // Форматируем вывод с двумя знаками после запятой
        cout << "|" << fixed << setprecision(2) << setw(7) << x << "  |";
        cout << fixed << setprecision(2) << setw(7) << y << "  |" << endl;
    }

    // Нижняя граница таблицы
    cout << "---------------------" << endl;
}

/**
 * @brief Точка входа в программу. Считывает выбор функции и границы, выводит таблицу значений.
 *
 * @return int Код завершения программы
 */
int main()
{
    int choice;
    double start, end;

    // Ввод данных
    cin >> choice >> start >> end;

    // Проверка корректности ввода
    if ((choice != 1 && choice != 2) || end < start)
    {
        cout << "ERROR" << endl;
        return 0;
    }

    // Выбор функции и вывод таблицы
    if (choice == 1)
    {
        tabulate(func1, start, end);
    }
    else
    {
        tabulate(func2, start, end);
    }

    return 0;
}