#include <stdio.h>
 
int main(void) 
{
         char bf[10];
 
         int max_len = sizeof(bf), i = 0;
         char *ptr = bf, ch;
        // считываем символы с клавиатуры до тех пор, пока не встретим символ конца строки или конец файла 
         while((ch = getchar()) != '\n' && ch != EOF && i < max_len-1) 
                   ptr[i++] = ch;
 
         ptr[i] = '\0'; // в конце мы прописываем символ конца строки ‘\0’, чтобы строка в массиве bf была корректной
 
         puts(bf);
                   
         return 0;
}