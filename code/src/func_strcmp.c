/* Без использования функции strcmp 
#include <stdio.h>
 
int main(void) 
{
         char s1[12] = "Hello";
         char s2[10] = "Hello";
 
         const char *str1 = s1;
         const char *str2 = s2;
 
         int i = 0;
         for(; str1[i] != '\0' && str2[i] != 0; ++i)
                   if(str1[i] != str2[i]) {
                            puts("Strings are not equal!");
                            return 0;
                   }
 
         if(str1[i] != str2[i]) {
                   puts("String lengths are not equal!");
                   return 0;
         }
 
         puts("Strings are equal!");
 
         return 0;
}
*/
#include <stdio.h>
#include <string.h>
 
int main(void) 
{
    char s1[12] = "Hello";
    char s2[10] = "Hello";
 
    int res = strcmp(s1, s2);
    if(res == 0)
        puts("Strings are equal!");
    else
        puts("Strings are not equal!");
/*
if(strcmp(s1, s2) == 0)
         puts("Strings are equal!");
else
         puts("Strings are not equal!");
*/ 
 
    return 0;
}