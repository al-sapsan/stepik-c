/* Вариант без использования функции strlen(): 
#include <stdio.h>
 
int main(void) 
{
    char str[100] = "Length of the string";
 
    const char *buf = str;
    size_t length = 0;
    while(*buf++)// Чтение символа из строки пока не достигнут нулевой символ
        length++;
 
    printf("length = %zu\n", length);
 
    return 0;
}
*/
#include <stdio.h>
#include <string.h>

int main(void) 
{
    char str[100] = "Length of the string";
    size_t length = strlen(str); // Использование функции strlen() для вычисления длины строки
    printf("length = %zu\n", length);
 
    return 0;
}