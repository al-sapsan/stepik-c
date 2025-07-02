/**
 * @file integral.cpp
 * @brief Программа для численного вычисления определенного интеграла методом прямоугольников
 */

#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

/**
 * @brief Вычисляет определенный интеграл методом левых прямоугольников
 * @param a Нижний предел интегрирования
 * @param b Верхний предел интегрирования
 * @param n Количество интервалов разбиения
 * @param pf Указатель на подынтегральную функцию
 * @return Приближенное значение интеграла
 * @note Точность повышается с увеличением n
 */
double integral(double a, double b, int n, double (*pf)(double))
{
    if (n <= 0)
        return 0; // Защита от неверного ввода

    double s = 0, h = (b - a) / n; // h - ширина интервала
    for (double x = a; x < b + h; x += h)
    {
        s += pf(x) * h;
    }
    return s;
}

/**
 * @brief Функция для безопасного ввода числа типа double
 * @param prompt Приглашение для ввода
 * @return Введенное пользователем число
 */
double inputDouble(const string &prompt)
{
    double value;
    while (true)
    {
        cout << prompt;
        cin >> value;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите число.\n";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

/**
 * @brief Функция для безопасного ввода целого числа
 * @param prompt Приглашение для ввода
 * @return Введенное пользователем целое число
 */
int inputInt(const string &prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        cin >> value;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите целое число.\n";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

/**
 * @brief Главная функция программы
 * @return Код завершения программы
 */
int main()
{
    setlocale(LC_ALL, "rus");

    // Ввод параметров с клавиатуры
    double a = inputDouble("Введите нижний предел интегрирования (a): ");
    double b = inputDouble("Введите верхний предел интегрирования (b): ");
    int n = inputInt("Введите количество интервалов разбиения (n): ");

    // Выбор функции
    cout << "\nВыберите подынтегральную функцию:\n";
    cout << "1. sin(x)\n";
    cout << "2. cos(x)\n";
    cout << "3. exp(x)\n";
    cout << "4. x^2\n";
    cout << "Ваш выбор: ";

    int choice;
    cin >> choice;

    double (*function)(double);
    string funcName;

    switch (choice)
    {
    case 1:
        function = sin;
        funcName = "sin(x)";
        break;
    case 2:
        function = cos;
        funcName = "cos(x)";
        break;
    case 3:
        function = exp;
        funcName = "exp(x)";
        break;
    case 4:
        function = [](double x)
        { return x * x; };
        funcName = "x^2";
        break;
    default:
        cout << "Неверный выбор. Используется sin(x) по умолчанию.\n";
        function = sin;
        funcName = "sin(x)";
    }

    // Вычисление и вывод результата
    double result = integral(a, b, n, function);
    cout << "\nРезультат интегрирования " << funcName << " от " << a << " до " << b
         << " = " << result << endl;

    return 0;
}