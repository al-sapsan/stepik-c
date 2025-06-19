#include <iostream>
using namespace std;

/**
 * @brief Sorts three integers in ascending order.
 * 
 * This function takes three integer references and arranges
 * them such that x <= y <= z.
 * 
 * @param x Reference to the first integer
 * @param y Reference to the second integer
 * @param z Reference to the third integer
 */
void sort(int &x, int &y, int &z)
{
    int tmp;
    if (x > y)
    {
        tmp = x;
        x = y;
        y = tmp;
    }
    if (y > z)
    {
        tmp = y;
        y = z;
        z = tmp;
    }
    if (x > y)
    {
        tmp = x;
        x = y;
        y = tmp;
    }
}

/**
 * @brief Entry point of the program.
 * 
 * Prompts the user to input three integers, sorts them using the `sort` function,
 * and displays the result in ascending order.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main()
{
    setlocale(LC_ALL, "rus");
    int a, b, c;

    cout << "Введите три целых числа: ";
    cin >> a >> b >> c;

    sort(a, b, c);

    cout << "Числа после упорядочивания: ";
    cout << a << " " << b << " " << c << endl;

    system("pause");
    return 0;
}
