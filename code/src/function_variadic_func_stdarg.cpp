#include <iostream>
#include <stdarg.h>
using namespace std;

int sum(int, ...); // прототип

int main()
{
    // последний ноль в списке параметров - признак конца
    cout << "Сумма трех чисел= " << sum(1, 2, 3, 0) << "\n";
    cout << "Сумма пяти чисел равна= " << sum(1, 2, 3, 4, 5, 0) << "\n";
    system("pause");
    return 0;
}

int sum(int a, ...)
{
    int sum = 0;
    va_list p;      // объявляем указатель нa параметр
    va_start(p, a); // устанавливаем этот указатель после явного параметра a
    while (a)
    { // пока очередной параметр не равен 0
        sum += a;
        a = va_arg(p, int); // считываем параметр и переходим к следующему
    }
    va_end(p);
    return sum;
}