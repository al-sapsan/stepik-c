/* Вариант без использования функции strcpy
#include <stdio.h>
 
int main(void) 
{
         char source[100] = "Source string";
         char destination[10];
 
         const char* src = source;
         char* dst = destination;
         int max_len_copy = sizeof(destination);
 
         while(*src != '\0' && max_len_copy-- > 1)
                   *dst++ = *src++;
         *dst = '\0';
 
         puts(destination);
         
         return 0;
}
*/
#include <stdio.h>
#include <string.h>
 
int main(void) 
{
         char s_1[100] = "Source string";
         char d_1[10], d_2[20];
 
         int max_len = sizeof(d_1)-1; // Определяем максимальную длину для копирования
         strncpy(d_1, s_1, max_len);
         d_1[max_len] = 0; // Добавляем нулевой символ в конец строки
         strncpy(d_2, "Balakirev", 5);
         d_2[5] = 0;
 
         puts(d_1);
         puts(d_2);
 
         return 0;
}