#include <stdio.h>

int main(void)
{
    int var;
    scanf("%d", &var);

    // Объявляем указатель на переменную var
    int *ptr_var = &var;
    // Объявляем указатель типа char и присваиваем ему адрес ptr_var с приведением типа
    char *ptr_ch = (char *)ptr_var;

    // Записываем в ячейку памяти, на которую ссылается ptr_ch, значение 2
    *ptr_ch = 2;

    // Выводим значение переменной var
    printf("%d\n", var);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}