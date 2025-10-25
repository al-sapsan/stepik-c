#include <stdio.h>

int prod_ar(int arr[], int len); // прототип функции

int main(void)
{
    int arr[20];
    int n = 0;
    // читает из входного потока в массив несколько целочисленных значений 
    // (не менее одного и не более 20)
    while (n < 20 && scanf("%d", &arr[n]) == 1)
        n++;
    int prod = prod_ar(arr, n);
    printf("%d\n", prod);
    return 0;
}

int prod_ar(int arr[], int len) {
    int prod = 1;
    for (int i = 0; i < len; ++i)
        prod *= arr[i];
    return prod;
}