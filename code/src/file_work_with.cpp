/**
 * @file file_copy.cpp
 * @brief Копирование содержимого одного файла в другой
 * @version 1.0
 * @date 2025-07-18
 */

#include <iostream>
#include <cstdio>
#include <locale.h>

/*** Main Function ***/

int main()
{

    FILE *input = nullptr;
    FILE *output = nullptr;

    // Открытие файла для чтения
    if (fopen_s(&input, "mydata.txt", "r") != 0)
    {
        std::cout << "Ошибка открытия файла для ввода!\n";
        system("pause");
        return 1;
    }

    // Открытие файла для записи
    if (fopen_s(&output, "myresult.txt", "w") != 0)
    {
        std::cout << "Ошибка открытия файла для вывода!\n";
        fclose(input); // обязательно закрыть входной файл
        system("pause");
        return 1;
    }

    std::cout << "Копирую...\n";
    /*
    int getc(FILE *fp); //читает очередной символ из файла fp
    //и возвращает его либо EOF в случае ошибки или конца файла
    int putc(int c, FILE *fp); //записывает символ c в файл fp.
    //Возвращает записанный символ или EOF в случае ошибки
    */
    int ch = getc(input);
    while (ch != EOF)
    {
        putc(ch, output);
        ch = getc(input);
    }
    /* Kопирование построчно до первого пробела или
    служебного символа
    Для форматированного файлового ввода-вывода можно пользоваться
функциями fscanf_s() и fprintf(). Они аналогичны функциям ввода
scanf_s() и вывода printf(), и отличаются лишь наличием дополнительного
первого параметра, который должен быть указателем на соответствующий файл:
int fscanf_s(FILE *fp, char *format, …) //выдает EOF при достижении конца файла
int fprintf(FILE *fp, char *format, …)
*/
    const int MAX = 128;
    char str[MAX];
    while (fscanf_s(input, "%s", str, MAX) != EOF)
    {
        fprintf(output, "%s ", str);
    }
    /* посимвольное копирование
    Для посимвольного копирования функции fgets() и fputs()
char *fgets(char *str, int n, FILE *fp); // считывает строку до символа '\n' включительно
//(строка может содержать пробелы);
// возвращает NULL, если произошла ошибка или достигнут конец файла
// в случае удачного ввода строки она возвращает ее адрес в памяти.
int fputs(const char * str, FILE *fp );//выводит строку в файл
//в случае ошибки возвращает EOF
Здесь
fp – указатель на файл, с которым будет обмен данными;
str – указатель на начало строки, предназначенной для размещения вводимых данных (или указатель на выводимую строку) ;
n – целое число, определяющее максимальный размер входной строки;
*/
    const int MAX = 128;
    char str[MAX];
    while (fgets(str, MAX, input) != NULL)
    {
        fputs(str, output);
    }

    std::cout << "Копирование успешно завершено\n";

    // Закрытие файлов
    if (fclose(input) != 0)
    {
        std::cout << "Ошибка закрытия файла ввода\n";
    }

    if (fclose(output) != 0)
    {
        std::cout << "Ошибка закрытия файла вывода\n";
    }

    return 0;
}
