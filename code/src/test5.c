#include <stdio.h>

int main(void)
{
    int digit;
    if (scanf("%d", &digit) != 1 || digit < 10 || digit > 15) {
        printf("Неверное число\n");
        return 0;
    }

    switch (digit) {
        case 10:
            printf("десять\n");
            break;
        case 11:
            printf("одиннадцать\n");
            break;
        case 12:
            printf("двенадцать\n");
            break;
        case 13:
            printf("тринадцать\n");
            break;
        case 14:
            printf("четырнадцать\n");
            break;
        case 15:
            printf("пятнадцать\n");
            break;
        default:
            printf("Неверное число\n");
            return 0;
    }