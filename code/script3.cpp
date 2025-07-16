#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    char symbol;

    // Ввод строки и символа
    getline(cin, input);
    cin >> symbol;

    // Удаление всех вхождений символа
    size_t pos = 0;
    while ((pos = input.find(symbol, pos)) != string::npos)
    {
        input.erase(pos, 1);
    }

    // Вывод результата
    cout << input << endl;

    return 0;
}