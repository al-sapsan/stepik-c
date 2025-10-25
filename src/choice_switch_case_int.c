#include <stdio.h>
 
int main(void)
{
    int item;
 
    printf("1. Learning C language\n"
           "2. Learning Python language\n"
           "3. Learning Java language\n"
           "4. Learning C++ language\n"
           "5. Exit\n");
 
    if(scanf("%d", &item) != 1) {
        printf("Error input");
        return 0;
    }
 
    switch(item) {
    case 1:
        printf("Learning C language\n");
        break; // Переход к следующему оператору после switch
    case 2:
        printf("Learning Python language\n");
        return 0; // Завершение программы
    case 3:
        printf("Learning Java language\n");
        return 0; 
    case 4:
        printf("Learning C++ language\n");
        return 0; 
    case 5:
        printf("Exit\n");
        return 0; 
    }
 
    return 0;
}