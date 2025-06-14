#include <stdio.h>
#include <stdlib.h>

#define N 5

int main() {
    int arr[N][N];
    int seed;
    scanf("%d", &seed);
    srand(seed);

    // Fill and print the array
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = rand() % 11 - 5; // -5 to 5 inclusive
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
 
    // Sum elements in the right triangle between diagonals (including diagonals)
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j >= i && j >= N - 1 - i) {
                sum += arr[i][j];
            }
        }
    }
    printf("%d\n", sum);

    return 0;
}