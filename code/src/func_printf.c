#include <stdio.h>

#include <stdio.h>

int main(void) 
{
    short var_h = 100;
    int var_i = 1208;
    double var_d = -54.478365;
    long double var_ld = 0.5;
    printf("var_h = %d, var_i = %d, %Lf\n", var_h, var_i, var_ld); // Последовательный вывод значений переменных
    printf("[%-10d]\n", var_h); // Вывод переменной var_h с выравниванием по левому краю
    printf("[%+10d]\n", var_i); // Вывод переменной var_i с выравниванием по правому краю и знаком 
    printf("[%10.2f]\n", var_d); // Вывод переменной var_d с 2 знаками после запятой
    printf("[%.2Lf]\n", var_ld); // Вывод переменной var_ld с 2 знаками после запятой
    printf("[%#x]\n", var_i); // Вывод переменной var_i в шестнадцатеричном формате
    printf("[%+.2f]\n", var_d); // Вывод переменной var_d с 2 знаками после запятой и знаком 
    return 0;
}