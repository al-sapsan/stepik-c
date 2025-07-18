#include <iostream>
using namespace std;
struct Student
{
    char *surname;
    char *name;
    int age;
};
void readStudent(Student &item)
{
    const int MAXLEN = 300;
    char buffer[MAXLEN];
    fgets(buffer, MAXLEN, stdin);
    char *word = strtok(buffer, ";\n");
    item.surname = new char[strlen(word) + 1];
    strcpy(item.surname, word);
    word = strtok(NULL, ";\n");
    item.name = new char[strlen(word) + 1];
    strcpy(item.name, word);
    word = strtok(NULL, ";\n");
    item.age = atoi(word);
}
void printList(Student *spisok, int n)
{
    cout << "\nСписок студентов:\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " " << spisok[i].surname << " " << spisok[i].name << " ";
        cout << spisok[i].age << endl;
    }
}
int menu()
{
    int choice;
    do
    {
        cout << "\n1 - добавление студента\n";
        cout << "2 - удаление студента\n";
        cout << "3 - печать списка студентов\n";
        cout << "4 - завершение работы программмы\n";
        cout << "Ваш выбор: ";
        cin >> choice;
        if (choice < 1 || choice > 4)
        {
            cout << "Неверный выбор! Повторите ввод!\n";
        }
    } while (choice < 1 || choice > 4);
    return choice;
}
void insertStudent(Student *&spisok, int &n)
{
    cout << "Введите данные нового студента: ";
    Student item;
    while (cin.get() != '\n')
        ;
    readStudent(item);
    Student *nspisok = new Student[n + 1];
    for (int i = 0; i < n; i++)
    {
        nspisok[i] = spisok[i];
    }
    nspisok[n] = item;
    delete[] spisok;
    spisok = nspisok;
    n++;
}
void deleteStudent(Student *&spisok, int &n)
{
    cout << "Введите номер студента, которого нужно удалить: ";
    int k;
    cin >> k;
    if (k < 1 || k > n)
        return;
    Student *nspisok = new Student[n - 1];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == k - 1)
            continue;
        nspisok[j++] = spisok[i];
    }
    delete[] spisok[k - 1].surname;
    delete[] spisok[k - 1].name;
    delete[] spisok;
    spisok = nspisok;
    n--;
}
void destroy(Student *spisok, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] spisok[i].surname;
        delete[] spisok[i].name;
    }
    delete[] spisok;
}
int main()
{
    int n; // текущее количество студентов
    cin >> n;
    while (cin.get() != '\n')
        ;
    Student *spisok = new Student[n];
    for (int i = 0; i < n; i++)
    {
        readStudent(spisok[i]);
    }
    printList(spisok, n);
    while (true)
    {
        int choice = menu();
        switch (choice)
        {
        case 1:
            insertStudent(spisok, n);
            break;
        case 2:
            deleteStudent(spisok, n);
            break;
        case 3:
            printList(spisok, n);
            break;
        case 4:
            cout << "Завершаем...\n";
            destroy(spisok, n);
            return 0;
        }
    }
}