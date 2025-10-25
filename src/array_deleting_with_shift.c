#include <stdio.h>
 
#define TOTAL_MARKS                10
 
int main(void)
{
         char marks[TOTAL_MARKS] = {3, 2, 4, 5, 2, 4};
         int del_indx = 3; // Номер позиции, которую нужно удалить

            // Сдвигаем элементы влево, начиная с позиции, которую нужно удалить
            // и заканчивая предпоследним элементом массива
         for(int i = del_indx; i < TOTAL_MARKS-1; ++i) {
                   printf("marks[%d] = marks[%d]\n", i, i+1); // Вывод процесса перемещения значений
                   marks[i] = marks[i+1]; // Цикл сдвига элементов влево
         }
 
         for(int i = 0; i < TOTAL_MARKS; ++i)
                   printf("%d ", marks[i]);
 
         return 0;
}