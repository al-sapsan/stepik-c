/**********************************************************************
 * @file script2.cpp
 * @brief Array of lambda pointers (embedded C++ style)
 * @version 1.1
 * @date 2025-08-22
 **********************************************************************/

#include <iostream>

/*** Function Prototypes ***/
/**
 * @brief  Массив указателей на лямбда-функции для проверки целых чисел
 *
 * Первый фильтр: возвращает 1, если число четное, иначе 0
 * Второй фильтр: возвращает 1, если число отрицательное, иначе 0
 * Третий фильтр: возвращает 1, если число положительное (>0), иначе 0
 *
 * @param v Проверяемое целое число
 * @return 1 — условие выполнено, 0 — не выполнено
 */
// ...lambda pointer array defined in main...

/*** Main Function ***/
int main(void)
{
    int (*func_filter[3])(int) = {
        [](int v) -> int
        { return v % 2 == 0 ? 1 : 0; },
        [](int v) -> int
        { return v < 0 ? 1 : 0; },
        [](int v) -> int
        { return v > 0 ? 1 : 0; }};

    int value = 0;
    std::cin >> value;
    std::cout << func_filter[1](value) << std::endl;

    return 0;
}
