#include <stdio.h>

int main() {
    const char* names[] = {
        "Анна",
        "Андрей",
        "Степан",
        "Мария",
        "Сергей"};

    // Array of pointers to pointers for female names
    const char** female_names[] = { &names[0], &names[3] };

    // Array of pointers to pointers for male names
    const char** male_names[] = { &names[1], &names[2], &names[4] };

    // Pointer to array of pointers to pointers
    const char ***pp;

    // Print female names using the pointer
    pp = female_names;
    for (int i = 0; i < sizeof(female_names) / sizeof(female_names[0]); i++, pp++) {
        printf("%s ", **pp);
    }
    printf("\n");

    // Reuse pp to print male names
    pp = male_names;
    for (int i = 0; i < sizeof(male_names) / sizeof(male_names[0]); i++, pp++) {
        printf("%s ", **pp);
    }
    printf("\n");

    return 0;
}
