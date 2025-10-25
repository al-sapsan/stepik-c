#include <stdio.h>
#include <stdbool.h>
 
int main(void)
{
    int digit;
    scanf("%d", &digit);
 
    bool even = digit % 2 == 0;
    
    // После запуска и ввода целого значения мы увидим 0 – для нечетных чисел и 1 – для четных.
    printf("%d\n", even);
    
    return 0;
}