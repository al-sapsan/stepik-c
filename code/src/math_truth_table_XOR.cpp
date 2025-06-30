/**
 * @file truth_table.c
 * @brief Программа для построения таблицы истинности логической формулы F(A,B,C) = (A ⊕ B) → C
 */

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Вычисление операции XOR (исключающее ИЛИ)
 * @param a Первый логический операнд
 * @param b Второй логический операнд
 * @return Результат операции a XOR b
 * @retval true Если операнды разные
 * @retval false Если операнды одинаковые
 */
bool xor (bool a, bool b) {
    return a != b;
}

    /**
     * @brief Вычисление логической импликации (→)
     * @param p Логическое условие (антецедент)
     * @param q Логическое следствие
     * @return Результат импликации p → q
     * @retval false Только когда p=true и q=false
     * @retval true Во всех остальных случаях
     */
    bool implies(bool p, bool q)
{
    return !p || q;
}

/**
 * @brief Основная функция программы
 * @return Код завершения программы
 * @retval 0 Программа завершилась успешно
 */
int main()
{
    // Вывод заголовка таблицы
    printf("Таблица истинности для формулы F(A,B,C) = (A ⊕ B) → C\n");
    printf("A B C | A⊕B | (A⊕B)→C | F\n");
    printf("----------------------------\n");

    // Перебор всех возможных комбинаций входных значений
    for (int a = 0; a <= 1; a++)
    {
        for (int b = 0; b <= 1; b++)
        {
            for (int c = 0; c <= 1; c++)
            {
                bool a_xor_b = xor(a, b);     // Вычисление A ⊕ B
                bool f = implies(a_xor_b, c); // Вычисление (A ⊕ B) → C

                // Вывод строки таблицы истинности
                printf("%d %d %d |  %d  |    %d    | %d\n",
                       a, b, c, a_xor_b, f, f);
            }
        }
    }

    // Вывод комбинаций, где F=1 в требуемом формате
    printf("\nКомбинации, где F=1: ");
    printf("000");  // A=0,B=0,C=0 → F=1
    printf(",001"); // A=0,B=0,C=1 → F=1
    printf(",011"); // A=0,B=1,C=1 → F=1
    printf(",101"); // A=1,B=0,C=1 → F=1
    printf(",110"); // A=1,B=1,C=0 → F=1
    printf(",111"); // A=1,B=1,C=1 → F=1
    printf("\n");

    return 0;
}