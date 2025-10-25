#include <stdio.h>
#include <string.h>
 
int main(void) 
{
         char str[] = "Abrakadabra";
         char *ptr = strstr(str, "ra"); // прописываем в двойных кавычках
         
         printf("str = %p\nptr = %p\n", str, ptr);
         if(ptr != NULL)
                   printf("ptr: %s\n", ptr);
 
         return 0;
}