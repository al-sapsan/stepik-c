#include <stdio.h>

int main(void)
{
 /* чтение символьной информации */
    char byte1 = '0', byte2 = '0';

    int res = scanf("%c,%c", &byte1, &byte2); // считываем два последовательных символа
    int res = scanf("%c %c", &byte1, &byte2); // считываем два символа с пробелом (перевод строки, табуляция) между ними
    int res = scanf("%c, %c", &byte1, &byte2); // считываем два символа с запятой и пробельным элементом между ними
    printf("res = %d: byte1 = %c, byte2 = %c\n", res, byte1, byte2); // выводим количество считанных символов и сам символ

/* чтение числовой информации 
важно, чтобы модификаторы строго сочитались с типом переменных,
так как они отличаются от аналогичных в функции print() */
    long long var_lli = 0;
    double var_d = 0.0;
    unsigned int price = 0;
    double weight = 0.0;

    int res = scanf("%lld %lf", &var_lli, &var_d); // считываем два числа long long и double
    printf("res = %d: var = %lld, var_d = %.2f\n", res, var_lli, var_d); // выводим количество считанных символов  
    // и сами числа
    int res = scanf("%*llu; %u; %lf", &price, &weight); // считываем два числа unsigned long long и double, 
    // игнорируя первое число с помощью символа * (звёздочка)
     printf("res = %d: price = %d, weight = %.2f\n", res, price, weight); // выводим количество считанных символов  
    // и сами числа
    return 0;
}