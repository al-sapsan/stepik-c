/********************************************************************
 * @file    script2.c
 * @brief   Работа с динамической структурой tag_rub и расчетом валюты
 * @version 1.0
 * @date    2025-07-29
 ********************************************************************/

/*** Includes ***/
#include <stdio.h>
#include <stdlib.h>

/*** Typedefs ***/
typedef struct tag_rub
{
    double ratio_usd;
    int rubs;
} tag_rub;

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Выделяет память под tag_rub, вычисляет доллары и освобождает память
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    tag_rub *account_r = (tag_rub *)malloc(sizeof(tag_rub));
    if (account_r == NULL)
    {
        return 1;
    }
    account_r->ratio_usd = 91.32;
    scanf("%d", &account_r->rubs);
    double dollars = account_r->rubs / account_r->ratio_usd;
    (void)printf("%.2f\n", dollars);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать)
        free(account_r);
    return 0;
}
