#include <iostream>
using namespace std;

typedef struct
{
    int data;
    Node *next;
} Node;

void push(int data, Node *&top)
{                          // добавление данных в стек
    Node *knot = new Node; // выделение памяти под новый узел
    knot->data = data;     // записываем данные в этот узел
    knot->next = top;      // устанавливаем связь со стеком
    top = knot;            // вершина теперь в новом узле
}

int pop(Node *&top)
{ // извлечение данных из стека
    if (top == NULL)
        return 0;        // если стек пуст возвращаем не существующий элемент
    int tmp = top->data; // копируем данные из вершины во вспомогательную переменную
    Node *knot = top;    // вспомогательный указатель - на вершину
    top = top->next;     // вершину перемещаем на следующий узел
    delete knot;         // очищаем память из-под удаляемого узла
    return tmp;          // возвращаем данные
}

int peek(Node *top)
{
    if (top == NULL)
        return 0;
    return top->data; // читаем данные из вершины, не удаляя
}
void print(Node *top)
{
    if (top == NULL)
    {
        cout << "Стек пуст\n";
        return;
    }
    cout << "Содержимое стека от вершины: ";
    while (top)
    {                             // пока не дойдем до дна стека
        cout << top->data << " "; // вывод данных
        top = top->next;          // переход к следующему узлу
    }
    cout << endl;
}

void clear(Node *&top)
{
    while (top)
    { // пока не дорйдем до дна стека
        Node *knot = top;
        top = top->next; // переходим к следующему узлу
        delete knot;     // удаляем очередной узел
    }
}

int menu()
{
    int choice = 0;
    do
    {
        cout << "\n1 - Добавление в стек\n";
        cout << "2 - Удаление из стека\n";
        cout << "3 - Чтение вершины стека\n";
        cout << "4 - Печать стека\n";
        cout << "5 - Очистка стека\n";
        cout << "6 - Завершение работы\n";
        cout << "Ваш выбор: ";
        cin >> choice;
        if (choice < 1 || choice > 6)
        {
            cout << "Неверный выбор! Повторите ввод!\n";
        }
    } while (choice < 1 || choice > 6);
    return choice;
}

int main()
{
    Node *top = NULL;
    int data;
    for (;;)
    {
        int k = menu();
        switch (k)
        {
        case 1:
            cout << "Введите число: ";
            cin >> data;
            push(data, top);
            break;
        case 2:
            cout << "Извлечено из стека: " << pop(top) << endl;
            break;
        case 3:
            cout << "Прочитано из вершины: " << peek(top) << endl;
            break;
        case 4:
            print(top);
            break;
        case 5:
            clear(top);
            break;
        case 6:
            cout << "Завершение работы...";
            clear(top);
            return 0;
        }
    }
}