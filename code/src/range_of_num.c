#include <stdio.h>
#include <stdbool.h>
 
int main(void)
{
    double y = 1.86;
    // логическое "и" && - true (единица), если "y" принадлежит [-2; 5] и false (ноль) если нет
    bool is_range = y >= -2 && y <= 5; 
    // логическое "или" || - true (единица), если "y" не принадлежит [-2; 5] и false (ноль) если да
    bool is_not_range = y < -2 || y > 5;
    // логическое "не" - аналогично "или" и обратное "и"
    bool is_not_range = !is_range; 
    // проверка (защита) от "деления на ноль"
    bool fl_digit = y != 0 && 10 / y > 1;

    printf("%d\n", is_range); 
 
    return 0;
}