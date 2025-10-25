#include <stdio.h>

int main(void)
{
    int value;  // Объявляем переменную value
    scanf("%d", &value);  // Считываем целое число из входного потока
    
    // Объявляем массив ar_d типа char с размером, равным размеру int
    char ar_d[sizeof(int)];
    
    // Копируем каждый байт из value в массив ar_d
    for (size_t i = 0; i < sizeof(int); ++i) {
        // Приводим адрес value к указателю на char, чтобы получить доступ к отдельным байтам
        // Копируем i-й байт value в i-й элемент массива ar_d
        ar_d[i] = ((char*)&value)[i];
    }
    
    // Выводим значения байтов в десятичном виде
    for (size_t i = 0; i < sizeof(int); ++i) {
       
        printf("%d ", (unsigned char)ar_d[i]);
    }
    return 0;
}