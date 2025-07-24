/*******************************************************************************
 * @file    script8.c
 * @brief   Разложение числа на простые множители
 * @version 1.0
 * @date    2025-07-24
 ******************************************************************************/

/*** Main Function ***/
int main(void)
{
    unsigned int n = 0;
    scanf("%u", &n);
    unsigned int first = 1;
    for (unsigned int d = 2; d <= n; ++d)
    {
        while (n % d == 0)
        {
            if (!first)
                printf(" ");
            printf("%u", d);
            n /= d;
            first = 0;
        }
    }
    printf("\n");
    return 0;
}
