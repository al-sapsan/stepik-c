#include <stdio.h>

int get_volume(int h, int w, int d); // прототип функции

int main(void)
{
    int height, width, depth;
    scanf("%d %d %d", &height, &width, &depth);
    int volume = get_volume(height, width, depth);
    printf("%d\n", volume);
    return 0;
}

int get_volume(int h, int w, int d) {
    return h * w * d;
}