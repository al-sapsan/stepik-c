#include <stdio.h>
#include <stdbool.h> // Для типа bool (C99 и выше)

int main()
{
    // Перебираем все возможные комбинации A, B, C (0 и 1)
    printf("A | B | C | (A ∨ B) | F = (A ∨ B) ∧ C\n");
    printf("-------------------------------------\n");

    for (int a = 0; a <= 1; a++)
    {
        for (int b = 0; b <= 1; b++)
        {
            for (int c = 0; c <= 1; c++)
            {
                // Вычисляем (A ∨ B) и затем F = (A ∨ B) ∧ C
                bool a_or_b = a || b;
                bool f = a_or_b && c;

                // Выводим строку таблицы
                printf("%d | %d | %d |    %d     |        %d\n", a, b, c, a_or_b, f);
            }
        }
    }

    return 0;
}