/****************************************************************************
 * @file reverse_array.cpp
 * @brief Программа для переворота массива целых чисел
 * @version 1.0
 * @date 2025-08-22
 ****************************************************************************/

#include <iostream>

// *** Constants ***
enum
{
    max_size = 20
};

// *** Function Prototypes ***
/**
 * @brief Функция для переворота массива
 * @param[in,out] arr Указатель на массив для переворота
 * @param[in] n Количество элементов в массиве
 */
void reverse(short *arr, size_t n);

// *** Main Function ***
int main(void)
{
    // Объявление массива и счетчика
    short digs[max_size];
    int count = 0;

    // Ввод данных
    while (count < max_size && std::cin >> digs[count])
    {
        count++;
    }

    // Вызов функции переворота массива
    reverse(digs, static_cast<size_t>(count));

    // Вывод результата
    for (int i = 0; i < count; i++)
    {
        std::cout << digs[i];

        if (i < count - 1)
        {
            std::cout << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}

// *** Function Implementations ***
void reverse(short *arr, size_t n)
{
    // Используем два указателя: один с начала, другой с конца
    size_t i = 0;
    size_t j = n - 1;

    // Меняем элементы местами пока указатели не встретятся
    while (i < j)
    {
        // Обмен значений
        short temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        // Двигаем указатели навстречу друг другу
        i++;
        j--;
    }
}
