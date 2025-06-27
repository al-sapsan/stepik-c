#include <iostream>
using namespace std;

/**
 * @brief Вычисляет наибольший общий делитель (НОД) двух чисел рекурсивно
 * @param a Первое число
 * @param b Второе число
 * @return Наибольший общий делитель
 * @details Используется алгоритм Евклида:
 * - Если числа равны, возвращается это число
 * - Если a > b, рекурсивно вызывается nod(a - b, b)
 * - Если a < b, рекурсивно вызывается nod(a, b - a)
 */
int nod(int a, int b)
{
    // Базовый случай: если числа равны
    if (a == b)
    {
        return a;
    }
    // Если первое число больше
    if (a > b)
    {
        return nod(a - b, b);
    }
    // Если второе число больше
    return nod(a, b - a);
}
/** Для большей эффективности можно использовать
 * вариант с делением по модулю:
 *
 * int nod(int a, int b) {
    if (b == 0) {
        return a;
    }
    return nod(b, a % b);
}
 * */
int main()
{
    int a, b;
    cin >> a >> b;
    cout << nod(a, b);
    return 0;
}