#include <stdio.h>

/**
 * @brief Simulates the process of chasing flies out of a room.
 *
 * The user enters n (initial number of flies) and k (minutes passed).
 * Each minute, 1 fly is chased out. Every 5 minutes, 1 new fly enters.
 * When the number of flies becomes <= 10% of the initial, 2 flies are chased out per minute.
 * The program outputs: flies left after k minutes, and the minute when Ivan Ivanovich is alone.
 *
 * @return 0 on successful completion
 */
int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    int flies = n;
    int alone_minute = 0;
    int initial = n;
    int minute = 1;

    // Simulate until all flies are gone to find alone_minute
    while (flies > 0) {
        int out = (flies <= initial / 10) ? 2 : 1;
        flies -= out;
        if (flies < 0) flies = 0;
        if (minute % 5 == 0) flies++;
        if (flies == 0 && alone_minute == 0) alone_minute = minute;
        minute++;
    }

    // Simulate again to find flies after k minutes
    flies = n;
    for (int i = 1; i <= k; i++) {
        int out = (flies <= initial / 10) ? 2 : 1;
        flies -= out;
        if (flies < 0) flies = 0;
        if (i % 5 == 0) flies++;
    }

    printf("%d %d\n", flies, alone_minute);
    return 0;
}