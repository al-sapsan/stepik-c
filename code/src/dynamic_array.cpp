#include <iostream>
#include <cstdlib>
#include <stdint.h>
using namespace std;

/** Определения типов данных */
typedef int32_t i32_t;
typedef uint32_t u32_t;

/**
 * @brief Инициализирует массив случайными числами от -10 до 15
 * @param[out] a Указатель на массив
 * @param[in] n Размер массива
 */
void initArray(i32_t *a, u32_t n);
/**
 * @brief Выводит массив на экран через пробел
 * @param[in] a Указатель на массив
 * @param[in] n Размер массива
 */
void printArray(const i32_t *a, u32_t n);
/**
 * @brief Добавляет элемент в массив на указанную позицию
 * @param[in,out] a Ссылка на указатель массива
 * @param[in,out] n Ссылка на размер массива
 */
void addElement(i32_t *&a, u32_t &n);
/**
 * @brief Удаляет элемент из массива по указанной позиции
 * @param[in,out] a Ссылка на указатель массива
 * @param[in,out] n Ссылка на размер массива
 */
void delElement(i32_t *&a, u32_t &n);

int main()
{
    u32_t n;
    i32_t beg;
    cin >> n >> beg;
    srand(static_cast<u32_t>(beg));

    i32_t *a = nullptr;
    a = new i32_t[n];

    initArray(a, n);
    printArray(a, n);

    i32_t k;
    for (;;)
    {
        cin >> k;
        switch (k)
        {
        case 1:
            addElement(a, n);
            break;
        case 2:
            delElement(a, n);
            break;
        case 3:
            printArray(a, n);
            break;
        default:
            delete[] a;
            return 0;
        }
    }
}

void initArray(i32_t *a, u32_t n)
{
    for (u32_t i = 0; i < n; i++)
    {
        a[i] = rand() % 26 - 10; // Генерация чисел от -10 до 15
    }
}

void printArray(const i32_t *a, u32_t n)
{
    for (u32_t i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void addElement(i32_t *&a, u32_t &n)
{
    i32_t pos, value;
    cin >> pos >> value;

    if (pos < 1)
        pos = 1;
    if (pos > static_cast<i32_t>(n))
        pos = n + 1;

    i32_t *newArray = new i32_t[n + 1];

    for (u32_t i = 0; i < static_cast<u32_t>(pos - 1); i++)
    {
        newArray[i] = a[i];
    }

    newArray[pos - 1] = value;

    for (u32_t i = pos; i < n + 1; i++)
    {
        newArray[i] = a[i - 1];
    }

    delete[] a;
    a = newArray;
    n++;
}

void delElement(i32_t *&a, u32_t &n)
{
    i32_t pos;
    cin >> pos;

    if (pos < 1 || pos > static_cast<i32_t>(n))
    {
        return;
    }

    i32_t *newArray = new i32_t[n - 1];

    for (u32_t i = 0; i < static_cast<u32_t>(pos - 1); i++)
    {
        newArray[i] = a[i];
    }

    for (u32_t i = pos; i < n; i++)
    {
        newArray[i - 1] = a[i];
    }

    delete[] a;
    a = newArray;
    n--;
}