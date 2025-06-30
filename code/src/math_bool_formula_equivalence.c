/**
 * @file formula_equivalence.c
 * @brief Программа для проверки эквивалентности двух булевых формул
 */

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Вычисление старой формулы F_old = (¬A ∧ B ∧ C) ∨ (A ∧ ¬B ∧ C) ∨ (A ∧ B ∧ C)
 * @param a Значение переменной A (true/false)
 * @param b Значение переменной B (true/false)
 * @param c Значение переменной C (true/false)
 * @return Результат вычисления формулы F_old
 */
bool calculate_old_formula(bool a, bool b, bool c)
{
    return (!a && b && c) || (a && !b && c) || (a && b && c);
}

/**
 * @brief Вычисление новой формулы F_new = C ∧ (A ∨ B)
 * @param a Значение переменной A (true/false)
 * @param b Значение переменной B (true/false)
 * @param c Значение переменной C (true/false)
 * @return Результат вычисления формулы F_new
 */
bool calculate_new_formula(bool a, bool b, bool c)
{
    return c && (a || b);
}

/**
 * @brief Проверка эквивалентности двух формул на всех комбинациях входных значений
 * @return true если формулы эквивалентны, false в противном случае
 */
bool test_formula_equivalence()
{
    bool equivalent = true;

    printf("A\tB\tC\tF_old\tF_new\tResult\n");
    printf("----------------------------------------\n");

    for (int a = 0; a <= 1; a++)
    {
        for (int b = 0; b <= 1; b++)
        {
            for (int c = 0; c <= 1; c++)
            {
                bool old_result = calculate_old_formula(a, b, c);
                bool new_result = calculate_new_formula(a, b, c);
                bool match = (old_result == new_result);

                printf("%d\t%d\t%d\t%d\t%d\t%s\n",
                       a, b, c,
                       old_result, new_result,
                       match ? "OK" : "MISMATCH");

                if (!match)
                {
                    equivalent = false;
                }
            }
        }
    }

    return equivalent;
}

/**
 * @brief Главная функция программы
 * @return 0 в случае успешного выполнения
 */
int main()
{
    bool is_equivalent = test_formula_equivalence();

    printf("\nFormulas are %sequivalent\n",
           is_equivalent ? "" : "NOT ");

    return 0;
}