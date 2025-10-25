#include <stdio.h>
 
int main(void)
{
    char item;
 
    if(scanf("%c", &item) != 1) {
        printf("Error input");
        return 0;
    }
 
    switch(item) {
    case 'a': // Переход к нижнему оператору, так как отсутвует выражение
    case 'A': // Дальнейший переход к нижнему оператору (printf)
        printf("Symbol A\n");
        break;
    case 'b':
    case 'B':
        printf("Symbol B\n");
        break;
    case 'c':
    case 'C':
        printf("Symbol C\n");
        break;
    default:
        printf("Incorrect symbol\n");
    }
 
    return 0;
}