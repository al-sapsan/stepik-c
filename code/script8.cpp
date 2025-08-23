/**********************************************************************
 * @file script8.cpp
 * @brief Replace is_verify with lambda (embedded C++ style)
 * @version 1.0 (Stepik exercise)
 * @date 2025-08-23
 **********************************************************************/

#include <iostream>

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 * @return Код завершения (0 — успешно, 1 — ошибка памяти)
 */
int main(void)
{
    enum
    {
        size_pole = 10
    };
    char arr_pg_u8[size_pole][size_pole] = {0};

    /**
     * @brief Лямбда-выражение для проверки клетки
     * @param x Индекс строки
     * @param y Индекс столбца
     * @return 1 — клетка свободна, 0 — есть мина рядом
     */
    auto is_v = [&arr_pg_u8](int x, int y) -> int
    {
        for (int i = -1; i <= 1; ++i)
            for (int j = -1; j <= 1; ++j)
            {
                int xx = x + i, yy = y + j;
                if (xx < 0 || xx >= size_pole || yy < 0 || yy >= size_pole)
                    continue;
                if (arr_pg_u8[xx][yy] == '*')
                    return 0;
            }
        return 1;
    };

    int mines = 0;
    do
    {
        int i = rand() % size_pole;
        int j = rand() % size_pole;
        if (is_v(i, j))
        {
            arr_pg_u8[i][j] = '*';
            mines++;
        }
    } while (mines < 12);

    /*
    //----------- вывод поля в консоль ---------------------------------
    for(int i = 0; i < size_pole; ++i) {
        for(int j = 0; j < size_pole; ++j)
            printf("%c ", (arr_pg_u8[i][j] == 0) ? '#' : '*');
        putchar('\n');
    }
    //----------- завершение вывода поля в консоль ----------------------
    */

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}
