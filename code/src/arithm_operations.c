#include <stdio.h>
 
int main(void)
{
    short a = -5;
    int b = 10;
    float c = 5.4f;
    double d = -6.5;
 
    int res_1 = a + b; // повышение типа переменной a
    short res_2 = 100 - b; // понижение типа переменной b
    float res_3 = 5.4 - c;
    double res_4 = d * 4;
 
    return 0;
}