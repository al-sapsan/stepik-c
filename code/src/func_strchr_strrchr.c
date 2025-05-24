#include <stdio.h>
#include <string.h>
 
int main(void) 
{
         char str[] = "Abrakadabra";
         // ищет слева направо
         char *ptr = strchr(str, 'a'); // char *ptr = strrchr(str, 'a'); - справа налево
         
         printf("str = %p\nptr = %p\n", str, ptr);
         if(ptr != NULL) // если не равен NULL - нашли символ
                   printf("*ptr = %c\n", *ptr);
 
         return 0;
}