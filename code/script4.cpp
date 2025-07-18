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
        cout << "4 - печать отсортированого списка студентов\n";
        cout << "5 - завершение работы программмы\n";
        cout << "Ваш выбор: ";
        cin >> choice;
        if (choice < 1 || choice > 5)
        {
            cout << "Неверный выбор! Повторите ввод!\n";
        }
    } while (choice < 1 || choice > 5);
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
// функция сравнивает студентов, на которые указывают one и two
// по полю структуры, которое задает type
int studentCmp(Student *one, Student *two, int type)
{
    if (type == 1)
    {
        if (strcmp(one->surname, two->surname) == 0)
        {
            return strcmp(one->name, two->name);
        }
        return strcmp(one->surname, two->surname);
    }
    if (type == 2)
    {
        return one->age - two->age;
    }
    return 0; // если ошибочный тип, то возвращается 0 и список сортироваться не будет
}
// функция выводит упорядоченный список студентов
void printSort(Student *spisok, int n)
{
    int type;
    cout << "1 - сортировка по фамилии и имени\n";
    cout << "2 - сортировка по возрасту\n";
    cout << "Ваш выбор: ";
    cin >> type;
    // создаем и заполняем массив указателей
    Student **ptrs = new Student *[n];
    for (int i = 0; i < n; i++)
    {
        ptrs[i] = spisok + i;
    }
    // сортировка методом пузырька
    for (int k = n - 1; k > 0; k--)
    {
        for (int i = 0; i < k; i++)
        {
            if (studentCmp(ptrs[i], ptrs[i + 1], type) > 0)
            {
                Student *tmp = ptrs[i];
                ptrs[i] = ptrs[i + 1];
                ptrs[i + 1] = tmp;
            }
        }
    }
    cout << "Отсортированный список студентов:\n";
    for (int i = 0; i < n; i++)
    {
        cout << ptrs[i]->surname << " " << ptrs[i]->name << " " << ptrs[i]->age << endl;
    }

    delete[] ptrs; // удаление массива указателей
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
            printSort(spisok, n);
            break;
        case 5:
            cout << "Завершаем...\n";
            destroy(spisok, n);
            return 0;
        }
    }
}