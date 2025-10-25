#include <stdio.h>
#include <stdbool.h>

#define MAX_CITIES 6
#define MAX_NAME_LEN 20

int main(void)
{
    char data[MAX_CITIES][MAX_NAME_LEN + 1] = {0}; // +1 для терминатора
    unsigned char city_count = 0;
    char current_char;
    unsigned char char_pos = 0;
    bool reading_city = false;

    // Чтение городов посимвольно
    while (city_count < MAX_CITIES && (current_char = getchar()) != '\n' && current_char != EOF) {
        if (current_char != ' ') {
            if (char_pos < MAX_NAME_LEN) {
                data[city_count][char_pos++] = current_char;
                reading_city = true;
            }
            // Если превышена длина названия - пропускаем остальные символы
        }
        else if (reading_city) {
            data[city_count][char_pos] = '\0';
            city_count++;
            char_pos = 0;
            reading_city = false;
        }
    }

    // Завершаем последний город, если он был в процессе чтения
    if (reading_city && city_count < MAX_CITIES) {
        data[city_count][char_pos] = '\0';
        city_count++;
    }

    // Вывод в обратном порядке
    for (int i = city_count - 1; i >= 0; i--) {
        printf("%s", data[i]);
        if (i > 0) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}