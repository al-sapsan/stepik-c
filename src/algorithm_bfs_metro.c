/********************************************************************
 * @file    breadth_first_search.c
 * @brief   Модель метро: станции и связи, variadic set_station_links
 * @version 2.1
 * @date
 ********************************************************************/

/*** Includes ***/
#include <stdio.h>
#include <stdarg.h>

/*** Typedefs ***/
enum
{
    name_length = 50,
    total_links = 50,
    max_path_station = 100
};

typedef struct tag_station
{
    char name[name_length];                 // название станции метро
    struct tag_station *links[total_links]; // связи станции метро с другими соседними станциями
    short count_links;                      // общее количество связей
    char fl_reserved;                       // зарезервированная переменная (для алгоритма поиска маршрута)
} STATION;

/*** Function Prototypes ***/
/**
 * @brief  Устанавливает связи между станциями метро
 * @param[in,out] st Указатель на станцию
 * @param[in] count_links Количество связей
 * @param[in] ... Перечень указателей на станции
 */
void set_station_links(STATION *st, int count_links, ...);
/**
 * @brief  Находит кратчайший маршрут между двумя станциями метро (BFS)
 * @param[in] from Начальная станция
 * @param[in] to Конечная станция
 * @param[out] path Массив указателей на станции маршрута
 * @param[out] count_st Указатель на количество станций в маршруте
 */
void find_path(STATION *from, STATION *to, STATION *path[], int *count_st);

/*** Main Function ***/
int main(void)
{
    STATION st[10] = {
        {"St #1", .count_links = 0, .fl_reserved = 0},
        {"St #2", .count_links = 0, .fl_reserved = 0},
        {"St #3", .count_links = 0, .fl_reserved = 0},
        {"St #4", .count_links = 0, .fl_reserved = 0},
        {"St #5", .count_links = 0, .fl_reserved = 0},
        {"St #6", .count_links = 0, .fl_reserved = 0},
        {"St #7", .count_links = 0, .fl_reserved = 0},
        {"St #8", .count_links = 0, .fl_reserved = 0},
        {"St #9", .count_links = 0, .fl_reserved = 0},
        {"St #10", .count_links = 0, .fl_reserved = 0},
    };

    set_station_links(&st[0], 2, &st[1], &st[2]);                 // 1 -> 2, 3
    set_station_links(&st[1], 3, &st[0], &st[3], &st[4]);         // 2 -> 1, 4, 5
    set_station_links(&st[2], 2, &st[0], &st[5]);                 // 3 -> 1, 6
    set_station_links(&st[3], 2, &st[1], &st[5]);                 // 4 -> 2, 6
    set_station_links(&st[4], 2, &st[1], &st[7]);                 // 5 -> 2, 8
    set_station_links(&st[5], 4, &st[2], &st[3], &st[6], &st[8]); // 6 -> 3, 4, 7, 9
    set_station_links(&st[6], 2, &st[5], &st[8]);                 // 7 -> 6, 9
    set_station_links(&st[7], 2, &st[4], &st[8]);                 // 8 -> 5, 9
    set_station_links(&st[8], 4, &st[5], &st[6], &st[7], &st[9]); // 9 -> 6, 7, 8, 10
    set_station_links(&st[9], 1, &st[8]);                         // 10 -> 9

    __ASSERT_TESTS__ // макроопределение для тестирования
        return 0;
}

void set_station_links(STATION *st, int count_links, ...)
{
    va_list args;
    va_start(args, count_links);
    st->count_links = (short)count_links;
    for (int i = 0; i < count_links; i++)
    {
        st->links[i] = va_arg(args, STATION *);
    }
    va_end(args);
}

void find_path(STATION *from, STATION *to, STATION *path[], int *count_st)
{
    // Поскольку stations не передается, будем считать, что все станции доступны через from
    STATION *queue[max_path_station];
    STATION *prev[100] = {0};
    int visited[100] = {0};
    int front = 0, rear = 0;

    // Начинаем BFS с начальной станции
    queue[rear++] = from;
    visited[0] = 1; // Помечаем начальную станцию как посещенную

    // Основной цикл BFS
    while (front < rear)
    {
        STATION *cur = queue[front++];

        // Если достигли конечной станции - выходим
        if (cur == to)
            break;

        // Перебираем все соседние станции
        for (int i = 0; i < cur->count_links; ++i)
        {
            STATION *next = cur->links[i];

            // Проверяем, не посещали ли мы эту станцию
            int visited_flag = 0;
            for (int j = 0; j < rear; j++)
            {
                if (queue[j] == next)
                {
                    visited_flag = 1;
                    break;
                }
            }

            if (!visited_flag)
            {
                queue[rear++] = next;
                prev[next - from] = cur; // Сохраняем предыдущую станцию
            }
        }
    }

    // Восстановление пути (обратный проход от конечной станции)
    int path_len = 0;
    STATION *cur = to;
    while (cur != NULL && cur != from)
    {
        path[path_len++] = cur;
        cur = prev[cur - from]; // Переходим к предыдущей станции
    }

    // Добавляем начальную станцию, если путь найден
    if (cur == from)
    {
        path[path_len++] = from;
    }

    // Разворачиваем путь, так как собирали его с конца
    for (int i = 0; i < path_len / 2; ++i)
    {
        STATION *tmp = path[i];
        path[i] = path[path_len - 1 - i];
        path[path_len - 1 - i] = tmp;
    }

    // Возвращаем длину найденного пути
    *count_st = path_len;
}