/************************************************************************
 * @file script4.cpp
 * @brief Шаблонная функция ar_sum с фильтрующей функцией
 * @version 1.0
 * @date 2025-10-16
 ************************************************************************/

#include <iostream>

/**
 * @brief Суммирует элементы массива, удовлетворяющие фильтрующей функции
 * @tparam T Тип элементов массива
 * @param arr Массив элементов
 * @param len Длина массива
 * @param filter Указатель на фильтрующую функцию (bool(T))
 * @return Сумма элементов, для которых filter возвращает true
 */
template <typename T>
T ar_sum(const T *arr, size_t len, bool (*filter)(T))
{
    T sum{};
    for (size_t i = 0; i < len; ++i)
    {
        if (filter(arr[i]))
            sum += arr[i];
    }
    return sum;
}

int main()
{
    double data[] = {-1, 2.5, -3, -4, 5.1, 6};
    auto positive = [](double x)
    { return x > 0; };
    // Лямбда не может быть передана напрямую как указатель на функцию, поэтому используем явную функцию-обертку
    struct PosWrap
    {
        static bool fn(double x) { return x > 0; }
    };
    double res = ar_sum<double>(data, sizeof(data) / sizeof(data[0]), PosWrap::fn);

    (void)res;

    __ASSERT_TESTS__ // макроопределение для тестирования
        return 0;
}