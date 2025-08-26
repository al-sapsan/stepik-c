/**********************************************************************
 * @file script2.cpp
 * @brief Структура book с методом price_per_page (embedded C++ style)
 * @version 1.0 (Stepik exercise)
 * @date 2025-08-26
 **********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

/**
 * @brief Структура книги с методом вычисления цены за страницу
 */
struct book
{
    std::string title;
    std::string author;
    int price;
    int npages;
    /**
     * @brief Вычисляет цену за одну страницу
     * @return Цена за страницу (вещественное число)
     */
    double price_per_page(void) const
    {
        return npages ? static_cast<double>(price) / npages : 0.0;
    }
};

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 * @return Код завершения (0 — успешно, 1 — ошибка памяти)
 */
int main(void)
{
    book arr_lib[10];
    int n = 0;
    while (n < 10 && std::getline(std::cin, arr_lib[n].title))
    {
        if (arr_lib[n].title.empty())
            break;
        std::getline(std::cin, arr_lib[n].author);
        std::cin >> arr_lib[n].price >> arr_lib[n].npages;
        std::cin.ignore();
        ++n;
    }
    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < n; ++i)
        std::cout << arr_lib[i].price_per_page() << (i < n - 1 ? " " : "");
    std::cout << std::endl;
    __ASSERT_TESTS__
    return 0;
}
