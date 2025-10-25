#include <stdio.h>
#include <locale.h>

#define MONTHS_IN_YEAR 12       ///< Количество месяцев в году
#define SEASONS 4               ///< Количество сезонов

int main() {

    // Имена месяцев
    const char *m[MONTHS_IN_YEAR] = {
        "январь", "февраль", "март", "апрель",
        "май", "июнь", "июль", "август",
        "сентябрь", "октябрь", "ноябрь", "декабрь"
    };

    // Указатели на первый месяц каждого сезона
    const char **mp[SEASONS] = {
        m + 11,  // зима начинается с декабря
        m + 2,   // весна с марта
        m + 5,   // лето с июня
        m + 8    // осень с сентября
    };

    // Первый способ вывода
    for (int i = 0; i < SEASONS; i++) {
        printf("%s ", *mp[i]);
    }
    printf("\n");

    // Второй способ вывода с указателем на массив указателей
    const char ***mpp = mp;
    for (int i = 0; i < SEASONS; i++, mpp++) {
        printf("%s ", **mpp);
    }
    printf("\n");

    return 0;
}
