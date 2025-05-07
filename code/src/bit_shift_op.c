#include <stdio.h>
/*Смещение бит вправо: number >> n тоже что и number // (2 ** n)
Смещение бит влево: number << n тоже что и number * (2 ** n) */

int main(void)
{
    unsigned char x = 40;                   // 00101000
    printf("x = %d\n", x); 
 
    x = x >> 1;                       // 00010100 (число 20)
    printf("x = %d\n", x);
 
    x = x >> 2;                       // 00000101 (число 5)
    printf("x = %d\n", x); 
 
    x = x >> 1;                       // 00000010 (число 2)
    printf("x = %d\n", x);
 
    x = x >> 1;                       // 00000001 (число 1)
    printf("x = %d\n", x);
 
    x = x << 1;                       // 00000010 (число 2)
    printf("x = %d\n", x);
 
    x = x << 2;                       // 00001000 (число 8)
    printf("x = %d\n", x);
 
    return 0;
}