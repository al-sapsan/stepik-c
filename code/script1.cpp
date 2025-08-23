/**********************************************************************
 * @file script1.cpp
 * @brief Array of lambda filters (embedded C++ style)
 * @version 1.2
 * @date 2025-08-22
 **********************************************************************/

#include <iostream>

/*** Function Prototypes ***/
/**
 * @brief  Массив лямбда-фильтров для проверки целых чисел
 *
 * Первый фильтр: возвращает 1, если число четное, иначе 0
 * Второй фильтр: возвращает 1, если число отрицательное, иначе 0
 * Третий фильтр: возвращает 1, если число положительное (>0), иначе 0
 *
 * @param v Проверяемое целое число
 * @return 1 — условие выполнено, 0 — не выполнено
 */

// ...lambda array defined in main...

/*** Main Function ***/
int main(void)
{
    auto func_filter = {
        [](int v)
        { return v % 2 == 0 ? 1 : 0; },
        [](int v)
        { return v < 0 ? 1 : 0; },
        [](int v)
        { return v > 0 ? 1 : 0; }};

    int value = 0;
    std::cin >> value;
    auto it = func_filter.begin();
    ++it; // second lambda
    std::cout << (*it)(value) << std::endl;

    __ASSERT_TESTS__
    return 0;
}
