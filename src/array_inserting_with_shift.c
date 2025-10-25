#include <stdio.h>
 
#define TOTAL_MARKS                10
 
int main(void)
{
         char marks[TOTAL_MARKS] = {3, 2, 5};
         int insert_indx = 2; // Номер позиции, куда нужно вставить новый элемент
 
         // Сдвигаем элементы вправо, начиная с конца массива
         // и заканчивая позицией, куда нужно вставить новый элемент
         for(int i = TOTAL_MARKS-1; i > insert_indx; --i) {
                   printf("marks[%d] = marks[%d]\n", i, i-1); // Вывод процесса перемещения значений
                   marks[i] = marks[i-1]; // Цикл сдвига элементов вправо
         }
 
         marks[insert_indx] = 4; // Вставляем новый элемент
 
         for(int i = 0; i < TOTAL_MARKS; ++i)
                   printf("%d ", marks[i]);
 
         return 0;
}