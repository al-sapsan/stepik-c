#include <iostream>
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

int sum(int a_n, ...)
{
    int i_sum = 0;
    int *p_arg = &a_n; // берем адрес первого аргумента
    while (*p_arg != 0)
    { // пока значение по адресу p не равно 0
        i_sum += *p_arg;
        p_arg++; // переходим к следующему аргументу
    }
    return i_sum;
}