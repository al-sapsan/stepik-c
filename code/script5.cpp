/************************************************************************
 * @file script5.cpp
 * @brief Шаблонная функция ar_sort с пользовательской функцией сравнения
 * @version 1.0
 * @date 2025-10-16
 ************************************************************************/

#include <iostream>
#include <cstddef>
#include <cstdlib>

/**
 * @brief Сортирует массив по возрастанию с помощью пользовательской функции сравнения
 * @tparam T Тип элементов массива
 * @param arr Массив элементов
 * @param len Длина массива
 * @param cmp Указатель на функцию сравнения (bool(T, T))
 */
template <typename T>
void ar_sort(T *arr, size_t len, bool (*cmp)(T, T))
{
    // Сортировка пузырьком (bubble sort)
    for (size_t i = 0; i < len; ++i)
    {
        for (size_t j = 1; j < len - i; ++j)
        {
            if (cmp(arr[j], arr[j - 1]))
            {
                T tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main()
{
    int data[] = {5, -3, 10, 0, 33, 7, -12};
    // Лямбда для сравнения по модулю
    auto abs_less = [](int a, int b)
    { return std::abs(a) < std::abs(b); };
    // Обертка для передачи лямбды как указателя на функцию
    struct AbsLessWrap
    {
        static bool fn(int a, int b) { return std::abs(a) < std::abs(b); }
    };
    ar_sort<int>(data, sizeof(data) / sizeof(data[0]), AbsLessWrap::fn);

    __ASSERT_TESTS__ // макроопределение для тестирования
        return 0;
}