#include <stdio.h>
 
#define SIZE_BUFFER          1024
 
int main(void)
{
         // Корректные объявления
         double f[30];
         char buffer[SIZE_BUFFER];
         int marks[13];
         short ar[8 * 5];
         char bytes[sizeof(double)];
 
         // Некорректные объявления
         int n = 5;
 
         float func[21.5];   // вещественное количество элементов
         int array[n];       // нельзя было до стандарта C99
         int null_ar[0];     // размер должен быть больше нуля

         // Перебор массива
         for(int i = 0; i < SIZE_BUFFER; ++i)
            printf("%d ", buffer[i]);
 
 
         return 0;
}