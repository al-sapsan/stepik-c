#include <stdio.h>
 
int main(void)
{
    int x = 8;
 // Если условие верно, то выводим "even", иначе "odd"
    printf("x is %s digit\n", (x % 2 == 0) ? "even" : "odd");
 // Вложенная тернарная операция
    printf("x is %s digit\n", (x > 0) ? ((x % 2 == 0) ? "even" : "odd") : "negative");

    return 0;
}