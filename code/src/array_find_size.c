#include <stdio.h>
 
#define TOTAL_MARKS                13
 
int main(void)
{
    int marks[TOTAL_MARKS];
 
    size_t bytes_marks = sizeof(marks); // Размер массива в байтах (13 ∙ 4 = 52 байта)
    size_t size_marks = sizeof(marks) / sizeof(marks[0]); // Количество элементов в массиве (52 / 4 = 13)
    // size_t size_marks = sizeof(marks) / sizeof(*marks); // Альтернативный способ получения количества элементов в массиве
    
    printf("%zu\n", bytes_marks); 
    
    // Выводит весь массив   
    for(int i = 0; i < TOTAL_MARKS; ++i) 
        printf("%d ", marks[i]);
 
         return 0;
}