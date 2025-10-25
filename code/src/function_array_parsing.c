#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_data_csv(double arr[], int max_len, const char *str) {
    int count = 0;
    const char *p = strstr(str, "csv:");
    if (!p) return 0;
    p += 4; // пропускаем "csv:"
    
    // Пропускаем пробелы после "csv:"
    while (*p == ' ') p++;
    
    // Извлекаем числа пока не конец строки или не заполним массив
    while (*p != '\0' && count < max_len) {
        char *endptr;
        double num = strtod(p, &endptr);
        
        // Если преобразование не удалось, выходим
        if (p == endptr) break;
        
        arr[count++] = num;
        p = endptr;
        
        // Пропускаем разделители (; и пробелы)
        while (*p == ';' || *p == ' ') p++;
    }
    
    return count;
}

int main(void) {
    char str[100] = {0};
    fgets(str, sizeof(str), stdin);
    
    // Удаляем символ новой строки
    char *ptr_n = strchr(str, '\n');
    if (ptr_n) *ptr_n = '\0';
    
    double arr[20];
    int n = get_data_csv(arr, 20, str);
    
    // Выводим числа с точностью до сотых
    for (int i = 0; i < n; ++i) {
        printf("%.2f", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    
    return 0;
}
/* Задание
Функция get_data_csv должна из переданной ей строки выделять и 
сохранять в переданный массив вещественные числа, которые записаны 
в формате:

"csv: <число 1>; <число 2>; ...; <число N>"

Например:

"csv: 0.56; -65.43; 0.1; 11.0"

Необходимо выделенные числа сохранять в переданном массиве в количестве 
не превышающем длину массива 20 элементов. Функция get_data_csv должна 
возвращать количество (целое число) записанных в массив вещественных 
чисел.
В функции main вызвать функцию get_data_csv для строки str и вывести 
в консоль выделенные в массив вещественные числа в одну строчку через 
пробел с точностью до сотых.
*/