#include <stdio.h>
 
int sum_ar(const short* arr, int length) // указатель на массив типа short (элементы нельзя менять)
{
         int res = 0;
         for(int i = 0; i < length; ++i)
                   res += arr[i];
 
         return res;
}
 
int main(void) 
{
         short ar[] = {1, 2, 3, 4, 5};
         int res = sum_ar(ar, sizeof(ar) / sizeof(*ar));
         /*
         Вызов sum_ar(ar, sizeof(ar) / sizeof(*ar))
1. ar — передаётся указатель на первый элемент массива.
2. sizeof(ar) / sizeof(*ar) — вычисление длины массива:
    - sizeof(ar) = размер всего массива в байтах (5 элементов × 2 байта = 10 байт).
    - sizeof(*ar) = размер одного элемента (short = 2 байта).
Итого: 10 / 2 = 5 (длина массива).
         */
         printf("res = %d\n", res);
 
         return 0;
}