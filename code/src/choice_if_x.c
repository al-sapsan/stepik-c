#include <stdio.h>
 
int main(void)
{
    int x;
    scanf("%d", &x);
 
    // Проверка на корректность ввода числа
    // Если ввод не является целым числом, то scanf вернет 0
    if(scanf("%d", &x) != 1) {
        printf("Error input");
        return 0;
    }
    // Проверка на принадлежность к диапазону [3; 11]
    if(x >= 3 && x <= 11) 
    printf("x in [3; 11]\n");

    // Проверка на положительные и отрицательные числа
    if(x < 0) printf("x < 0\n");
    if(x >= 0) printf("x >= 0\n"); 
    // Заменяемся на else if(x >= 0) для оптимизации
    if(x < 0) 
        printf("x < 0\n");
    else if(x > 0) 
        printf("x > 0\n");
    else
        printf("x == 0\n");    
    return 0;
    
    // Диапазон непересекающихся условий
    if(x < 10) 
        printf("x in [0; 9]\n");
    else if(x < 100) 
        printf("x in [10; 99]\n");
    else if(x < 1000)
        printf("x in [100; 999]\n");
    else
        printf("x > 999\n");
    
    return 0;
}