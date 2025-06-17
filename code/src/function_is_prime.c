#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Checks if a number is prime.
 * 
 * @param x Integer to check
 * @return true if x is prime, false otherwise
 */
bool simple(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main() {
    int x;
    scanf("%d", &x);
    if (simple(x)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}